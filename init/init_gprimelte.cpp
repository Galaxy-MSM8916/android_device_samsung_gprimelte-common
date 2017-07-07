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
	std::string bootloader = property_get("ro.bootloader");

	char *bootloader_str = NULL;
	char *build_id = NULL;
	char *device = NULL;
	char *model = NULL;
	char *name = NULL;
	char *operator_alpha = NULL;
	char *operator_numeric = NULL;
	char *version_release = NULL;

	int network_type = 1;

	if (bootloader.find("G530HXX") == 0) {
		build_id = (char *)"LRX22G";
		device = (char *)"fortuna3g";
		model = (char *)"SM-G530H";
		name = (char *)"fortuna3gxx";
		network_type=GSM_DEVICE;
		version_release = (char *)"5.0.2";
	}
	else if (bootloader.find("G530HXC") == 0) {
		build_id = (char *)"LRX22G";
		device = (char *)"fortunave3g";
		model = (char *)"SM-G530H";
		name = (char *)"fortunave3gxx";
		network_type=GSM_DEVICE;
		version_release = (char *)"5.0.2";
	}
	else if (bootloader.find("G530FZ") == 0) {
		build_id = (char *)"LRX22G";
		device = (char *)"grandprimelte";
		model = (char *)"SM-G530FZ";
		name = (char *)"grandprimeltexx";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.0.2";
	}
	else if (bootloader.find("G530MUU") == 0) {
		build_id = (char *)"KTU84P";
		device = (char *)"fortunaltezt";
		model = (char *)"SM-G530MU";
		name = (char *)"fortunalteuh";
		network_type=LTE_DEVICE;
		version_release = (char *)"4.4.4";
	}
	else if (bootloader.find("G530MU") == 0) {
		build_id = (char *)"LRX22G";
		device = (char *)"fortunalte";
		model = (char *)"SM-G530M";
		name = (char *)"fortunalteub";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.0.2";
	}
	else if (bootloader.find("G530P") == 0) {
		build_id = (char *)"LMY47X";
		device = (char *)"gprimeltespr";
		model = (char *)"SM-G530P";
		network_type=CDMA_DEVICE;
		operator_alpha= (char *)"Chameleon";
		operator_numeric= (char *)"310000";
		version_release = (char *)"5.1.1";
	}
	else if (bootloader.find("G530T1") == 0) {
		build_id = (char *)"LMY47X";
		device = (char *)"gprimeltemtr";
		model = (char *)"SM-G530T1";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.1.1";
	}
	else if (bootloader.find("G530T") == 0) {
		build_id = (char *)"LMY47X";
		device = (char *)"gprimeltetmo";
		model = (char *)"SM-G530T";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.1.1";
	}
	else if (bootloader.find("G530W") == 0) {
		build_id = (char *)"LMY47X";
		device = (char *)"gprimeltecan";
		model = (char *)"SM-G530W";
		name = (char *)"gprimeltevl";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.1.1";
	}
	else if (bootloader.find("S920L") == 0) {
		build_id = (char *)"LRX22G";
		device = (char *)"gprimeltetfnvzw";
		model = (char *)"SM-S920L";
		network_type=CDMA_DEVICE;
		operator_alpha= (char *)"TracFone";
		operator_numeric= (char *)"310000";
		version_release = (char *)"5.0.2";
	}
	else {
		return;
	}

	/* make sure device name is set */
	if (name == NULL)
		name = device;

	/* set the properties */
	set_target_properties(build_id, bootloader_str, name, device, model,
		       network_type, operator_alpha, operator_numeric, version_release);
}
