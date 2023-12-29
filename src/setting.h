#ifndef SETTINGS
#define SETTINGS
// sets the vertical length of the paddle 
#define PADDLE_LEN 5

// sets the paddle icon (string)
#define PADDLE_ICON "█"

// step to be moved by ai in a ai cycle
#define PADDLE_UPDATE_STEP 0.5

// define the delay between each ai update (in microseconds)
#define PADDLE_UPDATE_DELAY 5000

// how long to hold the notification (in seconds)
#define NOTIFICATION_DELAY 2

// id the program should be compiled for debug
#define DEBUG 1

// ball's initial valocity
#define INITIAL_XVEL -0.150
#define INITIAL_YVEL 0.000

// ball's refresh interval (in microseconds)
#define BALL_REFRESH_INTERVAL 7500
#endif
