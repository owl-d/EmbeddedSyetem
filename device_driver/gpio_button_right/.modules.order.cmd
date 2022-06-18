cmd_/home/pi/work/gpio_button_right/modules.order := {   echo /home/pi/work/gpio_button_right/gpio_button_right_driver.ko; :; } | awk '!x[$$0]++' - > /home/pi/work/gpio_button_right/modules.order
