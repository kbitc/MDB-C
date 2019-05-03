CREATE TABLE DTS_DT (
  Identifier VARCHAR(255) NULL, 
  Element Name VARCHAR(255) NULL, 
  Contents TEXT NULL, 
  Type VARCHAR(255) NULL, 
  Length Min NUMERIC NULL, 
  Length Max NUMERIC NULL
);
INSERT INTO DTS_DT (
  Identifier, Element Name, Contents, 
  Type, Length Min, Length Max
) 
VALUES 
  (
    'AC101', 'AUDIT_MODULE_SERIAL_NUMBER', 
    'Configures field AM101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'AC102', 'AUDIT_MODULE_MODEL_NUMBER', 
    'Configures field AM102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'AC103', 'AUDIT_MODULE_SOFTWARE_REVISION', 
    'Configures field AM103 (not post manufacturer configurable)', 
    'No', 1, 4
  ), 
  (
    'AC104', 'USER_DEFINED_FIELD', 'Configures field AM104', 
    'AN', 1, 12
  ), 
  (
    'AC105', 'AUDIT_MODULE_ASSET_NUMBER', 
    'Configures field AM105', 'AN', 
    1, 20
  ), 
  (
    'AM101', 'AUDIT_MODULE_SERIAL_NUMBER', 
    'Identification number of the Audit Module/ Comms Gateway. Typically includes a three character supplier ID code from Appendix B. This number may only be set by the Manufacturer. AM1 block is optional. If any AM1 data is transmitted, then AM101 becomes mandatory.', 
    'AN', 1, 20
  ), 
  (
    'AM102', 'AUDIT_MODULE_MODEL_NUMBER', 
    'Model number or description of the Audit Module / Comms Gateway.', 
    'AN', 1, 20
  ), 
  (
    'AM103', 'AUDIT_MODULE_SOFTWARE_REVISION', 
    'Software revision number of the Audit Module / Comms Gateway.', 
    'No', 1, 4
  ), 
  (
    'AM104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'AM105', 'AUDIT_MODULE_ASSET_NUMBER', 
    'Audit Module / Comms Gateway Asset Number reference for accounting purposes. Separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'BA101', 'BILL_VALIDATOR_SERIAL_NUMBER', 
    'Identification number of bill validator. Typically, includes a three character supplier ID code from Appendix B (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BA102', 'BILL_VALIDATOR_MODEL_NUMBER', 
    'Model Number or description of bill validator (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BA103', 'BILL_VALIDATOR_SOFTWARE_REVISION', 
    'Software revision of the bill validator (not post manufacturer configurable).', 
    'AN', 1, 4
  ), 
  (
    'BA104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'BA105', 'BILL_VALIDATOR_ASSET_NUMBER', 
    'Asset number used for tracking purposes. Programmable field.', 
    'AN', 1, 20
  ), 
  (
    'BC101', 'CONTROL_BOARD_SERIAL_NUMBER', 
    'Configures field CB101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BC102', 'CONTROL_BOARD_MODEL_NUMBER', 
    'Configures field CB102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BC103', 'CONTROL_BOARD_SOFTWARE_REVISION', 
    'Configures field CB103 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BC104', 'USER_DEFINED_FIELD', 'Configures field CB104', 
    'AN', 1, 12
  ), 
  (
    'BC105', 'CONTROL_BOARD_ASSET_NUMBER', 
    'Configures field CB105', 'AN', 
    1, 20
  ), 
  (
    'BC201', 'BILL_VALIDATOR_SERIAL_NUMBER', 
    'Configures field BA101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BC202', 'BILL_VALIDATOR_MODEL_NUMBER', 
    'Configures field BA102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'BC203', 'BILL_VALIDATOR_SOFTWARE_REVISION', 
    'Configures field BA103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'BC204', 'USER_DEFINED_FIELD', 'Configures field BA104', 
    'AN', 1, 12
  ), 
  (
    'BC205', 'BILL_VALIDATOR_ASSET_NUMBER', 
    'Configures field BA105', 'AN', 
    1, 20
  ), 
  (
    'CA101', 'COIN_MECH_SERIAL_NUMBER', 
    'Identification number of the coin mechanism. This number may only be set by the Manufacturer. Typically includes a three character supplier ID code from Appendix B. MDB level 2 changers may transmit a blank field but all MDB level 3 and above changers must send valid data (not post manufacturer configurable). CA1 block is optional. If any CA1 data is', 
    'AN', 1, 20
  ), 
  (
    'CA102', 'COIN_MECH_MODEL_NUMBER', 
    'Model number or description of the coin mechanism. MDB level 2 changers may transmit a blank field but all MDB level 3 and above changers must send valid data.', 
    'AN', 1, 20
  ), 
  (
    'CA103', 'COIN_MECH_SOFTWARE_REVISION', 
    'Software revision number of the coin mechanism. MDB level 2 changers may transmit a blank field but all MDB level 3 and above changers must send valid data.', 
    'N0', 1, 4
  ), 
  (
    'CA104', 'USER_DEFINED_FIELD', 'Use a Defined Data', 
    'AN', 1, 12
  ), 
  (
    'CA105', 'COIN_MECH_ASSET_NUMBER', 
    'Asset Number reference for accounting purposes. Separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'CA201', 'VALUE_OF_CASH_SALES_SINCE_INITIALISATION', 
    'Value of all cash sales. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA202', 'NUMBER_OF_CASH_VENDS_SINCE_INITIALISATION', 
    'NUMBER_OF_ALL_cash vends. Non-Resettable.', 
    'N0', 1, 6
  ), 
  (
    'CA203', 'VALUE_OF_CASH_SALES_SINCE_LAST_RESET', 
    'Value of all cash sales. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA204', 'NUMBER_OF_CASH_VENDS_SINCE_LAST_RESET', 
    'Number of all cash vends. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'CA301', 'VALUE_OF_CASH_IN_SINCE_LAST_RESET', 
    'Value of all cash in. (Coins + Banknotes) Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA302', 'VALUE_OF_CASH_TO_CASH_BOX_SINCE_LAST_RESET', 
    'Value of cash sent to the cashbox. (Typically today this is coins only, not banknotes, tokens are recorded separately). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA303', 'VALUE_OF_CASH_TO_TUBES_SINCE_LAST_RESET', 
    'Value of all coins sent to the inventory tubes, including sales and manually filled. Does not include value of free vend tokens.', 
    'Nc', 1, 8
  ), 
  (
    'CA304', 'VALUE_OF_BILLS_IN_SINCE_LAST_RESET', 
    'Total value of all bills (banknotes) accepted. Does not include value of free vend tokens.  This format is used in a wide installed base and must be maintained in existing and new designs for 5 years from the introduction of Version 6.0 (until 2009).  After this date, new designs need only send CA309. Check with equipment suppliers to verify their formatting. Implemented formats include: 1) In  most North American implementations, the value of the note is divided by 100, and is sent as an N0 data type.  Example:  A $5.00 bill is sent as 5.  A $20.00 bill is sent as 20. 2) In most European implementations, the value of the note is not divided by 100, and is sent as an Nc data type.  Example:  A €5.00 bill is sent as 500.  A €20.00 bill is sent as 2000. Resettable.', 
    'N0/Nc', 1, 8
  ), 
  (
    'CA305', 'VALUE_OF_CASH_IN_SINCE_INITIALISATION', 
    'Value of cash in from all sources (coins and paper currency). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA306', 'VALUE_OF_CASH_TO_CASH_BOX_SINCE_INITIALISATION', 
    'Value of cash sent to the cashbox. (Typically today this is coins only, no banknotes). Does not include value of free vend tokens. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA307', 'VALUE_OF_CASH_TO_TUBES_SINCE_INITIALISATION', 
    'Value of all coins sent to the inventory tubes, including sales and manually filled. Does not include value of free vend tokens. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA308', 'VALUE_OF_BILLS_IN_SINCE_INITIALISATION', 
    'Total value of all bills (banknotes) accepted. Does not include value of free vend tokens. This format is used in a wide installed base and must be maintained in existing and new designs for 5 years from the introduction of Version 6.0 (until 2009). After this date, new designs need only send CA310. Check with equipment suppliers to verify their formatting. Implemented formats include: 1) In  most North American implementations, the value of the note is divided by 100, and is sent as an N0 data type.  Example:  A $5.00 bill is sent as 5.  A $20.00 bill is sent as 20. 2) In most European implementations, the value of the note is not divided by 100, and is sent as an Nc data type.  Example:  A €5.00 bill is sent as 500.  A €20.00 bill is sent as 2000. Non-Resettable.', 
    'N0/Nc', 1, 8
  ), 
  (
    'CA309', 'VALUE_OF_BILLS_IN_SINCE_LAST_RESET', 
    'Total value of all bills (banknotes) accepted. Does not include value of free vend tokens.  Example:  A $5.00 bill is sent as 500.  A $20.00 bill is sent as 2000. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA310', 'VALUE_OF_BILLS_IN_SINCE_INITIALISATION', 
    'Total value of all bills (banknotes) accepted. Does not include value of free vend tokens.  Example:  A $5.00 bill is sent as 500.  A $20.00 bill is sent as 2000. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA311', 'VALUE_OF_BILLS_TO_RECYCLER_SINCE_LAST_RESET', 
    'Value of all bills sent to the recycler, including sales and manual fill modes. Does not include value of free vend coupons.  Example:  A $5.00 bill is sent as 500.  A $20.00 bill is sent as 2000. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA312', 'VALUE_OF_BILLS_TO_RECYCLER_SINCE_INITIALISATION', 
    'Value of all bills sent to the recycler, including sales and manual fill modes. Does not include value of free vend coupons.  Example:  A $5.00 bill is sent as 500.  A $20.00 bill is sent as 2000. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA401', 'VALUE_OF_CASH_DISPENSED_SINCE_LAST_RESET', 
    'Total value paid out as change plus the value manually dispensed. (Typically coins only). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA402', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Total value dispensed manually. (Typically coins only) Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA403', 'VALUE_OF_CASH_DISPENSED_SINCE_INITIALISATION', 
    'Total value paid out as change plus the value manually dispensed. (Typically coins only). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA404', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Total value dispensed manually. (Typically coins only) Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA405', 'VALUE_OF_BILLS_DISPENSED_SINCE_LAST_RESET', 
    'Total value paid out as change plus the value manually dispensed. (Typically Bills only, not coupons or tokens). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA406', 'VALUE_OF_BILLS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Total value dispensed manually. (Typically bills only, not coupons or tokens) Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA407', 'VALUE_OF_BILLS_DISPENSED_TO_RECYCLER_SINCE_LAST_RESET', 
    'Total value manually dispensed from the recycler to the cashbox. (Typically bills only, not coupons or tokens). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA408', 'VALUE_OF_BILLS_DISPENSED_SINCE_INITIALISATION', 
    'Total value paid out as change plus the value manually dispensed. (Typically bills only, not coupons or tokens). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA409', 'VALUE_OF_BILLS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Total value dispensed manually. (Typically bills only, not coupons or tokens) Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA410', 'VALUE_OF_BILLS_MANUALLY_DISPENSED_TO_RECYCLER_SINCE_INITIALISATION', 
    'Total value manually dispensed from the recycler to the cashbox. (Typically bills only, not coupons or tokens) Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA501', 'NUMBER_OF_POWER_OUTAGES_SINCE_LAST_RESET', 
    'Total number of power down - up cycles. Resettable. Superseded by event audit see reference EA701', 
    'N0', 1, 8
  ), 
  (
    'CA502', 'NUMBER_OF_POWER_OUTAGES_SINCE_INITIALISATION', 
    'Total number of power down - up cycles. Non-Resettable. Superseded by event audit see reference EA702', 
    'N0', 1, 8
  ), 
  (
    'CA601', 'NUMBER_OF_READS_PERFORMED_SINCE_INITIALISATION', 
    'Total number of data collection reads performed. Non-Resettable. Superseded by event audit see reference EA301', 
    'N0', 1, 8
  ), 
  (
    'CA602', 'NUMBER_OF_DOOR_OPENINGS_SINCE_INITIALISATION', 
    'The number of times the vending machine door has been opened. Non Resettable Superseded by event audit see reference EA201/202', 
    'N0', 1, 8
  ), 
  (
    'CA701', 'VALUE_OF_CASH_DISCOUNTS_SINCE_LAST_RESET', 
    'Value of cash discounts given. (vend price - price paid = discount value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA702', 'VALUE_OF_CASH_DISCOUNTS_SINCE_INITIALISATION', 
    'Value of cash discounts given. (vend price - price paid = discount value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA703', 'NUMBER_OF_CASH_DISCOUNTS_SINCE_LAST_RESET', 
    'NUMBER_OF_cash discounts given. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA704', 'NUMBER_OF_CASH_DISCOUNTS_SINCE_INITIALISATION', 
    'NUMBER_OF_cash discounts given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA705', 'VALUE_OF_CASH_SURCHARGES_SINCE_LAST_RESET', 
    'Value of cash surcharges given. (price paid - vend paid = surcharge value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA706', 'VALUE_OF_CASH_SURCHARGES_SINCE_INITIALISATION', 
    'Value of cash surcharges given. (price paid - vend paid = surcharge value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA707', 'NUMBER_OF_CASH_SURCHARGES_SINCE_LAST_RESET', 
    'Number of cash surcharges given. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA708', 'NUMBER_OF_CASH_SURCHARGES_SINCE_INITIALISATION', 
    'Number of cash surcharges given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA801', 'VALUE_OF_CASH_OVERPAY_SINCE_LAST_RESET', 
    'Value of cash overpay received. (Inserted money - change paid - vend price = overpay value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA802', 'VALUE_OF_CASH_OVERPAY_SINCE_INITIALISATION', 
    'Value of cash overpay received. (Inserted money - change paid - vend price = overpay value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA901', 'VALUE_OF_PAY_VENDS_EXACT_CHANGE_SINCE_LAST_RESET', 
    'Value of the vends performed while in an exact change condition. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA902', 'VALUE_OF_PAY_VENDS_EXACT_CHANGE_SINCE_INITIALISATION', 
    'Value of the vends performed while in an exact change condition. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1001', 'VALUE_OF_CASH_FILLED_SINCE_LAST_RESET', 
    'Value of all coins manually added to the machine. (filled inventory tubes) Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1002', 'VALUE_OF_CASH_FILLED_SINCE_INITIALISATION', 
    'Value of all coins manually added to the machine. (filled inventory tubes) Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1003', 'VALUE_OF_BILLS_FILLED_SINCE_LAST_RESET', 
    'Value of all bills manually added to the machine. (filled recycler) Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1004', 'VALUE_OF_CASH_FILLED_SINCE_INITIALISATION', 
    'Value of all bills manually added to the machine. (filled recycler) Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1101', 'VALUE_OF_ACCEPTED_COIN', 
    'Value of the coin being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA1102', 'NUMBER_OF_COINS_IN_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1101) accepted. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1103', 'NUMBER_OF_COINS_TO_CASH_BOX_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1101) accepted and sent to the cashbox. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1104', 'NUMBER_OF_COINS_TO_TUBES_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1101) accepted and sent to the inventory tubes Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1105', 'NUMBER_OF_COINS_IN_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1101) accepted. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1106', 'NUMBER_OF_COINS_TO_CASH_BOX_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1101) accepted and sent to the cashbox. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1107', 'NUMBER_OF_COINS_TO_TUBES_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1101) accepted and sent to the inventory tubes Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1108', 'AGE_OF_COIN', 'Number to indicate age of the coin. Lowest number is oldest, base 0, So if two coins of the same denomination are accepted e.g. UK 5p, then old = 0, 5p new = 1 and so on. CA1109 Country of Origin International telephone code for coins of this value (CA1101) for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 1
  ), 
  (
    'CA1109', 'COUNTRY_OF_ORIGIN', 'International telephone code for coins of this value (CA1101) for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA1201', 'DISPENSED_VALUE_COIN', 
    'Value of the dispensed coin being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA1202', 'NUMBER_OF_COINS_DISPENSED_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1201) paid out as change plus manually dispensed. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1203', 'NUMBER_OF_COINS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1201) manually dispensed. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1204', 'NUMBER_OF_COINS_DISPENSED_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1201) paid out as change plus manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1205', 'NUMBER_OF_COINS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1201) manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1206', 'AGE_OF_COIN', 'Number to indicate age of the coin. Lowest number is oldest, base 0. So if two coins of the same denomination are dispensed e.g. UK 5p, then old = 0, 5p new = 1 and so on.', 
    'N0', 1, 1
  ), 
  (
    'CA1207', 'COUNTRY_OF_ORIGIN', 'International telephone code for coins of this value (CA1201) for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA1301', 'MANUALLY_FILLED_COIN_VALUE', 
    'Value of the coin manually filled being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA1302', 'NUMBER_OF_COINS_FILLED_SINCE_LAST_RESET', 
    'Number of coins of this value (CA1301) manually filled. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1303', 'NUMBER_OF_COINS_FILLED_SINCE_INITIALISATION', 
    'Number of coins of this value (CA1301) manually filled. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1304', 'AGE_OF_COIN', 'Number to indicate age of the coin. Lowest number is oldest, base 0. So if two coins of the same denomination are filled e.g. UK 5p, then old = 0, 5p new = 1 and so on.', 
    'N0', 1, 1
  ), 
  (
    'CA1305', 'COUNTRY_OF_ORIGIN', 'International telephone code for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA1401', 'BILL_VALUE', 'Value of bill being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA1402', 'NUMBER_OF_BILLS_IN_SINCE_LAST_RESET', 
    'Number of bills of this value (CA1401) validated but returned by the VMD as well as those that are routed to the stacker. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1403', 'NUMBER_OF_BILLS_TO_STACKER_SINCE_LAST_RESET', 
    'Number of bills of this value (CA1401) validated and routed to the stacker Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1404', 'NUMBER_OF_BILLS_IN_SINCE_INITIALISATION', 
    'Number of bills of this value (CA1401) validated but returned by the VMC as well as those that are routed to the stacker. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1405', 'NUMBER_OF_BILLS_TO_STACKER_SINCE_INITIALISATION', 
    'Number of bills of this value (CA1401) validated and routed to the stacker Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1501', 'VALUE_OF_TUBE_CONTENTS', 
    'Value of coins stored in all tubes of the coin changegiver.', 
    'Nc', 1, 8
  ), 
  (
    'CA1502', 'BLOCK_NO_TUBE1_COIN_TYPE0_7_TUBE2_COIN_TYPE8_15', 
    'Tube 1 indicates CA1503-CA1510 Refers to Coin Type 0-7 Tube 2 indicates CA1503-CA1510 Refers to Coin Type 8-15', 
    'AN', 1, 5
  ), 
  (
    'CA1503', 'COIN_TYPE_0_OR_7_COUNT', 
    'Number of coins in tube 0 or 7', 
    'N0', 1, 3
  ), 
  (
    'CA1504', 'COIN_TYPE_1_OR_8_COUNT', 
    'Number of coins in tube 1 or 8', 
    'N0', 1, 3
  ), 
  (
    'CA1505', 'COIN_TYPE_2_OR_9_COUNT', 
    'Number of coins in tube 2 or 9', 
    'N0', 1, 3
  ), 
  (
    'CA1506', 'COIN_TYPE_3_OR_10_COUNT', 
    'Number of coins in tube 3 or 10', 
    'N0', 1, 3
  ), 
  (
    'CA1507', 'COIN_TYPE_4_OR_11_COUNT', 
    'Number of coins in tube 4 or 11', 
    'N0', 1, 3
  ), 
  (
    'CA1508', 'COIN_TYPE_5_OR_12_COUNT', 
    'Number of coins in tube 5 or 12', 
    'N0', 1, 3
  ), 
  (
    'CA1509', 'COIN_TYPE_6_OR_13_COUNT', 
    'Number of coins in tube 6 or 13', 
    'N0', 1, 3
  ), 
  (
    'CA1510', 'COIN_TYPE_7_OR_14_COUNT', 
    'Number of coins in tube 7 or 14', 
    'N0', 1, 3
  ), 
  (
    'CA1601', 'VALUE_CREDITED_FROM_MACHINE_SINCE_LAST_RESET', 
    'Value credited from vending machine to coin mechanism. This is the “Negative Vend” from specification BDV001. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1602', 'VALUE_CREDITED_FROM_MACHINE_SINCE_INITIALISATION', 
    'Value credited from vending machine to coin mechanism. This is the “Negative Vend” from specification BDV001. Non Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'CA1701', 'COIN_TYPE_NUMBER_PER_MDB_COIN_TUBE', 
    'The coin type number as referred to in the MDB interface specification. If not an MDB system, the number represents the coin’s position in the coin set starting with the lowest value coin accepted. Note, if two or more vintage of the same coin is accepted, the oldest one is first.', 
    'N0', 1, 3
  ), 
  (
    'CA1702', 'VALUE_OF_COIN', 'The cash value of the coin (units base, not scaled units). Examples for Canadian coins:  Nickel 5 $1 Dollar 100 Dime 10 $2 Dollar 200 Quarter 25', 
    'Nc', 1, 8
  ), 
  (
    'CA1703', 'NUMBER_OF_COINS_IN_TUBE', 
    'The interim number of coins in the coin tube (or tubes if multiple tubes per coin) that are not typically reported by the coin mech during normal vending operations. Note that this is the “best known tube count” and may be inaccurate if coins were manually added or removed by hand.', 
    'N0', 1, 8
  ), 
  (
    'CA1704', 'NUMBER_OF_COINS_INSERTED_DURING_CONTROLLED_MANUAL_FILL', 
    'The interim number of coins inserted while the changer was in a controlled- manual fill mode. Controlled-manual fill indicates that the coins are being inserted under the control of the coin mech or VMC. Coins are not being loaded by hand through the tops of the tubes.', 
    'N0', 1, 8
  ), 
  (
    'CA1705', 'NUMBER_OF_COINS_DISPENSED_DURING_CONTROLLED_MANUAL_INVENT', 
    'The interim number of coins dispensed while the changer was in a controlled-manual invent mode. Controlled-manual invent indicates that the coins are being dispensed under the control of the coin mech or VMC. Coins are not being removed by hand by “dumping” the tubes.', 
    'N0', 1, 8
  ), 
  (
    'CA1706', 'COIN_TUBE_IS_FULL', 'Defined values:   0 or empty (recommended) = Tube(s) NOT full   1 = Tube is currently full', 
    'N0', 1, 1
  ), 
  (
    'CA1801', 'DESTINATION_OF_COIN', 
    'Defined values: 0=Coin sent to tubes 1=Coin sent to cash', 
    'N0', 1, 1
  ), 
  (
    'CA1802', 'VALUE_OF_ACCEPTED_COIN', 
    'as per CA1702', 'Nc', 1, 8
  ), 
  (
    'CA1901', 'VALUE_OF_ACCEPTED_BILL', 
    'Value of the bill being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA1902', 'NUMBER_OF_BILLS_IN_SINCE_LAST_RESET', 
    'Number of bills of this value (CA1901) accepted. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1903', 'NUMBER_OF_BILLS_TO_CASH_BOX_SINCE_LAST_RESET', 
    'Number of bills of this value (CA1901) accepted and sent to the cashbox. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1904', 'NUMBER_OF_BILLS_TO_RECYCLER_SINCE_LAST_RESET', 
    'Number of bills of this value (CA1901) accepted and sent to the recycler Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1905', 'NUMBER_OF_BILLS_IN_SINCE_INITIALISATION', 
    'Number of bills of this value (CA1901) accepted. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1906', 'NUMBER_OF_BILLS_TO_CASH_BOX_SINCE_INITIALISATION', 
    'Number of bills of this value (CA1901) accepted and sent to the cashbox. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1907', 'NUMBER_OF_BILLS_TO_RECYCLER_SINCE_INITIALISATION', 
    'Number of bills of this value (CA1901) accepted and sent to the recycler Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA1908', 'AGE_OF_BILL', 'Number to indicate age of the bill. Lowest number is oldest, base 0, So if two bills of the same denomination are accepted e.g. UK 1£, then old = 0, 1£ new = 1 and so on.', 
    'N0', 1, 1
  ), 
  (
    'CA1909', 'COUNTRY_OF_ORIGIN', 'International telephone code for bills of this value (CA1901) for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA2001', 'DISPENSED_VALUE_BILL', 
    'Value of the dispensed bill being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA2002', 'NUMBER_OF_BILLS_DISPENSED_SINCE_LAST_RESET', 
    'NUMBER_OF_bills of this value (CA2001) paid out as change plus manually dispensed. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2003', 'NUMBER_OF_BILLS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'NUMBER_OF_bills of this value (CA2001) manually dispensed. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2004', 'NUMBER_OF_BILLS_MANUALLY_DISPENSED_TO_CASH_BOX_SINCE_LAST_RESET', 
    'NUMBER_OF_bills of this value (CA2001) manually dispensed from the recycler to the cashbox. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2005', 'NUMBER_OF_BILLS_DISPENSED_SINCE_INITIALISATION', 
    'NUMBER_OF_bills of this value (CA2001) paid out as change plus manually dispensed.  Non-Resettable', 
    'N0', 1, 8
  ), 
  (
    'CA2006', 'NUMBER_OF_BILLS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'NUMBER_OF_bills of this value (CA2001) manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2007', 'NUMBER_OF_BILLS_MANUALLY_DISPENSED_TO_CASH_BOX_SINCE_INITIALISATION', 
    'NUMBER_OF_bills of this value (CA2001) manually dispensed from the recycler to the cashbox. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2008', 'AGE_OF_BILL', 'Number to indicate age of the bill. Lowest number is oldest, base 0. So if two bills of the same denomination are dispensed e.g. UK 1£, then old = 0, 1£ new = 1 and so on.', 
    'N0', 1, 1
  ), 
  (
    'CA2009', 'COUNTRY_OF_ORIGIN', 'International telephone code for bills of this value (CA2001) for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA2101', 'MANUALLY_FILLED_BILL_VALUE', 
    'Value of the bill manually filled being reported on.', 
    'Nc', 1, 8
  ), 
  (
    'CA2102', 'NUMBER_OF_BILLS_FILLED_SINCE_LAST_RESET', 
    'Number of bills of this value (CA2101) manually filled. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2103', 'NUMBER_OF_BILLS_FILLED_SINCE_INITIALISATION', 
    'Number of bills of this value (CA2101) manually filled. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'CA2104', 'AGE_OF_BILL', 'Number to indicate age of the bill. Lowest number is oldest, base 0. So if two bills of the same denomination are filled e.g. UK 1£, then old = 0, 1£ new = 1 and so on.', 
    'N0', 1, 1
  ), 
  (
    'CA2105', 'COUNTRY_OF_ORIGIN', 'International telephone code for non standard country of origin. Default country is identified by element ID402.', 
    'N0', 1, 3
  ), 
  (
    'CA2201', 'VALUE_OF_RECYCLER_CONTENTS', 
    'Value of all bills stored in the bill recycler.', 
    'Nc', 1, 8
  ), 
  (
    'CA2202', 'BLOCK_NO_STORE1_BILL_TYPE0_7_STORE2_BILL_TYPE8_15', 
    'Store 1 indicates CA2203-CA2210 Refers to Bill Type 0-7 Store 2 indicates CA2203-CA2210 Refers to Bill Type 8-15', 
    'AN', 1, 5
  ), 
  (
    'CA2203', 'BILL_TYPE_0_OR_7_COUNT', 
    'Number of bills in recycler 0 or 7', 
    'N0', 1, 3
  ), 
  (
    'CA2204', 'BILL_TYPE_1_OR_8_COUNT', 
    'Number of bills in recycler 1 or 8', 
    'N0', 1, 3
  ), 
  (
    'CA2205', 'BILL_TYPE_2_OR_9_COUNT', 
    'Number of bills in recycler 2 or 9', 
    'N0', 1, 3
  ), 
  (
    'CA2206', 'BILL_TYPE_3_OR_10_COUNT', 
    'Number of bills in recycler 3 or 10', 
    'N0', 1, 3
  ), 
  (
    'CA2207', 'BILL_TYPE_4_OR_11_COUNT', 
    'Number of bills in recycler 4 or 11', 
    'N0', 1, 3
  ), 
  (
    'CA2208', 'BILL_TYPE_5_OR_12_COUNT', 
    'Number of bills in recycler 5 or 12', 
    'N0', 1, 3
  ), 
  (
    'CA2209', 'BILL_TYPE_6_OR_13_COUNT', 
    'NUMBER_OF_bills in recycler 6 or 13', 
    'N0', 1, 3
  ), 
  (
    'CA2210', 'BILL_TYPE_7_OR_14_COUNT', 
    'NUMBER_OF_bills in recycler 7 or 14', 
    'N0', 1, 3
  ), 
  (
    'CA2301', 'BILL_TYPE_NUMBER_PER_MDB_BILL_STORE', 
    'The bill type number as referred to in the MDB interface specification. If not an MDB system, the number represents the bill’s position in the bill set starting with the lowest value bill accepted. Note, if two or more vintage of the same bill is accepted, the oldest one is first.', 
    'N0', 1, 3
  ), 
  (
    'CA2302', 'VALUE_OF_BILL', 'The cash value of the bill (units base, not scaled units). Examples for US bills:  $1 Dollar 100 $2 Dollar 200 $5 Dollar 500 ...', 
    'Nc', 1, 8
  ), 
  (
    'CA2303', 'NUMBER_OF_BILLS_IN_STORE', 
    'The interim number of bills in the bill store (or stores if multiple tubes per bill) that are not typically reported by the bill mech during normal vending operations. Note that this is the “best known tube count” and may be inaccurate if bills were manually added or removed by hand.', 
    'N0', 1, 8
  ), 
  (
    'CA2306', 'BILL_STORE_IS_FULL', 'Defined values:   0 or empty (recommended) = Store(s) NOT full   1 = Store is currently full', 
    'N0', 1, 1
  ), 
  (
    'CA2401', 'DESTINATION_OF_BILL', 
    'Defined values: 0=Bill sent to recycler 1=Bill sent to cash', 
    'N0', 1, 1
  ), 
  (
    'CA2402', 'VALUE_OF_ACCEPTED_BILL', 
    'as per CA2302', 'Nc', 1, 8
  ), 
  (
    'CB101', 'CONTROL_BOARD_SERIAL_NUMBER', 
    'Identification number of the Control Board. This number may only be set by the Manufacturer. CB1 block is optional. If any CB1 data is transmitted, then CB101 becomes mandatory.', 
    'AN', 1, 20
  ), 
  (
    'CB102', 'CONTROL_BOARD_MODEL_NUMBER', 
    'Model number or description of the Control Board.', 
    'AN', 1, 20
  ), 
  (
    'CB103', 'CONTROL_BOARD_SOFTWARE_REVISION', 
    'Software revision number of the Control Board.', 
    'AN', 1, 20
  ), 
  (
    'CB104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'CB105', 'CONTROL_BOARD_ASSET_NUMBER', 
    'Control Board Asset Number reference for accounting purposes. Separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'CC101', 'COIN_MECH_SERIAL_NUMBER', 
    'Configures field CA101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'CC102', 'COIN_MECH_MODEL_NUMBER', 
    'Configures field CA102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'CC103', 'COIN_MECH_SOFTWARE_REVISION', 
    'Configures field CA103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'CC104', 'USER_DEFINED_FIELD', 'Configures field CA104', 
    'AN', 1, 12
  ), 
  (
    'CC105', 'COIN_MECH_ASSET_NUMBER', 
    'Configures field CA105', 'AN', 
    1, 20
  ), 
  (
    'DA101', 'CASHLESS1_SERIAL_NUMBER', 
    'Identification number of the system (card, key or other). Typically includes a three character supplier ID code from Appendix B (not post manufacturer configurable).', 
    'AN', 1, 20
  ), 
  (
    'DA102', 'CASHLESS1_MODEL_NUMBER', 
    'Model number or description of the system (card, key or other) cashless 1 unit.', 
    'AN', 1, 20
  ), 
  (
    'DA103', 'CASHLESS1_SOFTWARE_REVISION', 
    'Software revision number of the system (card, key or other) cashless 1 unit.', 
    'N0', 1, 4
  ), 
  (
    'DA104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DA105', 'CASHLESS1_ASSET_NUMBER', 
    'Asset Number reference for accounting purposes. Separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'DA201', 'VALUE_OF_CASHLESS1_SALES_SINCE_INITIALISATION', 
    'Value of all Cashless #1 sales. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA202', 'NUMBER_OF_CASHLESS1_VENDS_SINCE_INITIALISATION', 
    'Number of all cashless #1 vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DA203', 'VALUE_OF_CASHLESS1_SALES_SINCE_LAST_RESET', 
    'Value of all Cashless #1 sales. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA204', 'NUMBER_OF_CASHLESS1_VENDS_SINCE_LAST_RESET', 
    'Number of all Cashless #1 vends. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DA205', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DA301', 'VALUE_DEMITED_FROM_CASHLESS1_SINCE_INITIALISATION', 
    'Value debited from Cashless #1. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA302', 'VALUE_DEBITED_FROM_CASHLESS1_SINCE_LAST_RESET', 
    'Value debited from Cashless #1. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA303', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DA401', 'VALUE_CREDITED_TO_CASHLESS1_SINCE_INITIALISATION', 
    'Value credited to Cashless #1. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA402', 'VALUE_CREDITED_TO_CASHLESS1_SINCE_LAST_RESET', 
    'Value credited to Cashless $1. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA403', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DA501', 'VALUE_OF_CASHLESS1_DISCOUNTS_SINCE_LAST_RESET', 
    'Value of Cashless #1 discounts given. (vend price - price paid = discount value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA502', 'NUMBER_OF_DISCOUNT_CASHLESS1_VENDS_SINCE_LAST_RESET', 
    'Number of Cashless #1 discounted vends given. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DA503', 'VALUE_OF_CASHLESS1_DISCOUNTS_SINCE_INITIALISATION', 
    'Value of Cashless #1 discounts given. (vend price - price paid = discount value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA504', 'NUMBER_OF_DISCOUNT_CASHLESS1_VENDS_SINCE_INITIALISATION', 
    'Number of Cashless #1 discounted vends given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DA505', 'VALUE_OF_CASHLESS1_SURCHARGES_SINCE_LAST_RESET', 
    'Value of Cashless #1 surcharges given. (price paid – vend price = surcharge value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA506', 'NUMBER_OF_SURCHARGE_CASHLESS1_VENDS_SINCE_LAST_RESET', 
    'Number of Cashless #1 surcharge vends given. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DA507', 'VALUE_OF_CASHLESS1_SURCHARGES_SINCE_INITIALISATION', 
    'Value of Cashless #1 surcharges given. (price paid – vend price = surcharge value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA508', 'NUMBER_OF_SURCHARGE_CASHLESS1_VENDS_SINCE_INITIALISATION', 
    'Number of Cashless #1 surcharge vends given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DA601', 'REVALUATION_INCENTIVE_ON_CASHLESS1_SINCE_INITIALISATION', 
    'The value of the additional money added to CASHLESS1_ as an incentive. E.g. $10 cash input, $11 credited to card, Incentive is $1 Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'DA602', 'REVALUATION_INCENTIVE_ON_CASHLESS1_SINCE_LAST_RESET', 
    'The value of the additional money added to CASHLESS1_ as an incentive. E.g. $10 cash input, $11 credited to card, Incentive is $1 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA701', 'CASHLESS1_USER_GROUP_NUMBER', 
    'CASHLESS1_ User group being reported on.', 
    'N0', 1, 13
  ), 
  (
    'DA702', 'CASHLESS1_USER_GROUP_NET_SALES_SINCE_LAST_RESET', 
    'Net sale (equal to the value deducted from the cards) of the user group in DA701 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA703', 'USER_GROUP_VALUE_ADDED_TO_CASHLESS1_SINCE_LAST_RESET', 
    'Revaluation and initialisation (equal to the value added to the cards) of the user group in DA701 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA704', 'CASHLESS1_USER_GROUP_DISCOUNTS_SINCE_LAST_RESET', 
    'Discount deducted from the standard prices (showing up the net sale prices) of the user group in DA701. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA705', 'NUMBER_OF_PRODUCTS_SOLD_TO_CASHLESS1_USER_GROUP_SINCE_INITIALISATION', 
    'This is the number of paid vends from all payment sources of the user group in DA701 since initialisation. Non-resettable.', 
    'N0', 1, 8
  ), 
  (
    'DA706', 'NUMBER_OF_PRODUCTS_SOLD_TO_CASHLESS1_USER_GROUP_SINCE_LAST_RESET', 
    'This is the number of paid vends from all payment sources of the user group in DA701 since last reset. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DA707', 'CASHLESS1_USER_GROUP_NET_SALES_SINCE_INITIALISATION', 
    'Net sale (equal to the value deducted from the cards) of the user group in DA701 Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA708', 'USER_GROUP_VALUE_ADDED_TO_CASHLESS1_SINCE_INITIALISATION', 
    'Revaluation and initialisation (equal to the value added to the cards) of the user group in DA701 Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA709', 'CASHLESS1_USER_GROUP_DISCOUNTS_SINCE_INITIALISATION', 
    'Discount deducted from the standard prices (showing up the net sale prices) of the user group in DA701. Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA801', 'CASHLESS1_FUNDS_USED_FOR_SALE', 
    'This field contains the amount of CASHLESS1_ funds used for the last sale. It is an event-driven field and is intended to be sent after every vend which uses CASHLESS1_ funds.', 
    'Nc', 1, 8
  ), 
  (
    'DA901', 'VALUE_OF_CASHLESS_OVERPAY_SINCE_LAST_RESET', 
    'Value of cashless overpay received. (Inserted cashless value – revalued amount - vend price = overpay value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA902', 'VALUE_OF_CASHLESS_OVERPAY_SINCE_INITIALISATION', 
    'Value of cashless overpay received. (Inserted cashless value – revalued amount - vend price = overpay value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA1001', 'CASHLESS1_NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_INITIALISATION', 
    'The number of vends with cashless 1 where the sale is a mixed paid sale (cash and cashless). Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DA1002', 'CASHLESS1_VALUE_OF_MIXED_PAYMENT_CASHLESS_AMOUNT_SINCE_INITIALISATION', 
    'The value of the cashless amount paid with cashless 1 where the sale is a mixed sale (cash and cashless). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DA1003', 'CASHLESS1_NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_LAST_RESET', 
    'The number of vends with cashless 1 where the sale is a mixed paid sale (cash and cashless).  Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DA1004', 'CASHLESS1_VALUE_OF_MIXED_PAYMENT_CASHLESS_AMOUNT_SINCE_LAST_RESET', 
    'The value of the cashless amount paid with cashless 1 where the sale is a mixed sale (cash and cashless). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB101', 'CASHLESS2_SERIAL_NUMBER', 
    'Identification number of the system (card, key or other). Typically includes a three character supplier ID code from Appendix B (not post manufacturer configurable).', 
    'AN', 1, 20
  ), 
  (
    'DB102', 'CASHLESS2_MODEL_NUMBER', 
    'Model number or description of the system (card, key or other) cashless 2 unit.', 
    'AN', 1, 20
  ), 
  (
    'DB103', 'CASHLESS2_SOFTWARE_REVISION', 
    'Software revision number of the system (card, key or other) cashless 2 unit.', 
    'N0', 1, 4
  ), 
  (
    'DB104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DB105', 'CASHLESS2_ASSET_NUMBER', 
    'Asset number reference for accounting purposes. Separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'DB201', 'VALUE_OF_CASHLESS2_SALES_SINCE_INITIALISATION', 
    'Value of all Cashless #2 sales. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB202', 'NUMBER_OF_CASHLESS2_VENDS_SINCE_INITIALISATION', 
    'Number of all Cashless #2 vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DB203', 'VALUE_OF_CASHLESS2_SALES_SINCE_LAST_RESET', 
    'Value of all Cashless #2 sales. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB204', 'NUMBER_OF_CASHLESS2_VENDS_SINCE_LAST_RESET', 
    'Number of all Cashless #2 vends. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DB205', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DB301', 'VALUE_DEBITED_FROM_CASHLESS2_SINCE_INITIALISATION', 
    'Value debited from Cashless #2. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB302', 'VALUE_DEBITED_FROM_CASHLESS2_SINCE_LAST_RESET', 
    'Value debited from Cashless #2. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB303', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DB401', 'VALUE_CREDITED_TO_CASHLESS2_SINCE_INITIALISATION', 
    'Value credited to Cashless #2. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB402', 'VALUE_CREDITED_TO_CASHLESS2_SINCE_LAST_RESET', 
    'Value credited to Cashless #2. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB403', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'DB501', 'VALUE_OF_CASHLESS2_DISCOUNTS_SINCE_LAST_RESET', 
    'Value of Cashless #2 discounts given. (vend price - price paid = discount value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB502', 'NUMBER_OF_DISCOUNT_CASHLESS2_VENDS_SINCE_LAST_RESET', 
    'Number of Cashless #2 discounted vends given. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DB503', 'VALUE_OF_CASHLESS2_DISCOUNTS_SINCE_INITIALISATION', 
    'Value of Cashless #2 discounts given. (vend price - price paid = discount value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB504', 'NUMBER_OF_DISCOUNT_CASHLESS2_VENDS_SINCE_INITIALISATION', 
    'Number of Cashless #2 discounted vends given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DB505', 'VALUE_OF_CASHLESS2_SURCHARGES_SINCE_LAST_RESET', 
    'Value of Cashless #2 surcharges given. (price paid – vend price = surcharge value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB506', 'NUMBER_OF_SURCHARGE_CASHLESS2_VENDS_SINCE_LAST_RESET', 
    'Number of Cashless #2 surcharge vends given. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DB507', 'VALUE_OF_CASHLESS2_SURCHARGES_SINCE_INITIALISATION', 
    'Value of Cashless #2 surcharges given. (price paid – vend price = surcharge value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB508', 'NUMBER_OF_SURCHARGE_CASHLESS2_VENDS_SINCE_INITIALISATION', 
    'Number of Cashless #2 surcharge vends given. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DB601', 'REVALUATION_INCENTIVE_ON_CASHLESS2_SINCE_INITIALISATION', 
    'The value of the additional money added to Cashless #2 as an incentive. E.g. $10 cash input, $11 credited to card, Incentive is $1 Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'DB602', 'REVALUATION_INCENTIVE_ON_CASHLESS2_SINCE_LAST_RESET', 
    'The value of the additional money added to Cashless #2 as an incentive. E.g. $10 cash input, $11 credited to card, Incentive is $1 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB701', 'CASHLESS2_USER_GROUP_NUMBER', 
    'Cashless #2 User group being reported on.', 
    'N0', 1, 13
  ), 
  (
    'DB702', 'CASHLESS2_USER_GROUP_NET_SALES_SINCE_LAST_RESET.', 
    'Net sale (equal to the value deducted from the cards) of the user group in DB701 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB703', 'USER_GROUP_VALUE_ADDED_TO_CASHLESS2_SINCE_LAST_RESET', 
    'Revaluation and initialisation (equal to the value added to the cards) of the user group in DB701 Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB704', 'CASHLESS2_USER_GROUP_DISCOUNTS_SINCE_LAST_RESET', 
    'Discount deducted from the standard prices (showing up the net sale prices) of the user group in DB701. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB705', 'NUMBER_OF_PRODUCTS_SOLD_TO_CASHLESS2_USER_GROUP_SINCE_INITIALISATION', 
    'This is the number of paid vends from all payment sources of the user group in DB701 since initialisation. Non-resettable.', 
    'N0', 1, 8
  ), 
  (
    'DB706', 'NUMBER_OF_PRODUCTS_SOLD_TO_CASHLESS2_USER_GROUP_SINCE_LAST_RESET', 
    'This is the number of paid vends from all payment sources of the user group in DB701 since last reset. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DB707', 'CASHLESS2_USER_GROUP_NET_SALES_SINCE_INITIALISATION', 
    'Net sale (equal to the value deducted from the cards) of the user group in DB701 Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB708', 'USER_GROUP_VALUE_ADDED_TO_CASHLESS2_SINCE_INITIALISATION', 
    'Revaluation and initialisation (equal to the value added to the cards) of the user group in DB701 Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB709', 'CASHLESS2_USER_GROUP_DISCOUNTS_SINCE_INITIALISATION', 
    'Discount deducted from the standard prices (showing up the net sale prices) of the user group in DB701. Non-resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB801', 'CASHLESS2_FUNDS_USED_FOR_SALE', 
    'This field contains the amount of Cashless #2 funds used for the last sale. It is an event-driven field and is intended to be sent after every vend which uses Cashless #2 funds.', 
    'Nc', 1, 8
  ), 
  (
    'DB1001', 'CASHLESS2_NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_INITIALISATION', 
    'The number of vends with cashless 2 where the sale is a mixed paid sale (cash and cashless). Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'DB1002', 'CASHLESS2_VALUE_OF_MIXED_PAYMENT_CASHLESS_AMOUNT_SINCE_INITIALISATION', 
    'The value of the cashless amount paid with cashless 2 where the sale is a mixed sale (cash and cashless). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DB1003', 'CASHLESS2_NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_LAST_RESET', 
    'The number of vends with cashless 2 where the sale is a mixed paid sale (cash and cashless).  Resettable.', 
    'N0', 1, 6
  ), 
  (
    'DB1004', 'CASHLESS2_VALUE_OF_MIXED_PAYMENT_CASHLESS_AMOUNT_SINCE_LAST_RESET', 
    'The value of the cashless amount paid with cashless 2 where the sale is a mixed sale (cash and cashless). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'DC101', 'CASHLESS1_SERIAL_NUMBER', 
    'Configures field DA101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'DC102', 'CASHLESS1_MODEL_NUMBER', 
    'Configures field DA102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'DC103', 'CASHLESS1_SOFTWARE_REVISION', 
    'Configures field DA103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'DC104', 'USER_DEFINED_FIELD', 'Configures field DA104', 
    'AN', 1, 12
  ), 
  (
    'DC105', 'CASHLESS1_ASSET_NUMBER', 
    'Configures field DA105', 'AN', 
    1, 20
  ), 
  (
    'DD101', 'CASHLESS2_SERIAL_NUMBER', 
    'Configures field DB101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'DD102', 'CASHLESS2_MODEL_NUMBER', 
    'Configures field DB102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'DD103', 'CASHLESS2_SOFTWARE_REVISION', 
    'Configures field DB103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'DD104', 'USER_DEFINED_FIELD', 'Configures field DB104', 
    'AN', 1, 12
  ), 
  (
    'DD105', 'CASHLESS2_ASSET_NUMBER', 
    'Configures field DB105', 'AN', 
    1, 20
  ), 
  (
    'EA101', 'EVENT_IDENTIFICATION', 
    'This field identifies the event being reported in data elements EA102 – EA106.', 
    'AN', 1, 20
  ), 
  (
    'EA102', 'DATE_OF_EVENT_OCCURRENCE', 
    'Date the event occurred.', 'DT', 
    6, 8
  ), 
  (
    'EA103', 'TIME_OF_EVENT_OCCURRENCE', 
    'Time the event occurred.', 'TM', 
    4, 6
  ), 
  (
    'EA104', 'EVENT_DURATION_IN_MINUTES', 
    'How long the event lasted.', 'N0', 
    1, 8
  ), 
  (
    'EA105', 'EVENT_DURATION_IN_MILLISECONDS', 
    'Exactly how long the event lasted.', 
    'N0', 1, 12
  ), 
  (
    'EA106', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA201', 'EVENT_IDENTIFICATION', 
    'This field identifies the event being reported in data elements EA202 – EA204', 
    'AN', 1, 20
  ), 
  (
    'EA202', 'NUMBER_OF_EVENTS_SINCE_LAST_RESET', 
    'Number of times that this event occurred. Resets after each audit data collection.', 
    'N0', 1, 6
  ), 
  (
    'EA203', 'NUMBER_OF_EVENTS_SINCE_INITIALISATION', 
    'Number of times that this event occurred. Non-Resettable.', 
    'N0', 1, 6
  ), 
  (
    'EA204', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA205', 'EVENT_ACTIVITY', 'Indicates the current event activity. (1 = Event Active   /    0 (or empty = Event Inactive', 
    'N0', 1, 1
  ), 
  (
    'EA206', 'EVENT_DURATION_IN_MINUTES', 
    'Duration of the event (including multiple occurrences) in minutes while the event is in State 2 (see EVENT State paragraph in Section 2).', 
    'N0', 1, 8
  ), 
  (
    'EA301', 'NUMBER_OF_READS_WITH_RESET_SINCE_INITIALISATION', 
    'The number of times that the audit unit has been interrogated with reset.  This does not include EVENT resets. RESETs can be automatic after a read, via the SD105 RESET command, partial resets via the SD104 selective RESET command, or manual via a machine service mode. Non-Resettable. Supersedes field CA601', 
    'N0', 1, 8
  ), 
  (
    'EA302', 'DATE_OF_THIS_READ_OUT', 
    'Date of this interrogation.', 
    'DT', 6, 8
  ), 
  (
    'EA303', 'TIME_OF_THIS_READ_OUT', 
    'Time of this interrogation.', 
    'TM', 4, 6
  ), 
  (
    'EA304', 'THIS_TERMINAL_INTERROGATOR_IDENTIFICATION', 
    'The Terminals identification data (see ID201).', 
    'AN', 1, 20
  ), 
  (
    'EA305', 'DATE_OF_LAST_READ_OUT', 
    'Date of the previous interrogation.', 
    'DT', 6, 8
  ), 
  (
    'EA306', 'TIME_OF_LAST_READ_OUT', 
    'Time of the previous interrogation.', 
    'TM', 4, 6
  ), 
  (
    'EA307', 'LAST_TERMINAL_INTERROGATOR_IDENTIFICATION', 
    'The identification data of the terminal that performed the previous interrogation (see ID201).', 
    'AN', 1, 12
  ), 
  (
    'EA308', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA309', 'NUMBER_OF_READS_WITH_OR_WITHOUT_RESET_SINCE_INITIALISATION', 
    'The number of times that the audit unit has been interrogated with or without reset.   Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'EA310', 'NUMBER_OF_RESETS_SINCE_INITIALISATION', 
    'The number of times that the audit unit has been reset.  This does not include EVENT resets. RESETs can be automatic after a read, via the SD105 RESET command, partial resets via the SD104 selective RESET command, or manual via a machine service mode. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'EA401', 'DATE_OF_INITIALISATION', 
    'Date of initialisation  Note: This may be the date of the first interrogation also.', 
    'DT', 6, 8
  ), 
  (
    'EA402', 'TIME_OF_INITIALISATION', 
    'Time of initialisation Note: This may be the time of the first interrogation also.', 
    'TM', 4, 6
  ), 
  (
    'EA403', 'INITIALISATION_TERMINAL_INTERROGATOR_IDENTIFICATION', 
    'The identification data of the terminal that performs the initialisation. (see ID201). Note: This may be the terminal that performs the first read out', 
    'AN', 1, 12
  ), 
  (
    'EA404', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA501', 'DATE_OF_PRICE_SETTING', 
    'Date that the prices were last set.', 
    'DT', 6, 8
  ), 
  (
    'EA502', 'TIME_OF_PRICE_SETTING', 
    'Time that the prices were last set.', 
    'TM', 4, 6
  ), 
  (
    'EA503', 'INTERROGATOR_TERMINAL_IDENTIFICATION', 
    'The identification data of the terminal that set the prices (see ID201).', 
    'AN', 1, 12
  ), 
  (
    'EA504', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA505', 'NUMBER_OF_PRICE_ALTERATIONS', 
    'This reports the number of changes to prices, incrementing by one for every price alteration SINCE_ the last reset (e.g. up & back = +2 on the total). Resettable', 
    'N0', 1, 3
  ), 
  (
    'EA601', 'DATE_OF_MACHINE_SERVICE', 
    'Date of the last time that the machine was serviced. (cleaning, adjustment, repair)', 
    'DT', 6, 8
  ), 
  (
    'EA602', 'TIME_OF_MACHINE_SERVICE', 
    'Time of the last time that the machine was serviced (cleaning, adjustment, repair)', 
    'TM', 4, 6
  ), 
  (
    'EA603', 'INTERROGATOR_TERMINAL_IDENTIFICATION', 
    'The identification data of the terminal that was involved in the servicing. (see ID201).', 
    'AN', 1, 12
  ), 
  (
    'EA604', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA701', 'NUMBER_OF_POWER_OUTAGES_SINCE_LAST_RESET', 
    'Total number of power down - up cycles recorded by the audit unit. Supersedes CA501. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'EA702', 'NUMBER_OF_POWER_OUTAGES_SINCE_INITIALISATION', 
    'Total number of power down - up cycles recorded by the audit unit. Supersedes CA502 Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'EA801', 'REPEATING_EVENT_IDENTIFICATION', 
    'Identifies what repeating event has been set.', 
    'AN', 1, 20
  ), 
  (
    'EA802', 'DAY_OF_REPEATING_EVENT_OCCURRENCE', 
    'Reports the day that the event will occur. This will be of the form Day of Week, Weekday, Weekend, having values 1-7, 8, 9 respectively. Monday = 1.', 
    'AN', 1, 2
  ), 
  (
    'EA803', 'HOUR_OF_REPEATING_EVENT_OCCURRENCE', 
    'Reports the hour that the event will occur, in hours timed from midnight. (24 Hour Clock)', 
    'N0', 1, 2
  ), 
  (
    'EA804', 'MINUTE_OF_REPEATING_EVENT_OCCURRENCE', 
    'Reports the start time in minutes from midnight that the event will occur.', 
    'N0', 1, 4
  ), 
  (
    'EA805', 'MILLISECOND_OF_REPEATING_EVET_OCCURRENCE', 
    'Reports the start time in milliseconds from midnight that the event will occur.', 
    'N0', 1, 12
  ), 
  (
    'EA806', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EA901', 'MACHINE_HOURS_SINCE_INITIALISATION', 
    'Number of machine hours since initiatilization.', 
    'N0', 1, 6
  ), 
  (
    'EA902', 'TOTAL_NUMBER_OF_PRODUCTS_DISPENSED_SINCE_INITIALISATION', 
    'Total number of products dispensed since initialisation.', 
    'N0', 1, 8
  ), 
  (
    'EA903', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'EC806', 'USER_DEFINED_FIELD', 'Configures field EA806', 
    'AN', 1, 12
  ), 
  (
    'HA101', 'HOPPER_SERIAL_NUMBER', 
    'Identification number of the hopper/dispenser mechanism. This number may only be set by the Manufacturer. Typically includes a three character supplier ID code from Appendix B. Programmed at factory, not user changeable. HA1 block is optional. If any HA1 data is transmitted, then HA101 becomes mandatory.', 
    'AN', 1, 20
  ), 
  (
    'HA102', 'HOPPER_MODEL', 'NumberModel number or description of the hopper/dispenser', 
    'AN', 1, 20
  ), 
  (
    'HA103', 'HOPPER_SOFTWARE_REVISION', 
    'Software revision number of the hopper/dispenser', 
    'N0', 1, 4
  ), 
  (
    'HA104', 'USER_DEFINED_FIELD', 'User defined data', 
    'AN', 1, 12
  ), 
  (
    'HA105', 'HOPPER_ASSET_NUMBER', 'Asset number refence for accounting pruposes. Separate from serial number', 
    'AN', 1, 20
  ), 
  (
    'HA201', 'VALUE_OF_CASH_IN_SINCE_LAST_RESET', 
    'Value of CASH_ filled in. Includes cash filled in by a mechanism during sales (e. g. coin validator) and cash filled in manually. Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HA202', 'VALUE_OF_CASH_FILLED_SINCE_LAST_RESET', 
    'Value of CASH_ manually added to the hopper/dispenser (manually filled and fill mode) Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HA203', 'VALUE_OF_CASH_IN_SINCE_INITIALISATION', 
    'Value of CASH_ filled in. Includes cash filled in by a mechanism during sales (e. g. coin validator) and cash filled in manually. Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HA204', 'VALUE_OF_CASH_FILLED_SINCE_INITIALISATION', 
    'Value of CASH_ manually added to the hopper/dispenser (manually filled and fill mode) Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HA301', 'VALUE_OF_CASH_DISPENSED_SINCE_LAST_RESET', 
    'Value paid out as change plus the value manually dispensed. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'HA302', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Value dispensed manually. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'HA303', 'VALUE_OF_CASH_DISPENSED_SINCE_INITIALISATION', 
    'Value paid out as change plus the value manually dispensed Non-Resattable', 
    'Nc', 1, 8
  ), 
  (
    'HA304', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Value dispensed manually Non-Resattable', 
    'Nc', 1, 8
  ), 
  (
    'HA401', 'VALUE_OF_HOPPER_CONTENTS', 
    'Value of cash stored in all hopper/dispenser containers of the hopper/dispenser', 
    'Nc', 1, 8
  ), 
  (
    'HA402', 'BLOCK1_COIN_BILL_TYPE0_7_BLOCK2_COIN_BILL_TYPE8_15', 
    'A “1” indicates HA403 to HA410 refers to  coin/bill Type 0 – 7 A “2” indicates HA403 to HA410 refers to  coin/bill Type 8 – 15', 
    'N0', 1, 1
  ), 
  (
    'HA403', 'COIN_BILL_TYPE_0_OR_8', 
    'Number of coins/bills in container coin/bill type 0 or 8', 
    'N0', 1, 3
  ), 
  (
    'HA404', 'COIN_BILL_TYPE_1_OR_9', 
    'Number of coins/bills in container coin/bill type 1 or 9', 
    'N0', 1, 3
  ), 
  (
    'HA405', 'COIN_BILL_TYPE_2_OR_10', 
    'Number of coins/bills in container coin/bill type 2 or 10', 
    'N0', 1, 3
  ), 
  (
    'HA406', 'COIN_BILL_TYPE_3_OR_11', 
    'Number of coins/bills in container coin/bill type 3 or 11', 
    'N0', 1, 3
  ), 
  (
    'HA407', 'COIN_BILL_TYPE_4_OR_12', 
    'Number of coins/bills in container coin/bill type 4 or 12', 
    'N0', 1, 3
  ), 
  (
    'HA408', 'COIN_BILL_TYPE_5_OR_13', 
    'Number of coins/bills in container coin/bill type 5 or 13', 
    'N0', 1, 3
  ), 
  (
    'HA409', 'COIN_BILL_TYPE_6_OR_14', 
    'Number of coins/bills in container coin/bill type 6 or 14', 
    'N0', 1, 3
  ), 
  (
    'HA410', 'COIN_BILL_TYPE_7_OR_15', 
    'Number of coins/bills in container coin/bill type 7 or 15', 
    'N0', 1, 3
  ), 
  (
    'HB101', 'HOPPER_SERIAL_NUMBER', 
    'Identification number of the hopper/dispenser mechanism. This number may only be set by the Manufacturer. Typically includes a three character supplier ID code from Appendix B. Programmed at factory, not user changeable. HB1 block is optional. If any HB1 data is transmitted, then HB101 becomes mandatory.', 
    'AN', 1, 20
  ), 
  (
    'HB102', 'HOPPER_DISPENSER_MODEL_NUMBER', 
    'Model number or description of the hopper/dispenser', 
    'AN', 1, 20
  ), 
  (
    'HB103', 'HOPPER_DISPENSER_SOFTWARE_REVISION', 
    'Software revision number of the hopper/dispenser', 
    'N0', 1, 4
  ), 
  (
    'HB104', 'USER_DEFINED_FIELD', 'User defined data', 
    'AN', 1, 12
  ), 
  (
    'HB105', 'HOPPER_ASSET_NUMBER', 'Asset number refence for accounting pruposes. Separate from serial number', 
    'AN', 1, 20
  ), 
  (
    'HB201', 'VALUE_OF_CASH_IN_SINCE_LAST_RESET', 
    'Value of cash filled in. Includes cash filled in by a mechanism during sales (e. g. coin validator) and cash filled in manually. Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HB202', 'VALUE_OF_CASH_FILLED_SINCE_LAST_RESET', 
    'Value of cash manually added to the hopper/dispenser (manually filled and fill mode) Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HB203', 'VALUE_OF_CASH_IN_SINCE_INITIALISATION', 
    'Value of cash filled in. Includes cash filled in by a mechanism during sales (e. g. coin validator) and cash filled in manually. Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HB204', 'VALUE_OF_CASH_FILLED_SINCE_INITIALISATION', 
    'Value of cash manually added to the hopper/dispenser (manually filled and fill mode) Non-Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HB301', 'VALUE_OF_CASH_DISPENSED_SINCE_LAST_RESET', 
    'Value paid out as change plus the value manually dispensed Resettable', 
    'Nc', 1, 8
  ), 
  (
    'HB302', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Value dispensed manually. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'HB303', 'VALUE_OF_CASH_DISPENSED_SINCE_INITIALISATION', 
    'Value paid out as change plus the value manually dispensed Non-Resattable', 
    'Nc', 1, 8
  ), 
  (
    'HB304', 'VALUE_OF_CASH_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Value dispensed manually Non-Resattable', 
    'Nc', 1, 8
  ), 
  (
    'HB401', 'VALUE_OF_HOPPER_CONTENTS', 
    'Value of cash stored in all hopper/dispenser containers of the hopper/dispenser', 
    'Nc', 1, 8
  ), 
  (
    'HB402', 'BLOCK1_COIN_BILL_TYPE0_7_BLOCK2_COIN_BILL_TYPE8_15', 
    'A “1” indicates HB403 to HB410 refers to  Coin/bill Type 0 – 7 A “2” indicates HB403 to HB410 refers to  Coin/bill Type 8 - 15', 
    'N0', 1, 1
  ), 
  (
    'HB403', 'COIN_BILL_TYPE_0_OR_8', 
    'Number of coins/bills in container coin/bill type 0 or 8', 
    'N0', 1, 3
  ), 
  (
    'HB404', 'COIN_BILL_TYPE_1_OR_9', 
    'Number of coins/bills in container coin/bill type 1 or 9', 
    'N0', 1, 3
  ), 
  (
    'HB405', 'COIN_BILL_TYPE_2_OR_10', 
    'Number of coins/bills in container coin/bill type 2 or 10', 
    'N0', 1, 3
  ), 
  (
    'HB406', 'COIN_BILL_TYPE_3_OR_11', 
    'Number of coins/bills in container coin/bill type 3 or 11', 
    'N0', 1, 3
  ), 
  (
    'HB407', 'COIN_BILL_TYPE_4_OR_12', 
    'Number of coins/bills in container coin/bill type 4 or 12', 
    'N0', 1, 3
  ), 
  (
    'HB408', 'COIN_BILL_TYPE_5_OR_13', 
    'Number of coins/bills in container coin/bill type 5 or 13', 
    'N0', 1, 3
  ), 
  (
    'HB409', 'COIN_BILL_TYPE_6_OR_14', 
    'Number of coins/bills in container coin/bill type 6 or 14', 
    'N0', 1, 3
  ), 
  (
    'HB410', 'COIN_BILL_TYPE_7_OR_15', 
    'Number of coins/bills in container coin/bill type 7 or 15', 
    'N0', 1, 3
  ), 
  (
    'HC101', 'HOPPER_SERIAL_NUMBER', 
    'Configures field HA101 (NOT FIELD CONFIGURABLE)', 
    'AN', 1, 20
  ), 
  (
    'HC102', 'HOPPER_MODEL_NUMBER', 'Configures field HA102  (NOT FIELD CONFIGURABLE)', 
    'AN', 1, 20
  ), 
  (
    'HC103', 'HOPPER_DISPENSER_SOFTWARE_REVISION', 
    'Configures field HA103  (NOT FIELD CONFIGURABLE)', 
    'N0', 1, 4
  ), 
  (
    'HC104', 'USER_DEFINED_FIELD', 'Configures field HA104', 
    'AN', 1, 12
  ), 
  (
    'HC105', 'HOPPER_ASSET_NUMBER', 'Configures field HA105', 
    'AN', 1, 20
  ), 
  (
    'HD101', 'HOPPER_SERIAL_NUMBER', 
    'Configures field HB101 (NOT FIELD CONFIGURABLE)', 
    'AN', 1, 20
  ), 
  (
    'HD102', 'HOPPER_MODEL_NUMBER', 'Configures field HB102  (NOT FIELD CONFIGURABLE)', 
    'AN', 1, 20
  ), 
  (
    'HD103', 'HOPPER_SOFTWARE_REVISION', 
    'Configures field HB103  (NOT FIELD CONFIGURABLE)', 
    'N0', 1, 4
  ), 
  (
    'HD104', 'USER_DEFINED_FIELD', 'Configures field HB104', 
    'AN', 1, 12
  ), 
  (
    'HD105', 'HOPPER_ASSET_NUMBER', 'Configures field HB105', 
    'AN', 1, 20
  ), 
  (
    'IC101', 'MACHINE_SERIAL_NUMBER', 
    'Configures field ID101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC102', 'MACHINE_MODEL_NUMBER', 
    'Configures field ID102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC103', 'MACHINE_BUILD_STANDARD', 
    'Configures field ID103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'IC104', 'MACHINE_LOCATION', 'Configures field ID104', 
    'AN', 1, 30
  ), 
  (
    'IC105', 'USER_DEFINED_FIELD', 'Configures field ID105', 
    'AN', 1, 12
  ), 
  (
    'IC106', 'MACHINE_ASSET_NUMBER', 
    'Configures field ID106', 'AN', 
    1, 20
  ), 
  (
    'IC201', 'DATA_CARRIER_SERIAL_NUMBER', 
    'Configures field ID201 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC202', 'DATA_CARRIER_MODEL_NUMBER', 
    'Configures field ID202 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC203', 'DATA_CARRIER_SOFTWARE_REVISION', 
    'Configures field ID203 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'IC204', 'USER_DEFINED_FIELD', 'Configures field ID204', 
    'AN', 1, 12
  ), 
  (
    'IC205', 'DATA_CARRIER_ASSET_NUMBER', 
    'Configures field ID205', 'AN', 
    1, 20
  ), 
  (
    'IC301', 'ROUTE_NUMBER', 'Configures field ID301', 
    'AN', 1, 12
  ), 
  (
    'IC302', 'USER_FUNCTION', 'Configures field ID302', 
    'AN', 1, 20
  ), 
  (
    'IC303', 'ROUTE_PERSON_NAME', 'Configures field ID303', 
    'AN', 1, 20
  ), 
  (
    'IC304', 'USER_DEFINED_FIELD', 'Configures field ID304', 
    'AN', 1, 12
  ), 
  (
    'IC401', 'DECIMAL_POINT_POSITION', 
    'Configures field ID401', 'N0', 
    1, 1
  ), 
  (
    'IC402', 'COUNTRY_CODE', 'Configures field ID402', 
    'N0', 1, 3
  ), 
  (
    'IC403', 'CURRENCY_DESCRIPTION', 
    'Configures field ID403', 'AN', 
    1, 8
  ), 
  (
    'IC501', 'SYSTEM_DATE', 'Configures field ID501', 
    'DT', 6, 8
  ), 
  (
    'IC502', 'SYSTEM_TIME', 'Configures field ID502', 
    'TM', 4, 6
  ), 
  (
    'IC503', 'SYSTEM_TIME_IN_SECONDS', 
    'Configures field ID503', 'N0', 
    1, 2
  ), 
  (
    'IC504', 'SYSTEM_DAYLIGHT_SAVINGS_MODE', 
    'Configures the current status of daylight savings mode. OFF = Off  (no daylight savings mode) NA = North American rules   EU = European rules   AUS = Australian rules', 
    'AN', 2, 3
  ), 
  (
    'IC601', 'CURRENT_CASH_BAG_NUMBER', 
    'Configures ID601', 'AN', 1, 20
  ), 
  (
    'IC701', 'PAYMENT_SYSTEM_INDEX', 
    'Configures field ID701', 'AN', 
    1, 6
  ), 
  (
    'IC702', 'PAYMENT_SYSTEM_CATEGORY', 
    'Configures field ID702', 'AN', 
    1, 4
  ), 
  (
    'IC703', 'MANUFACTURER_CODE', 'Configures field ID703', 
    'AN', 1, 20
  ), 
  (
    'IC704', 'SERIAL_NUMBER', 'Configures field ID704 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC705', 'MODEL', 'Configures field ID705 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC706', 'SOFTWARE_REVISION', 'Configures field ID706 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'IC707', 'STATUS', 'Configures field ID707', 
    'N0', 1, 10
  ), 
  (
    'IC708', 'USER_DEFINED_FIELD', 'Configures field ID708', 
    'AN', 1, 12
  ), 
  (
    'ID101', 'MACHINE_SERIAL_NUMBER', 
    'Machine identification number. Possibly the ID of the VMD. It should include a three character supplier ID code from Appendix B.', 
    'AN', 1, 20
  ), 
  (
    'ID102', 'MACHINE_MODEL_NUMBER', 
    'Machine model number or description.', 
    'AN', 1, 20
  ), 
  (
    'ID103', 'MACHINE_BUILD_STANDARD', 
    'This element describes the build standard of the machine. It may be the Audit Unit or Vending Machine Controller software revision number.', 
    'N0', 1, 4
  ), 
  (
    'ID104', 'MACHINE_LOCATION', 'Description of the machine location. May be e.g. “1st floor by the lift”.', 
    'AN', 1, 30
  ), 
  (
    'ID105', 'USER_DEFINED_FIELD', 'The meaning of this field is dependent on the specific device or category it is associated with. Typically the block type and machine identification will indicate the specific data.', 
    'AN', 1, 12
  ), 
  (
    'ID106', 'MACHINE_ASSET_NUMBER', 
    'Unique number which operator can enter for accounting purposes (see Chapter 5)', 
    'AN', 1, 20
  ), 
  (
    'ID107', 'DTS_LEVEL', 'Specifies level number of the DTS Standard e.g. level 6 for DTS version 6.0.', 
    'N0', 1, 2
  ), 
  (
    'ID108', 'DTS_REVISION', 'Specifies any revision to the main DTS level e.g. revision 1 for potential DTS version 6.1.', 
    'N0', 1, 4
  ), 
  (
    'ID201', 'DATA_CARRIER_SERIAL_NUMBER', 
    'Terminal or data carrier identification number. This is a User defined number.', 
    'AN', 1, 20
  ), 
  (
    'ID202', 'DATA_CARRIER_MODEL_NUMBER', 
    'Terminal or data carrier model number or description.', 
    'AN', 1, 20
  ), 
  (
    'ID203', 'DATA_CARRIER_SOFTWARE_REVISION', 
    'Terminal or data carrier software revision number.', 
    'N0', 1, 4
  ), 
  (
    'ID204', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'ID205', 'DATA_CARRIER_ASSET_NUMBER', 
    'Data Carrier Asset Number reference for accounting purposes. This is separate from serial number.', 
    'AN', 1, 20
  ), 
  (
    'ID301', 'ROUTE_NUMBER', 'Route number or description.', 
    'AN', 1, 12
  ), 
  (
    'ID302', 'USER_FUNCTION', 'Route function being performed. (Audit, Service, Supervisor, etc.)', 
    'AN', 1, 20
  ), 
  (
    'ID303', 'ROUTE_PERSON_NAME', 'Name of the route person under ID302.', 
    'AN', 1, 20
  ), 
  (
    'ID304', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'ID401', 'DECIMAL_POINT_POSITION', 
    'This field is used in countries whose currency requires a number of digits to the right of the decimal point other than 2.This information is typically reported to the VMC by the peripheral(s).', 
    'N0', 1, 1
  ), 
  (
    'ID402', 'NUMERIC_CURRENCY_CODE', 
    'Currency identification by International Telephone Country Code or ISO 4217 numeric currency code. All new designs after July, 2000 must use the ISO 4217 numeric currency codes. If the left most digit is a 0, the International Telephone Code is used to indicate the currency. For example, the USA code is 0001. If the left most digit is a 1, the latest version of the ISO 4217 numeric currency code is used. For example, the code for the US dollar is 1840 and the Euro is 1978.', 
    'N0', 4, 4
  ), 
  (
    'ID403', 'ALPHABETIC_CURRENCY_CODE', 
    'This alpha-numeric field is used to define or describe the currency in use. Typically it is the ISO 4217 alphabetic currency code.', 
    'AN', 3, 3
  ), 
  (
    'ID501', 'SYSTEM_DATE', 'Reports the machine Date.', 
    'DT', 6, 8
  ), 
  (
    'ID502', 'SYSTEM_TIME', 'Reports the machine Time.', 
    'TM', 4, 6
  ), 
  (
    'ID503', 'SYSTEM_TIME_SECONDS', 'Reports the machine Time Seconds if ID502 is reported in the Hour Minute (HHMM) order. Used to report seconds to the interrogating device. Note that the interrogating device may use IC503 to update the time and thus keep the system synchronised.', 
    'N0', 1, 2
  ), 
  (
    'ID504', 'SYSTEM_DAYLIGHT_SAVINGS_MODE', 
    'Reports the current status of daylight savings mode. OFF = Off  (no daylight savings mode) NA = North American rules   EU = European rules   AUS = Australian rules', 
    'AN', 2, 3
  ), 
  (
    'ID601', 'CASH_BAG_NUMBER', 'This is the identification of the cash bag or box containing the money removed from the machine by the route person or service engineer.', 
    'AN', 1, 20
  ), 
  (
    'ID701', 'PAYMENT_SYSTEM_INDEX', 
    'Defines the number of the payment system (beginning with 1) for which the following values are valid. Several payment systems are possible.', 
    'AN', 1, 6
  ), 
  (
    'ID702', 'PAYMET_SYSTEM_CATEGORY', 
    'Defines the category of payment systems: 0: Coin mech., 1: Coin changer, 2: Token acceptor, 10: Magnetic card system, 11: Chipcard system, 12: Contactless card system, 20: Contact Key system, 21: Contactless Key system, 30: Bill Validator.', 
    'AN', 1, 4
  ), 
  (
    'ID703', 'MANUFACTURER_CODE', 'Manufacturer code of the payment system.', 
    'AN', 1, 20
  ), 
  (
    'ID704', 'SERIAL_NUMBER', 'Serial number of the payment system', 
    'AN', 1, 20
  ), 
  (
    'ID705', 'MODEL', 'Model number of the payment system', 
    'AN', 1, 20
  ), 
  (
    'ID706', 'SOFTWARE_REVISION', 'Software revision of the payment system', 
    'AN', 1, 20
  ), 
  (
    'ID707', 'STATUS', 'Status of payment system: (the right most bit will be sent first) 1. digit: 0 = disabled 1 = enabled 2. digit: revalue enabled 3. digit: Singlevend/Multivend', 
    'N0', 1, 10
  ), 
  (
    'ID708', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'LA101', 'PRICE_LIST_NUMBER', 'Defines the list number for which the following values are valid. Several Lists possible, to set different prices for each product.', 
    'N0', 1, 1
  ), 
  (
    'LA102', 'PRODUCT_NUMBER', 'Equal to the product no. defined in PA101', 
    'AN', 1, 6
  ), 
  (
    'LA103', 'PRICE', 'Product price valid for this list number. (If no price is defined for a product number, the price defined in PA102 is to be used).', 
    'Nc', 1, 8
  ), 
  (
    'LA104', 'NUMBER_OF_VENDS_SINCE_LAST_RESET', 
    'Number of vends of the product on this price list. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'LA105', 'NUMBER_OF_VENDS_SINCE_INITIALISATION', 
    'Number of vends of the product on this price list. Non-Resettable', 
    'N0', 1, 8
  ), 
  (
    'LC101', 'PRICE_LIST_NUMBER', 'Configures field LA101', 
    'N0', 1, 1
  ), 
  (
    'LC102', 'PRODUCT_NUMBER', 'Configures field LA102', 
    'AN', 1, 6
  ), 
  (
    'LC103', 'PRICE', 'Configures field LA103', 
    'Nc', 1, 8
  ), 
  (
    'MA101', 'MACHINE_SERIAL_NUMBER', 
    'Serial number of the machine reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA102', 'SINGLE_VEND_MULTI_VEND', 
    'Status of single vs. multi vend.', 
    'AN', 1, 20
  ), 
  (
    'MA201', 'MACHINE_SERIAL_NUMBER', 
    'Serial number of the machine reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA202', 'VMC_IDENTITY_SERIAL_NUMBER', 
    'Serial number of the vending machine controller reporting status and configuration data', 
    'AN', 1, 20
  ), 
  (
    'MA301', 'MACHINE_SERIAL_NUMBER', 
    'Serial number of the machine reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA302', 'COIN_MECH_IDENTITY', 'Serial number of the coin mechanism reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA401', 'MACHINE_SERIAL_NUMBER', 
    'Serial number of the machine reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA402', 'DEBIT_CARD_IDENTITY_SERIAL_NUMBER', 
    'Serial number of the debit card system reporting status and configuration data.', 
    'AN', 1, 20
  ), 
  (
    'MA403', 'PRICE_LIST_NUMBER', 'Identifies the price list whose card discount is reported.', 
    'N0', 1, 1
  ), 
  (
    'MA404', 'CARD_DISCOUNT', 'The discount in percent of the standard price.', 
    'N0', 1, 2
  ), 
  (
    'MA405', 'CARD_SURCHARGE', 'Surcharge in %', 
    'N0', 1, 2
  ), 
  (
    'MA501', 'BLOCK_IDENTIFIER', 'Sequential block number used for stringing multiple MA5 blocks together. This field should read LAST on the last block in the sequence. MA5 blocks are used together with MA2, MA3 and MA4.', 
    'AN', 1, 12
  ), 
  (
    'MA502', 'SPECIFIC_CONFIGURATION_DATA', 
    'This block contains the specific data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 100
  ), 
  (
    'MA503', 'OPTIONAL_FIELD_2', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA504', 'OPTIONAL_FIELD_3', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA505', 'OPTIONAL_FIELD_4', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA506', 'OPTIONAL_FIELD_5', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA507', 'OPTIONAL_FIELD_6', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA508', 'OPTIONAL_FIELD_7', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA509', 'OPTIONAL_FIELD_8', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA510', 'OPTIONAL_FIELD_9', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA511', 'OPTIONAL_FIELD_10', 'This block contains additional configuration data coming from the device addressed by the preceding MA2 or MA3 or MA4 block.', 
    'AN', 1, 12
  ), 
  (
    'MA601', 'PRODUCT_IDENTIFIER', 'No Description', 
    'AN', 1, 6
  ), 
  (
    'MA602', 'WATER_QUANTITY', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA603', 'WATER_QUANTITY_COLD', 'No Description', 
    'NO', 1, 6
  ), 
  (
    'MA604', 'WATER_QUANTITY', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA605', 'WATER_QUANTITY_SHORT', 
    'No Description', 'N0', 1, 6
  ), 
  (
    'MA606', 'WATER_QUANTITY_CLEANING_PROCEDURE', 
    'No Description', 'N0', 1, 6
  ), 
  (
    'MA607', 'PRODUCT_QUANTITY', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA608', 'START_TIME_PRODUCT', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA701', 'PRODUCT_NUMBER', 'No Description', 
    'AN', 1, 6
  ), 
  (
    'MA702', 'SYRUP_QUANTITY_SMALL', 
    'No Description', 'N0', 1, 6
  ), 
  (
    'MA703', 'SYRUP_QUANTITY_BIG', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA704', 'SODA_WATER_QUANTITY_SMALL', 
    'No Description', 'N0', 1, 6
  ), 
  (
    'MA705', 'SODA_WATER_QUANTITY_BIG', 
    'No Description', 'N0', 1, 6
  ), 
  (
    'MA706', 'WATER_QUANTITY', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA707', 'START_TIME_PRODUCT', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA801', 'SHELF_NUMBER', 'No Description', 
    'AN', 1, 6
  ), 
  (
    'MA802', 'SHELF_LOCK_STATUS', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA803', 'DEPOSIT', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MA901', 'SHELF_NUMBER', 'No Description', 
    'AN', 1, 6
  ), 
  (
    'MA902', 'SHELF_STATUS', 'No Description', 
    'N0', 1, 6
  ), 
  (
    'MC101', 'MACHINE_SERIAL_NUMBER', 
    'Configures field', 'AN', 1, 20
  ), 
  (
    'MC102', 'SINGLE_VEND_MULTI_VEND', 
    'Configures field', 'AN', 1, 20
  ), 
  (
    'MC201', 'MACHINE_SERIAL_NUMBER', 
    'Configures field', 'AN', 1, 20
  ), 
  (
    'MC202', 'VMC_IDENTITY_SERIAL_NUMBER', 
    'Configures field MA202', 'AN', 
    1, 20
  ), 
  (
    'MC301', 'MACHINE_SERIAL_NUMBER', 
    'Configures field MA301', 'AN', 
    1, 20
  ), 
  (
    'MC302', 'COIN_MECH_IDENTITY_SERIAL_NUMBER', 
    'Configures field MA302', 'AN', 
    1, 20
  ), 
  (
    'MC401', 'MACHINE_SERIAL_NUMBER', 
    'Configures field MA401', 'AN', 
    1, 20
  ), 
  (
    'MC402', 'DEBIT_CARDD_IDENTITY_SERIAL_NUMBER', 
    'Configures field MA402', 'AN', 
    1, 20
  ), 
  (
    'MC403', 'PRICE_LIST_NUMBER', 'Configures field MA403', 
    'N0', 1, 1
  ), 
  (
    'MC404', 'CARD_DISCOUNT', 'Configures field MA404', 
    'N0', 1, 2
  ), 
  (
    'MC405', 'CARD_SURCHARGE', 'Surcharge in %', 
    'N0', 1, 2
  ), 
  (
    'MC501', 'BLOCK_IDENTIFIER', 'Configures field MA501', 
    'AN', 1, 12
  ), 
  (
    'MC502', 'SPECIFIC_CONFIGURATION_DATA', 
    'Configures field MA502', 'AN', 
    1, 100
  ), 
  (
    'MC503', 'OPTIONAL_FIELD_2', 'Configures field MA503', 
    'AN', 1, 12
  ), 
  (
    'MC504', 'OPTIONAL_FIELD_3', 'Configures field MA504', 
    'AN', 1, 12
  ), 
  (
    'MC505', 'OPTIONAL_FIELD_4', 'Configures field MA505', 
    'AN', 1, 12
  ), 
  (
    'MC506', 'OPTIONAL_FIELD_5', 'Configures field MA506', 
    'AN', 1, 12
  ), 
  (
    'MC507', 'OPTIONAL_FIELD_6', 'Configures field MA507', 
    'AN', 1, 12
  ), 
  (
    'MC508', 'OPTIONAL_FIELD_7', 'Configures field MA508', 
    'AN', 1, 12
  ), 
  (
    'MC509', 'OPTIONAL_FIELD_8', 'Configures field MA509', 
    'AN', 1, 12
  ), 
  (
    'MC510', 'OPTIONAL_FIELD_9', 'Configures field MA510', 
    'AN', 1, 12
  ), 
  (
    'MC511', 'OPTIONAL_FIELD_10', 'Configures field MA511', 
    'AN', 1, 12
  ), 
  (
    'MC601', 'PRODUCT_IDENTIFIER', 'Configures field MA601', 
    'AN', 1, 6
  ), 
  (
    'MC602', 'WATER_QUANTITY', 'Configures field MA602', 
    'N0', 1, 6
  ), 
  (
    'MC603', 'WATER_QUANTITY_COLD', 'Configures field MA603', 
    'N0', 1, 6
  ), 
  (
    'MC604', 'WATER_QUANTITY', 'Configures field MA604', 
    'N0', 1, 6
  ), 
  (
    'MC605', 'WATER_QUANTITY_SHORT', 
    'Configures field MA605', 'N0', 
    1, 6
  ), 
  (
    'MC606', 'WATER_QUANTITY_CLEANING_PROCEDURE', 
    'Configures field MA606', 'N0', 
    1, 6
  ), 
  (
    'MC607', 'PRODUCT_QUANTITY', 'Configures field MA607', 
    'N0', 1, 6
  ), 
  (
    'MC608', 'START_TIME_PRODUCT', 'Configures field MA608', 
    'N0', 1, 6
  ), 
  (
    'MC701', 'PRODUCT_IDENTIFIER', 'Configures field MA701', 
    'AN', 1, 6
  ), 
  (
    'MC702', 'SYRUP_QUANTITY_SMALL', 
    'Configures field MA702', 'N0', 
    1, 6
  ), 
  (
    'MC703', 'SYRUP_QUANTITY_BIG', 'Configures field MA703', 
    'N0', 1, 6
  ), 
  (
    'MC704', 'SODA_WATER_QUANTITY_SMALL', 
    'Configures field MA704', 'N0', 
    1, 6
  ), 
  (
    'MC705', 'SODA_WATER_QUANTITY_BIG', 
    'Configures field MA705', 'N0', 
    1, 6
  ), 
  (
    'MC706', 'WATER_QUANTITY', 'Configures field MA706', 
    'N0', 1, 6
  ), 
  (
    'MC707', 'START_TIME_PRODUCT', 'Configures field MA707', 
    'N0', 1, 6
  ), 
  (
    'MC801', 'SHELF_IDENTIFIER', 'Configures field MA801', 
    'AN', 1, 6
  ), 
  (
    'MC802', 'SHELF_LOCK_STATUS', 'Configures field MA802', 
    'N0', 1, 6
  ), 
  (
    'MC803', 'DEPOSIT', 'Configures field MA803', 
    'N0', 1, 6
  ), 
  (
    'MC901', 'SHELF_IDENTIFIER', 'Configures field MA901', 
    'AN', 1, 6
  ), 
  (
    'MC902', 'SHELF_STATUS', 'Configures field MA902', 
    'N0', 1, 6
  ), 
  (
    'MR101', 'METER_READ_NUMBER_OF_VENDS_SINCE_INITIALISATION', 
    'This value is the meter reading of the total number of vends by the machine, including paid, free and test vends. It is recorded by the route person using a Data Carrier. Non Resettable', 
    'N0', 1, 8
  ), 
  (
    'MR102', 'METER_READ_NUMBER_OF_ALL_PAID_VENDS_SINCE_INITIALISATION', 
    'This value is the meter reading of the total number of paid vends by the machine. It is recorded by the route person using a Data Carrier. Non Resettable', 
    'N0', 1, 8
  ), 
  (
    'MR103', 'METER_READ_NUMBER_OF_FREE_VENDS_SINCE_INITIALISATION', 
    'This value is the meter reading of the total number of free vends by the machine. It is recorded by the route person using a Data Carrier. Non Resettable', 
    'N0', 1, 8
  ), 
  (
    'MR104', 'METER_READ_NUMBER_OF_TEST_VENDS_SINCE_LAST_RESET', 
    'This value is the meter reading of the total number of test vends by the machine since the last reset. It is recorded by the route person using a Data Carrier. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'MR105', 'METER_READ_NUMBER_OF_TEST_VENDS_SINCE_INITIALISATION', 
    'This value is the meter reading of the total number of test vends by the machine. It is recorded by the route person using a Data Carrier. Non Resettable', 
    'N0', 1, 8
  ), 
  (
    'MR201', 'METERED_PRODUCT_IDENTIFIER', 
    'This value is the product / column number of the meter recording individual product sales. It is recorded by the route person using a Data Carrier.', 
    'AN', 1, 6
  ), 
  (
    'MR202', 'METER_READ_NUMBER_OF_VENDS_FOR_ONE_PRODUCT_SINCE_INITIALISATION', 
    'This value is the number of vends for a single product whose number is given by MR201. It is recorded by the route person using a Data Carrier. Non Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA101', 'PRODUCT_IDENTIFIER', 'Identifies product to be audited by PA102-PA503. The product (i.e. selection) number should refer to a price line number or machine column designator. This number is defined by the manufacturer.', 
    'AN', 1, 6
  ), 
  (
    'PA102', 'PRODUCT_PRICE', 'The normal vend price of the product.', 
    'Nc', 1, 8
  ), 
  (
    'PA103', 'PRODUCT_IDENTIFICATION', 
    'Product identification should identify the product itself, as in a name (chips / crisps) or an ID number (barcode).', 
    'AN', 1, 20
  ), 
  (
    'PA104', 'MAXIMUM_PRODUCT_CAPACITY', 
    'Largest quantity of this type of product that can be stocked in the machine.', 
    'N0', 1, 4
  ), 
  (
    'PA105', 'STANDARD_FILLING_LEVEL', 
    'Normal filling level of this type of product.', 
    'N0', 1, 4
  ), 
  (
    'PA106', 'STANDARD_DISPENSED_QUANTITY', 
    'The standard dispensed quantity for each Vend of this product', 
    'N0', 1, 4
  ), 
  (
    'PA107', 'SELECTION_STATUS', 'Indicates if the selection motor, actuator, or mechanism is present or if historical (since initialisation) data is available.      0 or empty (recommended) = Selection Present  (normal)     1 = Selection is not Present   (missing / not plugged in) This element is not intended to indicate that a product is unavailable for vending, i.e. Soldout.', 
    'N0', 1, 1
  ), 
  (
    'PA108', 'CURRENT_PRODUCT_LEVEL', 
    'Holds the current product filling level and is modified after each product vend and after each refill action', 
    'N0', 1, 4
  ), 
  (
    'PA109', 'MINIMUM_PRODUCT_LEVEL', 
    'Holds the minimum product level that triggers the refill process', 
    'N0', 1, 4
  ), 
  (
    'PA201', 'NUMBER_OF_PRODUCTS_VENDED_SINCE_INITIALISATION', 
    'The number of products of this type (PA1) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA202', 'VALUE_OF_PAID_PRODUCT_SALES_SINCE_INITIALISATION', 
    'The value of the products of this type (PA1) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA203', 'NUMBER_OF_PRODUCTS_VENDED_SINCE_LAST_RESET', 
    'The number of products of this type (PA1) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, free vend token, and zero price vends. Resettable', 
    'N0', 1, 6
  ), 
  (
    'PA204', 'VALUE_OF_PAID_PRODUCT_SALES_SINCE_LAST_RESET', 
    'The value of the products of this type (PA1) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA205', 'NUMBER_OF_DISCOUNTED_PAID_VENDS_SINCE_INITIALISATION', 
    'This is the number of discounted paid vending sales from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA206', 'VALUE_OF_DISCOUNTS_GIVEN_SINCE_INITIALISATION', 
    'This is the value of discounts from all payment sources since initialisation. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA207', 'NUMBER_OF_DISCOUNTED_PAID_VENDS_SINCE_LAST_RESET', 
    'This is the number of discounted paid vending sales from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends.  Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA208', 'VALUE_OF_DISCOUNTS_GIVEN_SINCE_LAST_RESET', 
    'This is the value of discounts from all payment sources.  Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends.  Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA209', 'NUMBER_OF_SURCHARGES_PAID_VENDS_SINCE_INITIALISATION', 
    'This is the number of surcharged vends from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA210', 'VALUE_OF_SURCHARGES_PAID_SINCE_INITIALISATION', 
    'This is the value of surcharges collected from all payment sources since initialisation. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA211', 'NUMBER_OF_SURCHARGED_PAID_SINCE_LAST_RESET', 
    'This is the number of surcharged vends from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'PA212', 'VALUE_OF_SURCHARGES_PAID_SINCE_LAST_RESET', 
    'This is the value of surcharges collected from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA301', 'NUMBER_OF_TEST_VENDS_SINCE_INITIALISATION', 
    'The number of test vends of this product (PA1) performed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA302', 'VALUE_OF_TEST_VENDS_SINCE_INITIALISATION', 
    'The value of the test vends of this product (PA1) performed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA303', 'NUMBER_OF_TEST_VENDS_SINCE_LAST_RESET', 
    'The number of test vends of this product (PA1) performed. Resettable', 
    'N0', 1, 6
  ), 
  (
    'PA304', 'VALUE_OF_TEST_VENDS_SINCE_LAST_RESET', 
    'The value of the test vends of this product (PA1) performed. Resettable', 
    'Nc', 1, 8
  ), 
  (
    'PA401', 'NUMBER_OF_FREE_VENDS_SINCE_INITIALISATION', 
    'The number of free vends of this product (PA1) performed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA402', 'VALUE_OF_FREE_VENDS_SINCE_INITIALISATION', 
    'The value of the free vends of this product (PA1) performed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA403', 'NUMBER_OF_FREE_VENDS_SINCE_LAST_RESET', 
    'The number of free vends of this product (PA1) performed. Resettable', 
    'N0', 1, 6
  ), 
  (
    'PA404', 'VALUE_OF_FREE_VENDS_SINCE_LAST_RESET', 
    'The value of the free vends of this product (PA1) performed. Resettable', 
    'Nc', 1, 8
  ), 
  (
    'PA405', 'NUMBER_OF_FREE_VENDS_WITHOUT_CUPS_SINCE_INITIALISATION', 
    'The number of products of this type (PA1) vended where the sale is a free vend and no cup has been dispensed from the Vending machine (the patron has used own cup). Does not include test vends and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA406', 'NUMBER_OF_FREE_VENDS_WITHOUT_CUPS_SINCE_LAST_RESET', 
    'The number of products of this type (PA1) vended where the sale is a free vend and no cup has been dispensed from the Vending machine (the patron has used own cup). Does not include test vends and zero price vends. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA501', 'SOLD_OUT_DATE', 'The date that this product (PA1) sold out. In some implementations this may be the date of most recent sale.', 
    'DT', 6, 8
  ), 
  (
    'PA502', 'SOLD_OUT_TIME', 'The time that this product (PA1) sold out. In some implementations this may be the time of most recent sale.', 
    'TM', 4, 6
  ), 
  (
    'PA503', 'NUMBER_OF_TIMES_SOLD_OUT_PRODUCT_SELECTED', 
    'The number of times a product selection is made when sold out. (Credit is available but not deducted). One count per transaction. Resettable', 
    'N0', 1, 4
  ), 
  (
    'PA601', 'PRODUCT_IDENTIFIER', 'Identifies product to be audited by PA602-PA606. The product (i.e. selection) number should refer to a price line number or machine column designator. This number is defined by the manufacturer.', 
    'AN', 1, 6
  ), 
  (
    'PA602', 'PRODUCT_TEXT', 'The product (i.e. selection) text should refer to a price line number or machine column designator.', 
    'AN', 1, 20
  ), 
  (
    'PA603', 'VAT_GROUP', 'Vat group number. 1 out of 4 VAT groups can be selected per price line number or machine column designator.', 
    'N0', 1, 1
  ), 
  (
    'PA604', 'PRODUCT_STATUS', 'Product sales status (price line number or machine column designator). Status=0 means that the sale of the product is blocked. Status=1 means that the product may be sold in a certain period. Status=2 means that the product may be sold any time.', 
    'N0', 1, 1
  ), 
  (
    'PA605', 'FREE_VEND', 'The product can be set to free vend (price line number or machine column designator). Free vend=0 means that the product is not set to free vend. Free vend=1 means that the product is delivered free of charge if a payment card is used. Free vend=2 means that the product is delivered free of charge.', 
    'N0', 1, 1
  ), 
  (
    'PA606', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'PA701', 'PRODUCT_NUMBER', 'Identifies product to be audited by PA702-PA708. The product (i.e. selection) number should refer to a price line number or machine column designator. This number is defined by the manufacturer.', 
    'AN', 1, 8
  ), 
  (
    'PA702', 'PAYMENT_DEVICE', 'Identifies the payment device that performed vends reported in PA703 – PA708. CA = cash (coin and bill) DA = cashless 1 DB = cashless 2 …', 
    'AN', 1, 2
  ), 
  (
    'PA703', 'PRICE_LIST_NUMBER', 'Defines the vending machine list number for which the following values are valid. Irrelevant for cash sales, test and free vend. See appl. notes.', 
    'N0', 1, 3
  ), 
  (
    'PA704', 'APPLIED_PRICE', 'Specifies the product price for a sale with the parameters PA701 to PA703', 
    'Nc', 1, 8
  ), 
  (
    'PA705', 'NUMBER_OF_SALES_SINCE_INITIALISATION', 
    'The number of products of this type (PA701) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, surcharge, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA706', 'VALUE_OF_SALES_SINCE_INITIALISATION', 
    'The value of the products of this type (PA701) where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, surcharge, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA707', 'NUMBER_OF_SALES_SINCE_LAST_RESET', 
    'The number of products of this type (PA701) vended where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, surcharge, free vend token, and zero price vends.  Resettable.', 
    'N0', 1, 6
  ), 
  (
    'PA708', 'VALUE_OF_SALES_SINCE_LAST_RESET', 
    'The value of the products of this type (PA701) where the sale is a paid sale. Does not include free vends and test vends. Includes coin, bill, card, discount, surcharge, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA801', 'NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_INITIALISATION', 
    'The number of products of this type (PA101) vended where the sale is a mixed paid sale (cash and cashless). Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA802', 'VALUE_OF_MIXED_PAYMENT_CASH_AMOUNT_SINCE_INITIALISATION', 
    'The value of the cash amount paid for products of this type (PA101) where the sale is a mixed sale (cash and cashless). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PA803', 'NUMBER_OF_MIXED_PAYMENT_VENDS_SINCE_LAST_RESET', 
    'The number of products of this type (PA101) vended where the sale is a mixed paid sale (cash and cashless).  Resettable.', 
    'N0', 1, 8
  ), 
  (
    'PA804', 'VALUE_OF_MIXED_PAYMENT_CASH_AMOUNT_SINCE_LAST_RESET', 
    'The value of the cash amount paid for products of this type (PA101) where the sale is a mixed sale (cash and cashless). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'PC101', 'PRODUCT_NUMBER', 'Identifies product to be configured by PC102 - PC106', 
    'AN', 1, 6
  ), 
  (
    'PC102', 'PRODUCT_PRICE', 'Configures field PA102', 
    'Nc', 1, 8
  ), 
  (
    'PC103', 'PRODUCT_IDENTIFICATION', 
    'Configures field PA103', 'AN', 
    1, 20
  ), 
  (
    'PC104', 'MAXIMUM_PRODUCT_CAPACITY', 
    'Configures field PA104', 'N0', 
    1, 4
  ), 
  (
    'PC105', 'STANDARD_FILLING_LEVEL', 
    'Configures field PA105', 'N0', 
    1, 4
  ), 
  (
    'PC106', 'STANDARD_DISPENSED_QUANTITY', 
    'Configures field PA106', 'N0', 
    1, 4
  ), 
  (
    'PC108', 'CURRENT_PRODUCT_LEVEL', 
    'Configures PA108 after each refill action.', 
    'N0', 1, 4
  ), 
  (
    'PC109', 'MINIMUM_PRODUCT_LEVEL', 
    'Configures PA109', 'N0', 1, 4
  ), 
  (
    'PC601', 'PRODUCT_IDENTIFIER', 'Identifies product to be configured by PC602 - PC606', 
    'AN', 1, 6
  ), 
  (
    'PC602', 'PRODUCT_TEXT', 'Configures field PA602', 
    'AN', 1, 20
  ), 
  (
    'PC603', 'VAT_GROUP', 'Configures field PA603', 
    'N0', 1, 1
  ), 
  (
    'PC604', 'PRODUCT_STATUS', 'Configures field PA604', 
    'N0', 1, 1
  ), 
  (
    'PC605', 'FREE_VEND', 'Configures field PA605', 
    'N0', 1, 1
  ), 
  (
    'PC606', 'USER_DEFINED_FIELD', 'Configures field PA606', 
    'AN', 1, 12
  ), 
  (
    'PC701', 'PRODUCT_NUMBER', 'Identifies product sales parameters to be configured by PC702 – PC704', 
    'AN', 1, 8
  ), 
  (
    'PC702', 'PAYMENT_DEVICE', 'Identifies payment device further specified in PC703 – PC704. CA = cash (coin and bill) DA = cashless 1 DB = cashless 2 …', 
    'AN', 1, 2
  ), 
  (
    'PC703', 'PRICE_LIST_NUMBER', 'Identifies the vending machine price list to be configured in PC704', 
    'N0', 1, 3
  ), 
  (
    'PC704', 'APPLIED_PRICE', 'Configures PA704', 
    'Nc', 1, 8
  ), 
  (
    'PP101', 'PRESELECTION_NUMBER', 'Identifies the preselection to be audited by PP102PP108. This number is defined by the manufacturer.', 
    'AN', 1, 6
  ), 
  (
    'PP102', 'PRESELECTION_PRICE', 'The normal price of the preselection.', 
    'Nc', 1, 8
  ), 
  (
    'PP103', 'PRESELECTION_IDENTIFICATION', 
    'Preselection identification should identify the preselection itself, as in a name (sweetner, whitener, etc.) or an ID number (barcode).', 
    'AN', 1, 20
  ), 
  (
    'PP104', 'PRESELECTION_INCREMENTAL_PRICE', 
    'The incremental price for multiple preselections of this type in the same transaction.', 
    'Nc', 1, 6
  ), 
  (
    'PP105', 'NUMBER_OF_TIMES_PRESELECTION_USED_SINCE_INITIALISATION', 
    'The number of times this preselection has been used since initialisation.', 
    'N0', 1, 6
  ), 
  (
    'PP106', 'VALUE_OF_PRESELECTION_USED_SINCE_INITIALISATION', 
    'The value of this preselection that has been used since initialisation.', 
    'Nc', 1, 8
  ), 
  (
    'PP107', 'NUMBER_OF_TIMES_PRESELECTION_USED_SINCE_RESET', 
    'The number of times this preselection has been used since the last reset.', 
    'N0', 1, 6
  ), 
  (
    'PP108', 'VALUE_OF_PRESELECTION_USED_SINCE_RESET', 
    'The value of this preselection that has been used since the last reset.', 
    'Nc', 1, 8
  ), 
  (
    'SA101', 'STOCK_ITEM_IDENTIFICATION', 
    'Stock item identification should identify the product it- self, as in a name (chips / crisps) or an ID number (barcode).', 
    'AN', 1, 20
  ), 
  (
    'SA102', 'QUANTITY_ADDED_TO_THE_MACHINE', 
    'This is the quantity of product stocked or added to the machine inventory.', 
    'N0', 1, 6
  ), 
  (
    'SA103', 'QUANTITY_REMOVED_FROM_THE_MACHINE', 
    'This is the quantity of product manually removed from the machine inventory.', 
    'N0', 1, 6
  ), 
  (
    'SA104', 'STOCK_ITEM_MACHINE_PRICE', 
    'This is the normal vend price that this item is vended at. (e.g. Price manually entered in Data Carrier)', 
    'Nc', 1, 8
  ), 
  (
    'SA105', 'STOCK_ITEM_MACHINE_LOCATION', 
    'This should identify the column number of where this item is vended from. (e.g. location manually entered in Data Carrier)', 
    'AN', 1, 20
  ), 
  (
    'SA106', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'SA201', 'INGREDIENT_NUMBER', 'Defines the ingredient for which the following values are valid.', 
    'AN', 1, 20
  ), 
  (
    'SA202', 'QUANTITY_OF_INGREDIENT_VENDED_SINCE_LAST_RESET', 
    'Quantity of ingredient vended since last reset.', 
    'N0', 1, 6
  ), 
  (
    'SA203', 'QUANTITY_OF_INGREDIENT_VENDED_SINCE_INITIALISATION', 
    'Quantity of ingredient vended since initialisation.', 
    'N0', 1, 6
  ), 
  (
    'SD101', 'CURRENT_PASSWORD', 'This element transmits the security access key currently in use.', 
    'AN', 1, 12
  ), 
  (
    'SD102', 'NEW_PASSWORD', 'This element transmits the new security access key that will be adopted at the end of the session.', 
    'AN', 1, 12
  ), 
  (
    'SD103', 'REPORTING_INSTRUCTIONS', 
    'This command is used to instruct the audit unit which data segments (not individual data elements) are to be reported.  Refer to Section 2 for specific details on the use of the SD103 command.', 
    'CD', 1, 100
  ), 
  (
    'SD104', 'RESET_SELECTED_DATA', 'This command is used to instruct the audit unit to reset selected data segments (not individual data elements).  Refer to Section 2 for specific details on the use of the SD104 command.', 
    'CD', 1, 100
  ), 
  (
    'SD105', 'RESET_ALL_INTERVAL_DATA_CONTROL', 
    'This command is used to place the audit unit into a mode of operation pertaining to resetting interval audit data.  It also is used to instruct the audit unit when to reset interval (since last reset) data elements. AUTO, SAVE, and RESET are the allowable commands.  Refer to Section 2 for specific details on the use of the SD105 command.', 
    'CD', 4, 5
  ), 
  (
    'SD106', 'RESET_EVENTS_CONTROL', 
    'This command is used to place the audit unit into a mode of operation pertaining to resetting State 3 events.  It also is used to instruct the audit unit when to reset State 3 events. AUTO, SAVE, and RESET are the allowable commands.  Refer to Section 2 for specific details on the use of the SD106 command.', 
    'CD', 4, 5
  ), 
  (
    'TA101', 'TOKEN_ACCEPTOR_SERIAL_NUMBER', 
    'Identification number of the token acceptor unit. This number may only be set by the Manufacturer. Note: If payment system accepts coins as well as tokens, use CA101 element instead of TA101', 
    'AN', 1, 20
  ), 
  (
    'TA102', 'TOKEN_ACCEPTOR_MODEL_NUMBER', 
    'Model number or description of the token unit.', 
    'AN', 1, 20
  ), 
  (
    'TA103', 'TOKEN_ACCEPTOR_SOFTWARE_REVISION', 
    'Software revision number of the token unit.', 
    'N0', 1, 4
  ), 
  (
    'TA104', 'USER_DEFINED_FIELD', 'User Defined Data', 
    'AN', 1, 12
  ), 
  (
    'TA201', 'VALUE_OF_VEND_TOKEN_VENDS_SINCE_INITIALISATION', 
    'Value of all vend token vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA202', 'NUMBER_OF_VEND_TOKEN_VENDS_SINCE_INITIALISATION', 
    'Number of all vend token vends Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA203', 'VALUE_OF_VEND_TOKEN_SALES_SINCE_LAST_RESET', 
    'Value of all vend token sales. Resettable.', 
    'Nc', 1, 6
  ), 
  (
    'TA204', 'NUMBER_OF_VEND_TOKEN_SALES_SINCE_LAST_RESET', 
    'Number of all vend token sales. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA205', 'VALUE_OF_VALUE_TOKEN_SINCE_INITIALISATION', 
    'Value of all value token sales. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA206', 'NUMBER_OF_VALUE_TOKEN_SINCE_INITIALISATION', 
    'Number of all value token sales. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA207', 'VALUE_OF_VALUE_TOKEN_SALES_SINCE_LAST_RESET', 
    'Value of all value token sales. Resettable.', 
    'Nc', 1, 6
  ), 
  (
    'TA208', 'NUMBER_OF_VALUE_TOKEN_VENDS_SINCE_LAST_RESET', 
    'Number of all value token sales. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA301', 'VALUE_OF_VALUE_TOKENS_IN_SINCE_LAST_RESET', 
    'Value of all value tokens accepted. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA302', 'VALUE_OF_VALUE_TOKENS_IN_SINCE_INITIALISATION', 
    'Value of all value tokens. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA401', 'VALUE_OF_VALUE_TOKENS_DISPENSED_SINCE_LAST_RESET', 
    'Value of all value tokens dispensed as change plus manually dispensed. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA402', 'VALUE_OF_VALUE_TOKENS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Value of all value tokens manually dispensed. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA403', 'VALUE_OF_VALUE_TOKENS_DISPENSED_SINCE_INITIALISATION', 
    'Value of all value tokens dispensed as change plus manually dispensed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA404', 'VALUE_OF_VALUE_TOKENS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Value of all value tokens manually dispensed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA405', 'NUMBER_OF_VEND_TOKENS_DISPENSED_SINCE_LAST_RESET', 
    'Number of all vend tokens dispensed as change plus manually dispensed. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA406', 'NUMBER_OF_VEND_TOKENS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Number of all vend tokens manually dispensed. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA407', 'NUMBER_OF_VEND_TOKENS_DISPENSED_SINCE_INITIALISATION', 
    'Number of all vend tokens dispensed as change plus manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA408', 'NUMBER_OF_VEND_TOKENS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Number of all vend tokens manually dispensed Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA501', 'VALUE_OF_TOKEN_OVERPAY_SINCE_LAST_RESET', 
    'Value of value token overpay received. (Inserted money - change paid - vend price = overpay value). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA502', 'VALUE_OF_TOKEN_OVERPAY_SINCE_INITIALISATION', 
    'Value of value token overpay received. (Inserted money - change paid - vend price = overpay value). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA601', 'VALUE_OF_VALUE_TOKENS_FILLED_SINCE_LAST_RESET', 
    'Value of all value tokens manually added to the machine. (filled inventory tubes). Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA602', 'VALUE_OF_VALUE_TOKENS_FILLED_SINCE_INITIALISATION', 
    'Value of all value tokens manually added to the machine. (filled inventory tubes). Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'TA603', 'NUMBER_OF_VEND_TOKENS_FILLED_SINCE_LAST_RESET', 
    'Number of all vend tokens manually added to the machine. (filled inventory tubes). Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA604', 'NUMBER_OF_VEND_TOKENS_FILLED_SINCE_INITIALISATION', 
    'Number of all vend tokens manually added to the machine. (filled inventory tubes). Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA701', 'TOKEN_VALUE', 'Value of the token being reported on. Value of zero means vend token.', 
    'Nc', 1, 8
  ), 
  (
    'TA702', 'NUMBER_OF_TOKENS_IN_SINCE_LAST_RESET', 
    'Number of value token of this value (TA701) accepted. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA703', 'NUMBER_OF_TOKENS_TO_CASH_BOX_SINCE_LAST_RESET', 
    'Number of value token of this value (TA701) accepted and sent to the cashbox. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA704', 'NUMBER_OF_TOKENS_TO_TUBES_SINCE_LAST_RESET', 
    'Number of value token of this value (TA701) accepted and sent to the inventory tubes Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA705', 'NUMBER_OF_TOKENS_IN_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA701) accepted. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA706', 'NUMBER_OF_TOKENS_TO_CASH_BOX_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA701) accepted and sent to the cashbox. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA707', 'NUMBER_OF_TOKENS_TO_TUBES_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA701) accepted and sent to the inventory tubes Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA801', 'TOKEN_VALUE', 'Value of the token being reported on. Value of zero means vend token.', 
    'Nc', 1, 8
  ), 
  (
    'TA802', 'NUMBER_OF_TOKENS_DISPENSED_SINCE_LAST_RESET', 
    'Number of value tokens of this value (TA801) paid out as change plus manually dispensed. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA803', 'NUMBER_OF_TOKENS_MANUALLY_DISPENSED_SINCE_LAST_RESET', 
    'Number of value tokens of this value (TA801) manually dispensed. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA804', 'NUMBER_OF_TOKENS_DISPENSED_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA801) paid out as change plus manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA805', 'NUMBER_OF_TOKENS_MANUALLY_DISPENSED_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA801) manually dispensed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA901', 'TOKEN_VALUE', 'Value of the token being reported on. Value of zero means vend token.', 
    'Nc', 1, 8
  ), 
  (
    'TA902', 'NUMBER_OF_TOKENS_FILLED_SINCE_LAST_RESET', 
    'Number of value tokens of this value (TA901) manually filled. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'TA903', 'NUMBER_OF_TOKENS_FILLED_SINCE_INITIALISATION', 
    'Number of value tokens of this value (TA901) manually filled. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'TA1001', 'TOKEN_IDENTIFICATION', 
    'Identification Number of the Token being reported on.', 
    'N0', 1, 8
  ), 
  (
    'TA1002', 'TOKEN_VALUE', 'Value of the token. Note that a value of zero means that the token is a vend token.', 
    'Nc', 1, 8
  ), 
  (
    'TC101', 'TOKEN_ACCEPTOR_SERIAL_NUMBER', 
    'Configures field TA101 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'TC102', 'TOKEN_ACCEPTOR_MODEL_NUMBER', 
    'Configures field TA102 (not post manufacturer configurable)', 
    'AN', 1, 20
  ), 
  (
    'TC103', 'TOKEN_ACCEPTOR_SOFTWARE_REVISION', 
    'Configures field TA103 (not post manufacturer configurable)', 
    'N0', 1, 4
  ), 
  (
    'TC104', 'USER_DEFINED_FIELD', 'Configures field TA104', 
    'AN', 1, 12
  ), 
  (
    'TC1001', 'TOKEN_IDENTIFICATION', 
    'Configures field TC1001', 'N0', 
    1, 8
  ), 
  (
    'TC1002', 'TOKEN_VALUE', 'Configures field TA1002', 
    'Nc', 1, 8
  ), 
  (
    'VA101', 'VALUE_OF_ALL_PAID_VENDS_SINCE_INITIALISATION', 
    'This is the value of all paid vending sales from all payment sources since initialisation. NonResettable. Free vends and Test vends are not included. Includes coin, bill, card, discount, free vend token, and zero price vends.', 
    'Nc', 1, 8
  ), 
  (
    'VA102', 'NUMBER_OF_ALL_PAID_VENDS_SINCE_INITIALISATION', 
    'This is the number of paid vending sales from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, discount, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA103', 'VALUE_OF_ALL_PAID_SALES_SINCE_LAST_RESET', 
    'This is the value of all paid vending sales from all payment sources. Free vends and test vends are not included. Includes coin, bill, card, discount, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA104', 'NUMBER_OF_ALL_PAID_VENDS_SINCE_LAST_RESET', 
    'This is the number of all paid vending sales from all payment sources. Free vends and test vends are not included. Includes coin, bill, card, discount, free vend token, and zero price vends.  Resettable.', 
    'N0', 1, 6
  ), 
  (
    'VA105', 'VALUE_OF_ALL_DISCOUNTS_GIVEN_SINCE_INITIALISATION', 
    'This is the value of all discounts awarded by the vending machine controller (does not include discounts applied by a peripheral) from all payment sources since initialisation. Free vends and test vends are not included. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA106', 'NUMBER_OF_ALL_DISCOUNTED_PAID_VENDS_SINCE_INITIALISATION', 
    'This is the number of all discounted paid vending sales awarded by the vending machine controller (does not include discounts applied by a peripheral) from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA107', 'VALUE_OF_ALL_DISCOUNTS_GIVEN_SINCE_LAST_RESET', 
    'This is the value of all discounts awarded by the vending machine controller (does not include discounts applied by a peripheral) from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA108', 'NUMBER_OF_ALL_DISCOUNTED_PAID_VENDS_SINCE_LAST_RESET', 
    'This is the number of all discounted paid vending sales awarded by the vending machine controller (does not include discounts applied by a peripheral) from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA109', 'NUMBER_OF_ALL_SURCHARGED_VENDS_SINCE_INITIALISATION', 
    'This is the number of all surcharged vends from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA110', 'VALUE_OF_ALL_SURCHARGES_COLLECTED_SINCE_INITIALISATION', 
    'This is the value of all surcharges collected from all payment sources since initialisation. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA111', 'NUMBER_OF_ALL_SURCHARGED_VENDS_SINCE_LAST_RESET', 
    'This is the number of all surcharged vends from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'N0', 1, 6
  ), 
  (
    'VA112', 'VALUE_OF_ALL_SURCHARGES_COLLECTED_SINCE_LAST_RESET', 
    'This is the value of all surcharges collected from all payment sources. Does not include free vends and test vends. Includes coin, bill, card, free vend token, and zero price vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA201', 'TEST_VEND_VALUE_OF_SALES_SINCE_INITIALISATION', 
    'Value of all test vends performed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA202', 'NUMBER_OF_TEST_VENDS_SINCE_INITIALISATION', 
    'Number of all test vends performed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA203', 'TEST_VEND_VALUE_OF_SALES_SINCE_LAST_RESET', 
    'Value of all test vends performed. Resettable.', 
    'Nc', 1, 6
  ), 
  (
    'VA204', 'NUMBER_OF_TEST_VENDS_SINCE_LAST_RESET', 
    'Number of all test vends performed. Resettable.', 
    'N0', 1, 4
  ), 
  (
    'VA205', 'TEST_VEND_BOX_CASH_SINCE_INITIALISATION', 
    'Value of money to the cash box during test vends. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA206', 'TEST_VEND_BOX_CASH_SINCE_LAST_RESET', 
    'Value of money to the cash box during test vends. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA301', 'FREE_VEND_VALUE_OF_SALES_SINCE_INITIALISATION', 
    'Value of all free vends performed. Non-Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA302', 'NUMBER_OF_FREE_VENDS_SINCE_INITIALISATION', 
    'Number of all free vends performed. Non-Resettable.', 
    'N0', 1, 8
  ), 
  (
    'VA303', 'FREE_VEND_VALUE_OF_SALES_SINCE_LAST_RESET', 
    'Value of all free vends performed. Resettable.', 
    'Nc', 1, 8
  ), 
  (
    'VA304', 'NUMBER_OF_FREE_VENDS_SINCE_LAST_RESET', 
    'Number of all free vends performed. Resettable.', 
    'N0', 1, 6
  )
