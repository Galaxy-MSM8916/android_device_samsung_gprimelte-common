LOCAL_PATH := $(call my-dir)

ifneq ($(filter fortuna3g fortunave3g fortunalte fortunalteub gprimelte gprimeltexx gprimeltespr gprimeltetfnvzw gprimeltezt, $(TARGET_DEVICE)),)

include $(call all-subdir-makefiles,$(LOCAL_PATH))

endif
