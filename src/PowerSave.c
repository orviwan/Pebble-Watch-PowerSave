#include "pebble_os.h"
#include "pebble_app.h"

#define MY_UUID { 0xC3, 0xE7, 0xC8, 0xCA, 0xB1, 0xE0, 0x43, 0xAB, 0xAC, 0x1B, 0xF5, 0x17, 0xC6, 0x83, 0xEC, 0xED }
PBL_APP_INFO(MY_UUID,
             "PowerSave", "orviwan",
             1, 0, /* App version */
             RESOURCE_ID_IMAGE_MENU_ICON,
             APP_INFO_WATCH_FACE);

Window window;
BmpContainer bmp_cont;

void handle_init(AppContextRef ctx) {
  (void)ctx;
  window_init(&window, "PowerSave");
  window_stack_push(&window, false /* NOT Animated */);
  resource_init_current_app(&APP_RESOURCES);
  bmp_init_container(RESOURCE_ID_IMAGE, &bmp_cont);
  layer_add_child(&window.layer, &bmp_cont.layer.layer);
}
void handle_deinit(AppContextRef ctx) {
  (void)ctx;
  bmp_deinit_container(&bmp_cont);
}

void pbl_main(void *params) {
  PebbleAppHandlers handlers = {
    .init_handler = &handle_init,
    .deinit_handler = &handle_deinit
  };
  app_event_loop(params, &handlers);
}
