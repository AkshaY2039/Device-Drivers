#!/usr/bin/env bash

unset baseCurr
unset xchngToCurr
unset httpGetTool
currCodes=(AUD BGN BRL CAD
	 CHF CNY CZK DKK
	 EUR GBP HKD HRK
	 HUF IDR ILS INR
	 JPY KRW MXN MYR
	 NOK NZD PHP PLN
	 RON RUB SEK SGD
	 THB TRY USD ZAR)

## Determining http get tool the system has installed and returns an error if there isnt one
gethttpGetTool()
{
	if command -v curl &>/dev/null; then
		httpGetTool="curl"
	elif command -v wget &>/dev/null; then
		httpGetTool="wget"
	elif command -v http &>/dev/null; then
		httpGetTool="httpie"
	elif command -v fetch &>/dev/null; then
		httpGetTool="fetch"
	else
		echo "Error: This tool reqires either curl, wget, httpie or fetch to be installed." >&2
		return 1
	fi
}

## Allows to call the users configured client without if statements everywhere
httpGet()
{
	case "$httpGetTool" in
		curl)	curl -A curl -s "$@" ;;
		wget)	wget -qO- "$@" ;;
		httpie) http -b GET "$@" ;;
		fetch) fetch -q "$@" ;;
	esac
}

chkCurrValid()
{
	if [[ "${currCodes[*]}" == *"$(echo "${@}" | tr -d '[:space:]')"* ]]; then
		echo "0"
	else
		echo "1"
	fi
}

## Grabs the base currency from the user and validates it with all the possible currency
## types available on the API and guides user through input (doesnt take in arguments)
getBaseCurr()
{
	echo -n "Input Base Currency: "
	read -r baseCurr
	baseCurr=$(echo $baseCurr | tr /a-z/ /A-Z/)
	if [[ $(chkCurrValid $baseCurr) == "1" ]]; then
		unset baseCurr
		echo "Invalid base currency"
		getBaseCurr
	fi
}

## Checks base currency from the user and validates it with all the possible currency
## types available on the API (requires argument)
chkBaseCurr()
{
	baseCurr=$1
	baseCurr=$(echo $baseCurr | tr /a-z/ /A-Z/)
	if [[ $(chkCurrValid $baseCurr) == "1" ]]; then
		unset baseCurr
		echo "Invalid base currency"
		exit 1
	fi
}

## Grabs the exchange to currency from the user and validates it with all the possible currency
## types available on the API and guides user through input (doesnt take in arguments)
getXchngToCurr()
{
	echo -n "What currency to exchange to: "
	read -r xchngToCurr
	xchngToCurr=$(echo $xchngToCurr | tr /a-z/ /A-Z/)
	if [[ $(chkCurrValid $xchngToCurr) == "1" ]]; then
		echo "Invalid exchange currency"
		unset xchngToCurr
		getXchngToCurr
	fi
}

## Grabs the exchange to currency from the user and validates it with all the possible currency
## types available on the API (requires arguments)
chkXchngToCurr()
{
	xchngToCurr=$1
	xchngToCurr=$(echo $xchngToCurr | tr /a-z/ /A-Z/)
	if [[ $(chkCurrValid $xchngToCurr) == "1" ]]; then
		echo "Invalid exchange currency"
		unset xchngToCurr
		exit 1
	fi
}

## Get the amount that will be exchanged and validate that the user has entered a number (decimals are allowed)
## doesnt take in argument, it guides user through input
getAmount()
{
	echo -n "Amount to be exchanged: "
	read -r amount
	if [[ ! "$amount" =~ ^[0-9]+(\.[0-9]+)?$ ]]
	then
		echo "The amount has to be a number"
		unset amount
		getAmount
	fi
}

## Get the amount that will be exchanged
## validate that the user has entered a number (decimals are allowed and requires argument)
chkAmount()
{
	amount=$1
	if [[ ! "$amount" =~ ^[0-9]+(\.[0-9]+)?$ ]]
	then
		echo "The amount has to be a number"
		unset amount
		exit 1
	fi
}

chkInternet()
{
	httpGet github.com > /dev/null 2>&1 || { echo "Error: no active internet connection" >&2; return 1; }
	# query github with a get request, redirect stdout to /dev/null and stderr to stdout (File Descriptor 1)
	# if that fails send set Error message to stderr (File descriptor 2)
}

## Grabs the exchange rate and does the math for converting the currency
cnvtCurr()
{
	xchngRate=$(httpGet "https://api.exchangeratesapi.io/latest?base=$baseCurr" | grep -Eo "$xchngToCurr\":[0-9.]*" | grep -Eo "[0-9.]*") > /dev/null
	if ! command -v bc &>/dev/null; then
		oldRate=$xchngRate
		xchngRate=$(echo $xchngRate | grep -Eo "^[0-9.]*" )
		amount=$(echo $amount | grep -Eo "^[0-9]*" )
		xchngAmount=$(( $xchngRate * $amount ))
		xchngRate=$oldRate
	else
		xchngAmount=$( echo "$xchngRate * $amount" | bc )
	fi

	cat <<EOF
=========================
| $baseCurr to $xchngToCurr
| Rate: $xchngRate
| $baseCurr: $amount
| $xchngToCurr: $xchngAmount
=========================
EOF
}

usage()
{
	cat <<EOF
	Currency
	Description: A realtime currency converter.
		With no flags it will guide you through the currency exchange
	Usage: currency or currency [flag] or currency [base] [xchngToCurr] [amount]
		-h	Show the help
	Supported Currencies:
	_________________________
	| AUD | BGN | BRL | CAD |
	| CHF | CNY | CZK | DKK |
	| EUR | GBP | HKD | HRK |
	| HUF | IDR | ILS | INR |
	| JPY | KRW | MXN | MYR |
	| NOK | NZD | PHP | PLN |
	| RON | RUB | SEK | SGD |
	| THB | TRY | USD | ZAR |
	_________________________
	Examples:
			currency EUR USD 12.35
EOF
}

gethttpGetTool || exit 1


while getopts "uvh" opt; do
	case "$opt" in
		\?) echo "Invalid option: -$OPTARG" >&2
				exit 1
				;;
		h)	usage
				exit 0
				;;
		:)	echo "Option -$OPTARG requires an argument." >&2
				exit 1
				;;
	esac
done

if [[ $# == 0 ]]; then
	chkInternet || exit 1 # check if we have a valid internet connection if this isnt true the rest of the script will not work so stop here
	getBaseCurr # get base currency
	getXchngToCurr # get exchange to currency
	getAmount # get the amount to be converted
	cnvtCurr # grab the exhange rate and perform the conversion
	exit 0
elif [[ $# == "1" ]]; then
	if [[ $1 == "help" ]]; then
		usage
	else
		echo "Not a valid argument"
		usage
		exit 1
	fi
elif [[ $# == "2" ]]; then
	echo "Not a valid argument"
	usage
	exit 1
elif [[ $# == "3" ]]; then
	chkInternet || exit 1 # check if we have a valid internet connection if this isnt true the rest of the script will not work so stop here
	chkBaseCurr $1
	chkXchngToCurr $2
	chkAmount $3
	cnvtCurr
	exit 0
else
	echo "Error: too many arguments."
fi