/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above
	  copyright notice, this list of conditions and the following
	  disclaimer in the documentation and/or other materials provided
	  with the distribution.
	* Neither the name of The Linux Foundation nor the names of its
	  contributors may be used to endorse or promote products derived
	  from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <init_msm8916.h>

void init_target_properties(void)
{
	char bootloader[PROP_VALUE_MAX];
	/* get the bootloader string */
	property_get("ro.bootloader", bootloader);

	char *device = NULL;
	char *model = NULL;
	char *operator_alpha = NULL;
	char *operator_numeric = NULL;
	int network_type = 1;

	if (strstr(bootloader,"G530HXX")) {
		device = (char *)"fortuna3g";
		model = (char *)"SM-G530H";
		network_type=GSM_DEVICE;
	}
	else if (strstr(bootloader,"G530HXC")) {
		device = (char *)"fortunave3g";
		model = (char *)"SM-G530H";
		network_type=GSM_DEVICE;
	}
	else if (strstr(bootloader,"G530FZ")) {
		device = (char *)"gprimeltexx";
		model = (char *)"SM-G530FZ";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"G530MUU")) {
		device = (char *)"gprimeltezt";
		model = (char *)"SM-G530MU";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"G530MU")) {
		device = (char *)"fortunalteub";
		model = (char *)"SM-G530M";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"G530P")) {
		device = (char *)"gprimeltespr";
		model = (char *)"SM-G530P";
		network_type=CDMA_DEVICE;
		operator_alpha= (char *)"Chameleon";
		operator_numeric= (char *)"310000";
	}
	else if (strstr(bootloader,"G530T1")) {
		device = (char *)"gprimeltemtr";
		model = (char *)"SM-G530T1";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"G530T")) {
		device = (char *)"gprimeltetmo";
		model = (char *)"SM-G530T";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"G530W")) {
		device = (char *)"gprimeltecan";
		model = (char *)"SM-G530W";
		network_type=LTE_DEVICE;
	}
	else if (strstr(bootloader,"S920L")) {
		device = (char *)"gprimeltetfnvzw";
		model = (char *)"SM-S920L";
		network_type=CDMA_DEVICE;
		operator_alpha= (char *)"TracFone";
		operator_numeric= (char *)"310000";
	}
	/* set the properties */
	set_target_properties((char *)bootloader, device, model,
		       network_type, operator_alpha, operator_numeric);
}
