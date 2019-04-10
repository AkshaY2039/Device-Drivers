#include <stdio.h>
#include <X11/Xlib.h>

int main()
{
	Display *d;
	Window inwin;			/* root window the pointer is in */
	Window inchildwin; /* child win the pointer is in(terminal window) */
	int rootx, rooty,old_cx=0,old_cy=0; /* relative to the "root" window;	*/
	int childx, childy;	/* relative to terminal */
	Atom atom_type_prop; /*	*/
	int actual_format;	 /* should be 32 after the call */
	unsigned int mask;	 /* status of the buttons */
	unsigned long n_items, bytes_after_ret;
	Window *props; /* since we are interested just in the first value, which is
				a Window id */
 
	/* default DISPLAY */
	d = XOpenDisplay(NULL); 
 
	/* ask for active window (no error check); the client must be freedesktop
		 compliant */
	(void)XGetWindowProperty(d, DefaultRootWindow(d),
				 XInternAtom(d, "_NET_ACTIVE_WINDOW", True),
				 0, 1, False, AnyPropertyType,
				 &atom_type_prop, &actual_format,
				 &n_items, &bytes_after_ret, (unsigned char**)&props);
 
 while(1)
 {
	XQueryPointer(d, props[0], &inwin,	&inchildwin,
		&rootx, &rooty, &childx, &childy, &mask);
	if(rootx!=old_cx || rooty!=old_cy)
		printf("relative to active window: %d,%d\n", rootx, rooty);
	old_cx=rootx;
	old_cy=rooty;
 }
 
	XFree(props);					 /* free mem */
	(void)XCloseDisplay(d); /* and close the display */
	return 0;
}
/*
int XGetWindowProperty(display, w, property, long_offset, long_length, delete, req_type, 
												actual_type_return, actual_format_return, nitems_return, bytes_after_return, 
												prop_return)
			Display *display;
			Window w;
			Atom property;
			long long_offset, long_length;
			Bool delete;
			Atom req_type; 
			Atom *actual_type_return;
			int *actual_format_return;
			unsigned long *nitems_return;
			unsigned long *bytes_after_return;
			unsigned char **prop_return;

Arguments
display :Specifies the connection to the X server.
w: Specifies the window whose property you want to obtain.
property : Specifies the property name.
long_offset: Specifies the offset in the specified property (in 32-bit quantities) where the data is to be retrieved.
long_length: Specifies the length in 32-bit multiples of the data to be retrieved.
delete : Specifies a Boolean value that determines whether the property is deleted.
req_type : Specifies the atom identifier associated with the property type or AnyPropertyType.
actual_type_return : Returns the atom identifier that defines the actual type of the property.
actual_format_return : Returns the actual format of the property.
nitems_return :Returns the actual number of 8-bit, 16-bit, or 32-bit items stored in the prop_return data.
bytes_after_return : Returns the number of bytes remaining to be read in the property if a partial read was performed.
prop_return: Returns the data in the specified format.



Bool XQueryPointer(display, w, root_return, child_return, root_x_return, root_y_return, 
										 win_x_return, win_y_return, mask_return)
			Display *display;
			Window w;
			Window *root_return, *child_return;
			int *root_x_return, *root_y_return;
			int *win_x_return, *win_y_return;
			unsigned int *mask_return;

Arguments
display Specifies the connection to the X server.
w Specifies the window.
root_return Returns the root window that the pointer is in.
child_return	Returns the child window that the pointer is located in, if any.
root_x_return
root_y_return Return the pointer coordinates relative to the root window's origin.
win_x_return
win_y_return	Return the pointer coordinates relative to the specified window.
mask_return Returns the current state of the modifier keys and pointer buttons.

*/