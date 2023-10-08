SRC += ./features/achordion.c
SRC += ./features/oled.c
SRC += ./features/luna.c
SRC += ./features/overlay.c

SERIAL_DRIVER = vendor

COMMAND_ENABLE = no
CONSOLE_ENABLE = no

BOOTMAGIC_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
COMBO_ENABLE = yes
NKRO_ENABLE = yes

UNICODE_COMMON = yes
RGB_MATRIX = yes
OLED_ENABLE = yes
WPM_ENABLE = yes
