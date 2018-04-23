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
	char *device = NULL;
	char *model = NULL;

	std::string bootloader = android::base::GetProperty("ro.bootloader", "");

	if (bootloader.find("G530HXX") == 0) {
		device = (char *)"fortuna3g";
		model = (char *)"SM-G530H";
		set_gsm_properties();
		set_dsds_properties();
	}
	else if (bootloader.find("G530HXC") == 0) {
		device = (char *)"fortunave3g";
		model = (char *)"SM-G530H";
		set_gsm_properties();
		set_dsds_properties();
	}
	else if (bootloader.find("G530FZ") == 0) {
		device = (char *)"gprimeltexx";
		model = (char *)"SM-G530FZ";
		set_lte_properties();
	}
	else if (bootloader.find("G530MUU") == 0) {
		device = (char *)"fortunaltezt";
		model = (char *)"SM-G530MU";
		set_lte_properties();
	}
	else if (bootloader.find("G530MU") == 0) {
		device = (char *)"fortunalte";
		model = (char *)"SM-G530M";
		set_lte_properties();
	}
	else if (bootloader.find("G530P") == 0) {
		device = (char *)"gprimeltespr";
		model = (char *)"SM-G530P";
		set_cdma_properties("Chameleon", "310000", "10");
	}
	else if (bootloader.find("G530T1") == 0) {
		device = (char *)"gprimeltemtr";
		model = (char *)"SM-G530T1";
		set_lte_properties();
	}
	else if (bootloader.find("G530T") == 0) {
		device = (char *)"gprimeltetmo";
		model = (char *)"SM-G530T";
		set_lte_properties();
	}
	else if (bootloader.find("G530W") == 0) {
		device = (char *)"gprimeltecan";
		model = (char *)"SM-G530W";
		set_lte_properties();
	}
	else if (bootloader.find("S920L") == 0) {
		device = (char *)"gprimeltetfnvzw";
		model = (char *)"SM-S920L";
		set_cdma_properties("TracFone", "310000", "10");
	}
	else if (bootloader.find("G5309W") == 0) {
		device = (char *)"fortunaltectc";
		model = (char *)"SM-G5309W";
		set_lte_properties();
	}
	else {
		return;
	}

	/* set the properties */
	set_target_properties(device, model);
}
