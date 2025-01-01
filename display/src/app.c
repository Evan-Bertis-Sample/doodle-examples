#include <doodle/core/doodle_app.h>
#include <doodle/core/modules/doodle_renderer.h>
#include <doodle/core/util/doodle_math.h>
#include <doodle/core/doodle_debug.h>
#include <stdio.h>
#include <stdlib.h>

static void display_setup(doodle_app_t *app) {
    DOODLE_APP_LOG("setup\n");
    doodle_module_renderer_t *renderer = (doodle_module_renderer_t *)doodle_app_get_module(app, DOODLE_MODULE_TYPE_RENDERER);
    if (renderer) {
        doodle_color_t color = (doodle_color_t){.value = 0xFF0000FF};
        renderer->clear(renderer, color);
    }
}

static void display_loop(doodle_app_t *app) {
    // DOODLE_APP_LOG("loop\n");
    doodle_module_renderer_t *renderer = (doodle_module_renderer_t *)doodle_app_get_module(app, DOODLE_MODULE_TYPE_RENDERER);
    if (renderer) {
        doodle_color_t color = (doodle_color_t){.value = 0x00FF00FF};
        renderer->draw_pixel(renderer, 320, 240, color);
    }
}

static void display_teardown(doodle_app_t *app) {
    DOODLE_APP_LOG("teardown\n");
}

doodle_app_desc_t doodle_main(int32_t argc, char *argv[]) {
    doodle_app_desc_t desc = {
        .name = "blank",
        .module_configs = {0},
        .setup = display_setup,
        .loop = display_loop,
        .teardown = display_teardown,
    };

    doodle_module_renderer_config_t *renderer_config = malloc(sizeof(doodle_module_renderer_config_t));
    *renderer_config = (doodle_module_renderer_config_t){
        .width = 640,
        .height = 480,
    };
    DOODLE_APP_LOG("Renderer config address: %p\n", renderer_config);
    desc.module_configs[DOODLE_MODULE_TYPE_RENDERER] = renderer_config;

    DOODLE_APP_LOG("main end\n");
    return desc;
}