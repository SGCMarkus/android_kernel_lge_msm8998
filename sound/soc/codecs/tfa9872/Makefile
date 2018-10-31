# NXP audio amplifier - TFA9872

TFA_DEBUG                =1
TFA_ENABLED_CODE         =1
TFA_DISABLED_CODE        =1
TFADSP_DEBUG             =1
TFA_VERSION              =tfa9872
TFADSP_32BITS            =1
TFADSP_DSP_MSG_BUFFERING =0
TFADSP_DSP_MSG_APR_PACKET_STRATEGY=1
TFADSP_DSP_BUFFER_POOL=1
TFA_SOFTDSP              =1
TFA_SRC_DIR              =sound/soc/codecs/$(TFA_VERSION)
TFA98XX_FLAGS           := -DUSE_TFA9872

# cc flags
#ccflags-y               := -DDEBUG
ccflags-y               += -I$(TFA_SRC_DIR)/inc
ccflags-y               += -Werror
ifdef TFA_DEBUG
ccflags-y               += -DTFA_DEBUG
endif
ifdef TFADSP_32BITS
ccflags-y               += -DTFADSP_32BITS
endif
ifdef TFADSP_DSP_MSG_BUFFERING
#ccflags-y               += -DTFADSP_DSP_MSG_BUFFERING
endif
ifdef TFADSP_DSP_MSG_APR_PACKET_STRATEGY
ccflags-y               += -DTFADSP_DSP_MSG_APR_PACKET_STRATEGY
endif
ifdef TFADSP_DSP_BUFFER_POOL
ccflags-y               += -DTFADSP_DSP_BUFFER_POOL
endif
ifdef TFA_SOFTDSP
ccflags-y               += -DTFA_SOFTDSP
endif
ifdef TFADSP_DEBUG
ccflags-y               += -DTFADSP_DEBUG
endif
ifdef TFA_DISABLED_CODE
ccflags-y               += -DTFA_DISABLED_CODE
endif
ifdef TFA_ENABLED_CODE
ccflags-y               += -DTFA_ENABLED_CODE
endif

# objs
snd-soc-tfa98xx-objs    := tfa98xx.o
snd-soc-tfa98xx-objs    += tfa_container.o
snd-soc-tfa98xx-objs    += tfa_dsp.o
snd-soc-tfa98xx-objs    += tfa_init.o
ifdef TFA_DEBUG
snd-soc-tfa98xx-objs    += tfa_debug.o
endif

# CFLAGS
CFLAGS_tfa98xx.o       += $(TFA98XX_FLAGS)
CFLAGS_tfa_container.o += $(TFA98XX_FLAGS)
CFLAGS_tfa_dsp.o       += $(TFA98XX_FLAGS)
CFLAGS_tfa_init.o  += $(TFA98XX_FLAGS)
ifdef TFA_DEBUG
CFLAGS_tfa_debug.o     += $(TFA98XX_FLAGS)
endif

ifdef TFADSP_DSP_MSG_BUFFERING
#obj-m += snd-soc-tfa98xx-ext-dummy.o
#snd-soc-tfa98xx-ext-dummy-objs += tfa_ext_dummy.o
#obj-m += snd-soc-tfa98xx-ext-dummy-qcom.o
#snd-soc-tfa98xx-ext-dummy-qcom-objs += tfa_ext_dummy_qcom.o
#CFLAGS_tfa_ext_dummy.o     += $(TFA98XX_FLAGS)
#CFLAGS_tfa_ext_dummy_qcom.o     += $(TFA98XX_FLAGS)
endif

# built-in driver
obj-y	+= snd-soc-tfa98xx.o

obj-$(CONFIG_TOUCHSCREEN_SCROFF_VOLCTR)	+= tfa98xx_notifier.o
