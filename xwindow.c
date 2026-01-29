#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

#include <stdio.h>


struct Resolution {

	int screenWidth;
	int screenHeight;
};



struct Resolution getResolution() {
  Display *dpy = XOpenDisplay(NULL);
    if (!dpy) {
        fprintf(stderr, "Failed to open display\n");
    }

    Window root = DefaultRootWindow(dpy);

    int nmonitors = 0;
    XRRMonitorInfo *monitors =
        XRRGetMonitors(dpy, root, True, &nmonitors);

    if (!monitors || nmonitors == 0) {
        fprintf(stderr, "No monitors found\n");
    }

    int index = 0; 
    if (index >= nmonitors) {
        fprintf(stderr, "Monitor index out of range\n");
    }

    XRRMonitorInfo m = monitors[index];

    
    XRRFreeMonitors(monitors);
    XCloseDisplay(dpy);
    struct Resolution win1 = {m.width, m.height};

    return win1;

}
