#include "esp_log.h"
#include "bsp/esp-lcd-3-5-bsp.h"
#include "lvgl.h"
#include "ui/ui.h"


#define TAG "MAIN"
#define APP_DISP_DEFAULT_BRIGHTNESS 50

void app_lvgl_display(void)
{
    bsp_lcd_lock(0);

    ui_init();

    bsp_lcd_unlock();
}

void app_main(void)
{
    /* Initialize I2C */
    bsp_lcd_i2c_init();

    /* Initialize display and LVGL */
    lv_disp_t *disp = bsp_lcd_start(false);
    // THIS DOESN'T WORK
     lv_disp_set_rotation(disp, LV_DISP_ROT_NONE);

    /* Add and show objects on display */
    app_lvgl_display();

    ESP_LOGI(TAG, "Initialization done.");
}
