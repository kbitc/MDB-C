uint8_t VMC() {

}

uint8_t cashless1() {
  if (cashless1.online == 0x00) {
    clearBlock();
    block[0].whole = (CASHLESS_POLL_COMMAND | 0x0100);
    pointer = 1;
    tX(pointer, VMC_ADDRESS);
    c
  }

  }
}

uint8_t VMC() {}
uint8_t CHANGER()
{
	static uint8_t poll_timer;
	constant int32_t max_non_response = 2Seconds;
	constant unresponsive poll 10 seconds;
	constant poll 2-5 seconds;
	if vmc_timer();
	/*5.0*/
	/*5.1*/
	/*5.2*/
	/*5.3*/
	/*5.4*/
	/*5.5*/
	/*5.6*/

	uint8_t changerReset(void)
	{
	changer.busy_f = 0x1; /* Until hardware finishes reset */
	changer.commandOutOfSequence_f = 0x0;
	changer.status_f = 0x1; /* Just Reset Status */
	changer.alternativePayoutMethod_s = 0x0;
	changer.extendedDiagnosticCommand_s = 0x0;
	changer.controlledManualFillPayout_s = 0x0;
	changer.ftlSupported_s = 0x0;
	}

	uint8_t changerSetup(void)
	{
	clearBlock();
	for (int counter = 0; counter < 23; counter++) {
		if (counter < 1)
			sBlock[counter].part.data = changer.changerFeatureLevel_c;
		else if (counter < 3)
			sBlock[counter].part.data = changer.countryCurrencyCode_c[counter - 1];
		else if (counter < 4)
			sBlock[counter].part.data = changer.scaleFactor_c;
		else if (counter < 5)
			sBlock[counter].part.data = changer.decimalPlaces_c;
		else if (counter < 7)
			sBlock[counter].part.data = changer.coinTypeRouting_c[counter - 5];
		else if (counter < 23)
			sBlock[counter].part.data = changer.coinTypeCredit_c[counter - 7];
	}
	pointer = 23;
	return tX(pionter, changer.address);
	}

	uint8_t changerTubeStatus(void)
	{
		for (int counter = 0; counter < 18; counter++) {
			if (counter < 2)
				sBlock[counter].part.data = changer.tubeFullStatus[counter];
			else
				sBlock[counter].part.data = changer.tubeStatus[counter - 2];
		}
		pointer = 18;
		return tX(pointer, changer.address)
	}

	uint8_t changerPoll(void)
	{
	if (changer.coinsDispensedManually_f == 0x01) {
	clearBlock();
	{
		int counter = 0;
		do {
			sBlock[counter].part.data = changer.coinsDispensedManuallyData[counter];
			counter++;
			sBlock[counter].part.data = changer.coinsDispensedManuallyData[counter];
			counter++;
		} while ((sBlock[changer.coinsDispensedManually[counter] != 0X00) && (counter < 16))
		pointer = counter;
		rxResult = tX(pointer, changer.address);
		if (rxResult == ACK)
			changer.coinsDispensedManually_f = 0x0;
		clearBlock();
		return rxResult;
		}
	}
	else if (changer.coinsDeposited_f == 0x1) {
		clearBlock();
		{
		int counter = 0;
		do {
			sBlock[counter].part.data = changer.coinsDeposited[counter];
			counter++;
			sBlock[counter].part.data = changer.coinsDeposited[counter];
			counter++;
		} while ((sBlock[changer.coinsDeposited[counter] != 0X00) && (counter < 16))
		pointer = counter;
		rxResult = tX(pointer, changer.address);
		if (rxResult == ACK)
			changer.coinsDeposited_f = 0x0;
		clearBlock();
		return rxResult;
		}
	}
	else if (changer.status_f) {
		int counter = 0;
		clearBlock();
		if (changer.noCredit_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_NOCREDIT;
			changer.noCredit_f = 0x0;
			counter++;
		}
		if (changer.defectiveTubeSensor_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_DEFECTIVETUBESENSOR;
			changer.defectiveTubeSensor_f = 0x0;
			counter++;
		}
		if (changer.doubleArrival_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_DOUBLEARRIVAL;
			changer.doubleArrival_f = 0x0;
			counter++;
		}
		if (changer.acceptorUnplugged_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_ACCEPTORUNPLUGGED;
			counter++;
		}
		if (changer.tubeJam_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_TUBEJAM;
			changer.tubeJam_f = 0x0;
			counter++;
		}
		if (changer.romChecksumError_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_ROMCHECKSUMERROR;
			changer.romChecksumError_f = 0x0;
			counter++;
		}
		if (changer.coinRoutingError_f = 0x1) {
			sBlock.part.data = CHANGER_STATUS_COINROUTINGERROR;
			changer.coinRoutingError_f = 0x0;
			counter++;
		}
		if (changer.busy_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_BUSY;
			counter++;
		}
		if (changer.wasReset_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_WASRESET;
			changer.wasReset_f = 0x0;
			counter++;
		}
		if (changer.coinJam_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_COINJAM;
			changer.coinJam_f = 0x0;
			counter++;
		}
		if (changer.possibleCreditedCoinRemoval_f = 0x1) {
			sBlock[counter].part.data = CHANGER_STATUS_POSSIBLECREDITEDCOINREMOVAL;
			changer.possibleCreditedCoinRemoval_f = 0x0;
			counter++;
		}
	}
	else if (changer.slug_f) {
		sBlock[counter].part.data = (CHANGER_POLL_RESPONSE_SLUG | changer.slugs);
		changer.slugs = 0x00;
		changer.slug_f = 0x0;
	}
	pointer = counter;
	return tX(pointer, changer.address);
	}

	uint8_t changerCoinType(void)
	{
	changer.coinEnable[0] = mBlock[1].part.data;
	changer.coinEnable[1] = mBlock[2].part.data;
	changer.manualDispenseEnable[0] = mBlock[3].part.data;
	changer.manualDispenseEnable[1] = mBlock[4].part.data;
	clearBlock();
	for (int counter = 15, arrayCounter = 0,  shiftCounter = 7; counter < 255; counter--) {
		changer.coin_s[counter] = (changer.coinEnable[arrayCounter] >> shiftCounter & 0x01);
		if (counter == 8) {
			shiftCounter = 7;
			arrayCounter = 1;
		}
	}
	for (int counter = 15, arrayCounter = 0, shiftCounter = 7; counter < 255; counter--) {
		changer.coinManualDispense_s[counter] = (changer.manualDispenseEnable[arrayCounter] >> shiftCounter & 0x01);
		if (counter == 8) {
			shiftCounter = 7;
			arrayCounter = 1;
		}
	}
	return EMPTY;
	}

	uint8_t changerDispense(void)
	{
	changer.payoutCycle_f = 0x1;
	if (changer.dispense_que_counter != 15)
		changer.dispense_que[changer.dispense_que_countner + 1] = mBlock[1].part.data;
	clearBlock();
	return EMPTY;
	/* #FIXDIS */
	}

	uint8_t changerExpansion(void)
	{
		switch (mBlock[1].part.data) {
			case CHANGER_EXPANSION_IDENTIFICATION_COMMAND :
				clearBlock();
				for (int counter = 0; counter < 33; counter++) {
					if (counter < 3)
						sBlock[counter].part.data = changer.manufacturerCode[counter];
					else if (counter < 15)
						sBlock[counter].part.data = changer.serialNumber[counter - 3];
					else if (counter < 27)
						sBlock[counter].part.data = changer.modelNumber[counter - 15];
					else if (counter < 29)
						sBlock[counter].part.data = changer.softwareVersion[counter - 27];
					else if (counter < 33)
						sBlock[counter].part.data = changer.optionalFeatureBits[counter - 29];
				}
				pointer = 33;
				return tX(pointer, changer.address);
			case CHANGER_EXPANSION_FEATUREENABLE_COMMAND :
				uint8_t optionalFeatureBitsEnabled[3];
				for (int counter = 0; counter < 4; counter++) {
					optionalFeatureBitsEnabled[counter] = mBlock[counter + 3];
				}
				clearBlock();
				if ((optionalFeatureBitsEnabled[3] & 0x01) == 0x01)
					changer.alternativePayoutMethod_s = 0x1;
				if ((optionalFeatureBitsEnabled[3] & 0x02) == 0x02)
					changer.extendedDiagnosticCommand_s = 0x1;
			if ((optionalFeatureBitsEnabled[3] & 0x04) == 0x04)
					changer.controlledManualFillPayout_s = 0x1;
				if ((optionalFeatureBitsEnabled[3] & 0x08) == 0x08)
					changer.ftlSupported_s = 0x1;
				return EMPTY;
			case CHANGER_EXPANSION_PAYOUT_COMMAND :
				changer.payout_f = 0x1;
				changer.valueOfCoinsToBePaidOut += mBlock[2].part.data;
				clearBlock();
				return EMPTY;
			case CHANGER_EXPANSION_PAYOUTSTATUS :
				clearBlock();
				for (int counter = 0; counter < 16; counter++) {
					sBlock[counter].part.data = changer.coinsPaid[counter];
				}
				pointer = 16;
				rxResult = tX(pointer, changer.address);
				if (rxResult == ACK) {
					changer.coinsPaid = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
					return EMPTY;
				}
				else
					return rxResult;
			case CHANGER_EXPANSION_PAYOURVALUEPOLL :
				clearBlock();
				sBlock[0].part.data = changer.payoutValue;
				pointer = 1;
				rxResult = tX(pointer, changer.address);
				changer.payoutValue = 0x00;
				return EMPTY;
			case CHANGER_EXPANSION_SENDDIAGNOSTICSTATUS_COMMAND :
				clearBlock();
				pointer = 0;
				if ((pointer < 8) && (changer.poweringUp_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_POWERINGUP >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_POWERINGUP;
					pointer++;
				}
				if ((pointer < 8) && (changer.poweringDown_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_POWERINGDOWN >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_POWERINGDOWN;
					pointer++;
				}
				if ((pointer < 8) && (changer.ok_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_OK >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_OK;
					pointer++;
				}
				if ((pointer < 8) && (changer.keypadShifted_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_KEYPADSHIFTED>> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_KEYPADSHIFTED;
					pointer++;
				}
				if ((pointer < 8) && (changer.poweringDown_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_POWERINGDOWN >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_POWERINGDOWN;
					pointer++;
				}
				if ((pointer < 8) && (changer.manualFillPayoutActive_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_MANUALFILLPAYOUTACTIVE >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_MANUALFILLPAYOUTACTIVE;
					pointer++;
				}
				if ((pointer < 8) && (changer.newInventoryInformationAvailable_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_NEWINVENTORYINFORMATIONAVAILABLE >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NEWINVENTORYINFORMATIONAVAILABLE;
					pointer++;
				}
				if ((pointer < 8) && (changer.inhibitedByVMC_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_INHIBITEDBYVMC >> 8;
					pointer++;
					sBlock[pointer].part.data = CHANGER_INHIBITEDBYVMC;
					pointer++;
				}
				if ((pointer < 8) && (changer.generalChangeError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.generalChangeError_NonSpecificError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.checksumError1_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR_CHECKSUM1;
					changer.checksumError1_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.checksumError2_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR_CHECKSUM2;
					changer.checksumError2_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.lowLineVoltage_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_GENERALCHANGERERROR_LOWLINEVOLTAGE;
					changer.lowLineVoltage_f = 0x0;
					pointer++;
				}
				if ((pointer < 8) && (changer.discriminatorModuleError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.discriminatorModuleError_NonSpecificError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.flightDeckOpen_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_FLIGHTDECKOPEN;
					changer.flightDeckOpen_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.escrowReturnStuckOpen_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_ESCROWRETURNSTUCK;
					changer.escrowReturnStuckOpen_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.coinJamInSensor_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_COINJAMINSENSOR;
					changer.coinJamInSensor_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.discriminationSubstandard_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERRORR_DISCRIMINATIONSUBSTANDARD;
					changer.discriminationSubstandard_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.validationSensorAOutOfRange_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_VALIDATIONSENSORAOUTOFRANGE;
					changer.validatorSensorAOutOfRange_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.validationSensorBOutOfRange_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_VALIDATIONSENSORBOUTOFRANGE;
					changer.validatorSensorBOutOfRange_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.validationSensorCOutOfRange_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_VALIDATIONSENSORCOUTOFRANGE;
					changer.validatorSensorCOutOfRange_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.operatingTemperatureExceeded_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_OPERATINGTEMPERATUREEXCEEDED;
					changer.operatingTemperatureExceeded_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.sizingOpticsFailure_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR_SIZINGOPTICSFAILURE;
					changer.sizingOpticsFailure_f = 0x0;
					pointer++;
				}
				if ((pointer < 8) && (changer.acceptGateError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_ACCEPTGATEMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.acceptGateError_NonSpecificError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.sortSensorError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISCRIMINATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_SEPARATORMODULEERROR_SORTSENSOR;
					changer.sortSensorError_f = 0x0;
					pointer++;
				}
				if ((pointer < 8) && (changer.separatorModuleError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_SEPARATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.separatorModuleError_NonSpecificError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.sortSensorError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_SEPARATORMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_SEPARATORMODULEERROR_SORTSENSOR;
					changer.sortSensorError_f = 0x0;
					pointer++;
				}
				if ((pointer < 8) && (changer.dispenserModuleError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_DISPENSERMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.dispenserModuleError_NonSpecificError_f = 0x0;
					pointer++;
				}
				if ((pointer < 8) && (changer.cassetteTubeModuleError_NonSpecificError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_NONSPECIFICERROR;
					changer.cassetteTubeModuleError_NonSpecificError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.cassetteRemoved_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR_CASSETTEREMOVED;
					changer.cassetteRemoved_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.cashBoxSensorError_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR_CASHBOXSENSOR;
					changer.cashBoxSensorError_f = 0x0;
					pointer++;
				}
				else if ((pointer < 8) && (changer.sunlightOnTubeSensor_f = 0x1)) {
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR;
					pointer++;
					sBlock[pointer].part.data = CHANGER_CASSETTETUBEMODULEERROR_SUNLIGHTONTUBESENSOR;
					changer.sunlightOnTubeSensor_f = 0x0;
					pointer++;
				}
				return tX(pointer, changer.address);
			case CHANGER_EXPANSION_SENDCONTROLLEDMANUALFILLREPORT :
				clearBlock();
				for (int counter = 0; counter < 16; counter++) {
					sBlock[counter].part.data = changer.coinsFilledManually[counter];
				}
				pointer = 16;
				return tX(pointer, changer.address);
			case CHANGER_EXPANSION_SENDCONTROLLEDMANUALPAYOUTREPORT :
				clearBlock();
				for (int counter = 0; counter < 16; counter++) {
					sBlock[counter].part.data = changer.coinsDispensedManually[counter];
				}
				pointer = 16
				return tX(pointer, changer.address);
			case CHANGER_FTL_REQTORCV_COMMAND :
				return ftl(changer.address);
			case CHANGER_FTL_RETRYDENY_COMMAND :
				return ftl(changer.address);
			case CHANGER_FTL_SENDBLOCK_COMMAND :
				return ftl(changer.address);
			case CHANGER_FTL_OKTOSEND_COMMAND :
				return ftl(changer.address);
			case CHANGER_FTL_REQTOSEND_COMMAND :
				return ftl(changer.address);
			case CHANGER_EXPANSION_DIAGNOSTICS_COMMAND :
				/* Manufacturer defined test data */
				return 0;
		}
	}

	/*5.4 Non-Response Time*/
	/*5.5 Power Requirements */
	/*5.6 Session Examples*/
	uint8_t mainz(void)
	{
	if (rX9BitsAvailable() == 0x1)
		rxResult = rX(changer.address);
	if (rxResult == RECEIVED) {
		rxResult = EMPTY;
		switch (mBlock[0].part.data) {
			case CHANGER_RESET_COMMAND :
			case CHANGER_SETUP_COMMAND :
			case CHANGER_TUBESTATUS_COMMAND :
			case CHANGER_POLL_COMMAND :
			case CHANGER_COINTYPE_COMMAND :
			case CHANGER_DISPENSE_COMMAND :
			case CHANGER_EXPANSION_COMMAND :
		}
	}
	}
}

uint8_t CASHLESS1() {}
uint8_t COMMUNICATIONS_GATEWAY() {}
uint8_t DISPLAY() {}
uint8_t ENERGY_MANAGEMENT_SYSTEM() {}
uint8_t BILL_VALIDATOR() {}
uint8_t RESERVED_FOR_FUTURE_STANDARD_PERIPHERAL() {}
uint8_t UNIVERSAL_SATELLITE_DEVICE1() {}
uint8_t UNIVERSAL_SATELLITE_DEVICE2() {}
uint8_t UNIVERSAL_SATELLITE_DEVICE3() {}
uint8_t COIN_HOPPER1() {}
uint8_t CASHLESS2() {}
uint8_t AGE_VERIFICATION_DEVICE() {}
uint8_t COIN_HOPPER2() {}
uint8_t EXPERIMENTAL_PERIPHERAL1() {}
uint8_t EXPERIMENTAL_PERIPHERAL2() {}
uint8_t VENDING_MACHINE_SPECIFIC_PERIPHERAL1() {}
uint8_t VENDING_MACHINE_SPECIFIC_PERIPHERAL2() {}
