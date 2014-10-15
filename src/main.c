#include <pebble.h>

Window *my_window;
TextLayer *text_layer;

void handle_init(void) {
  my_window = window_create();
  window_stack_push(my_window, true);

  Layer *window_layer = window_get_root_layer(my_window);
  GRect bounds = layer_get_bounds(window_layer);
 
  text_layer = text_layer_create(bounds);

  // set the text of our newly created textlayer
  text_layer_set_text(text_layer,"Hello Dreamforce!");
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

void handle_deinit(void) {
  // destroy the textlayer we created
  text_layer_destroy(text_layer);
  // destroy the window we created
  window_destroy(my_window);
}

// the main function that is started when the app starts
int main(void) {
  // call the handle_init function to setup the display
  handle_init();
  // start the event loop that keeps the application running and receiving events from the OS
  app_event_loop();
  // call the handle_deinit after the event loop has stopped, so we can clean up
  handle_deinit();
}
