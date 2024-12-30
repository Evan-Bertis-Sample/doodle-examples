#include <doodle/core/doodle_app.h>
#include <doodle/core/modules/doodle_renderer.h>
#include <doodle/core/util/doodle_math.h>
#include <stdio.h>
#include <stdlib.h>

static void display_setup(doodle_app_t *app) {
    printf("setup\n");
    doodle_module_renderer_t *renderer = (doodle_module_renderer_t *)doodle_app_get_module(app, DOODLE_MODULE_TYPE_RENDERER);
    if (renderer) {
        doodle_color_t color = (doodle_color_t){.value = 0xFF0000FF};
        renderer->clear(renderer, color);
    }
}

static void display_loop(doodle_app_t *app) {
    printf("loop\n");
    doodle_module_renderer_t *renderer = (doodle_module_renderer_t *)doodle_app_get_module(app, DOODLE_MODULE_TYPE_RENDERER);
    if (renderer) {
        doodle_color_t color = (doodle_color_t){.value = 0x00FF00FF};
        renderer->draw_pixel(renderer, 320, 240, color);
    }
}

static void display_teardown(doodle_app_t *app) {
    printf("teardown\n");
}

doodle_app_desc_t doodle_main(int32_t argc, char *argv[]) {
    void **module_configs = calloc(DOODLE_MODULE_TYPE_COUNT, sizeof(void *));

    printf("main\n");

    doodle_module_renderer_config_t *renderer_config = malloc(sizeof(doodle_module_renderer_config_t));
    *renderer_config = (doodle_module_renderer_config_t){
        .width = 640,
        .height = 480,
    };
    module_configs[DOODLE_MODULE_TYPE_RENDERER] = renderer_config;

    doodle_app_desc_t desc = {
        .name = "blank",
        .module_configs = module_configs,
        .setup = display_setup,
        .loop = display_loop,
        .teardown = display_teardown,
    };

    printf("main end\n");
    return desc;
}