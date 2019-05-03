CREATE TABLE IF NOT EXISTS `regions` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT, 
  `iso` varchar(45) DEFAULT NULL, 
  `iso3` varchar(45) DEFAULT NULL, 
  `fips` varchar(45) DEFAULT NULL, 
  `country` varchar(45) DEFAULT NULL, 
  `continent` varchar(45) DEFAULT NULL, 
  `currency_code` varchar(45) DEFAULT NULL, 
  `currency_name` varchar(45) DEFAULT NULL, 
  `phone_prefix` varchar(45) DEFAULT NULL, 
  `postal_code` varchar(45) DEFAULT NULL, 
  `languages` varchar(45) DEFAULT NULL, 
  `geonameid` varchar(45) DEFAULT NULL, 
  PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8 AUTO_INCREMENT = 895;
INSERT INTO `regions` (
  `id`, `iso`, `iso3`, `fips`, `country`, 
  `continent`, `currency_code`, `currency_name`, 
  `phone_prefix`, `postal_code`, `languages`, 
  `geonameid`
) 
VALUES 
  (
    4, 'AF', 'AFG', 'AF', 'Afghanistan', 
    'AS', 'AFN', 'Afghani', '93', '', 'fa-AF,ps,uz-AF,tk', 
    '1149361'
  ), 
  (
    8, 'AL', 'ALB', 'AL', 'Albania', 'EU', 
    'ALL', 'Lek', '355', '', 'sq,el', '783754'
  ), 
  (
    10, 'AQ', 'ATA', 'AY', 'Antarctica', 
    'AN', '', '', '', '', '', '6697173'
  ), 
  (
    12, 'DZ', 'DZA', 'AG', 'Algeria', 'AF', 
    'DZD', 'Dinar', '213', '^(d{5})$', 
    'ar-DZ', '2589581'
  ), 
  (
    16, 'AS', 'ASM', 'AQ', 'American Samoa', 
    'OC', 'USD', 'Dollar', '+1-684', '', 
    'en-AS,sm,to', '5880801'
  ), 
  (
    20, 'AD', 'AND', 'AN', 'Andorra', 'EU', 
    'EUR', 'Euro', '376', '^(?:AD)*(d{3})$', 
    'ca,fr-AD,pt', '3041565'
  ), 
  (
    24, 'AO', 'AGO', 'AO', 'Angola', 'AF', 
    'AOA', 'Kwanza', '244', '', 'pt-AO', 
    '3351879'
  ), 
  (
    28, 'AG', 'ATG', 'AC', 'Antigua and Barbuda', 
    'NA', 'XCD', 'Dollar', '+1-268', '', 
    'en-AG', '3576396'
  ), 
  (
    31, 'AZ', 'AZE', 'AJ', 'Azerbaijan', 
    'AS', 'AZN', 'Manat', '994', '^(?:AZ)*(d{4})$', 
    'az,ru,hy', '587116'
  ), 
  (
    32, 'AR', 'ARG', 'AR', 'Argentina', 
    'SA', 'ARS', 'Peso', '54', '^([A-Z]d{4}[A-Z]{3})$', 
    'es-AR,en,it,de,fr', '3865483'
  ), 
  (
    36, 'AU', 'AUS', 'AS', 'Australia', 
    'OC', 'AUD', 'Dollar', '61', '^(d{4})$', 
    'en-AU', '2077456'
  ), 
  (
    40, 'AT', 'AUT', 'AU', 'Austria', 'EU', 
    'EUR', 'Euro', '43', '^(d{4})$', 'de-AT,hr,hu,sl', 
    '2782113'
  ), 
  (
    44, 'BS', 'BHS', 'BF', 'Bahamas', 'NA', 
    'BSD', 'Dollar', '+1-242', '', 'en-BS', 
    '3572887'
  ), 
  (
    48, 'BH', 'BHR', 'BA', 'Bahrain', 'AS', 
    'BHD', 'Dinar', '973', '^(d{3}d?)$', 
    'ar-BH,en,fa,ur', '290291'
  ), 
  (
    50, 'BD', 'BGD', 'BG', 'Bangladesh', 
    'AS', 'BDT', 'Taka', '880', '^(d{4})$', 
    'bn-BD,en', '1210997'
  ), 
  (
    51, 'AM', 'ARM', 'AM', 'Armenia', 'AS', 
    'AMD', 'Dram', '374', '^(d{6})$', 
    'hy', '174982'
  ), 
  (
    52, 'BB', 'BRB', 'BB', 'Barbados', 'NA', 
    'BBD', 'Dollar', '+1-246', '^(?:BB)*(d{5})$', 
    'en-BB', '3374084'
  ), 
  (
    56, 'BE', 'BEL', 'BE', 'Belgium', 'EU', 
    'EUR', 'Euro', '32', '^(d{4})$', 'nl-BE,fr-BE,de-BE', 
    '2802361'
  ), 
  (
    60, 'BM', 'BMU', 'BD', 'Bermuda', 'NA', 
    'BMD', 'Dollar', '+1-441', '^([A-Z]{2}d{2})$', 
    'en-BM,pt', '3573345'
  ), 
  (
    64, 'BT', 'BTN', 'BT', 'Bhutan', 'AS', 
    'BTN', 'Ngultrum', '975', '', 'dz', 
    '1252634'
  ), 
  (
    68, 'BO', 'BOL', 'BL', 'Bolivia', 'SA', 
    'BOB', 'Boliviano', '591', '', 'es-BO,qu,ay', 
    '3923057'
  ), 
  (
    70, 'BA', 'BIH', 'BK', 'Bosnia and Herzegovina', 
    'EU', 'BAM', 'Marka', '387', '^(d{5})$', 
    'bs,hr-BA,sr-BA', '3277605'
  ), 
  (
    72, 'BW', 'BWA', 'BC', 'Botswana', 'AF', 
    'BWP', 'Pula', '267', '', 'en-BW,tn-BW', 
    '933860'
  ), 
  (
    74, 'BV', 'BVT', 'BV', 'Bouvet Island', 
    'AN', 'NOK', 'Krone', '', '', '', '3371123'
  ), 
  (
    76, 'BR', 'BRA', 'BR', 'Brazil', 'SA', 
    'BRL', 'Real', '55', '^(d{8})$', 'pt-BR,es,en,fr', 
    '3469034'
  ), 
  (
    84, 'BZ', 'BLZ', 'BH', 'Belize', 'NA', 
    'BZD', 'Dollar', '501', '', 'en-BZ,es', 
    '3582678'
  ), 
  (
    86, 'IO', 'IOT', 'IO', 'British Indian Ocean Territory', 
    'AS', 'USD', 'Dollar', '246', '', 'en-IO', 
    '1282588'
  ), 
  (
    90, 'SB', 'SLB', 'BP', 'Solomon Islands', 
    'OC', 'SBD', 'Dollar', '677', '', 'en-SB,tpi', 
    '2103350'
  ), 
  (
    92, 'VG', 'VGB', 'VI', 'British Virgin Islands', 
    'NA', 'USD', 'Dollar', '+1-284', '', 
    'en-VG', '3577718'
  ), 
  (
    96, 'BN', 'BRN', 'BX', 'Brunei', 'AS', 
    'BND', 'Dollar', '673', '^([A-Z]{2}d{4})$', 
    'ms-BN,en-BN', '1820814'
  ), 
  (
    100, 'BG', 'BGR', 'BU', 'Bulgaria', 
    'EU', 'BGN', 'Lev', '359', '^(d{4})$', 
    'bg,tr-BG', '732800'
  ), 
  (
    104, 'MM', 'MMR', 'BM', 'Myanmar', 'AS', 
    'MMK', 'Kyat', '95', '^(d{5})$', 'my', 
    '1327865'
  ), 
  (
    108, 'BI', 'BDI', 'BY', 'Burundi', 'AF', 
    'BIF', 'Franc', '257', '', 'fr-BI,rn', 
    '433561'
  ), 
  (
    112, 'BY', 'BLR', 'BO', 'Belarus', 'EU', 
    'BYR', 'Ruble', '375', '^(d{6})$', 
    'be,ru', '630336'
  ), 
  (
    116, 'KH', 'KHM', 'CB', 'Cambodia', 
    'AS', 'KHR', 'Riels', '855', '^(d{5})$', 
    'km,fr,en', '1831722'
  ), 
  (
    120, 'CM', 'CMR', 'CM', 'Cameroon', 
    'AF', 'XAF', 'Franc', '237', '', 'en-CM,fr-CM', 
    '2233387'
  ), 
  (
    124, 'CA', 'CAN', 'CA', 'Canada', 'NA', 
    'CAD', 'Dollar', '1', '^([a-zA-Z]d[a-zA-Z]d[a-zA-Z]d)$', 
    'en-CA,fr-CA', '6251999'
  ), 
  (
    132, 'CV', 'CPV', 'CV', 'Cape Verde', 
    'AF', 'CVE', 'Escudo', '238', '^(d{4})$', 
    'pt-CV', '3374766'
  ), 
  (
    136, 'KY', 'CYM', 'CJ', 'Cayman Islands', 
    'NA', 'KYD', 'Dollar', '+1-345', '', 
    'en-KY', '3580718'
  ), 
  (
    140, 'CF', 'CAF', 'CT', 'Central African Republic', 
    'AF', 'XAF', 'Franc', '236', '', 'fr-CF,ln,kg', 
    '239880'
  ), 
  (
    144, 'LK', 'LKA', 'CE', 'Sri Lanka', 
    'AS', 'LKR', 'Rupee', '94', '^(d{5})$', 
    'si,ta,en', '1227603'
  ), 
  (
    148, 'TD', 'TCD', 'CD', 'Chad', 'AF', 
    'XAF', 'Franc', '235', '', 'fr-TD,ar-TD,sre', 
    '2434508'
  ), 
  (
    152, 'CL', 'CHL', 'CI', 'Chile', 'SA', 
    'CLP', 'Peso', '56', '^(d{7})$', 'es-CL', 
    '3895114'
  ), 
  (
    156, 'CN', 'CHN', 'CH', 'China', 'AS', 
    'CNY', 'Yuan Renminbi', '86', '^(d{6})$', 
    'zh-CN,yue,wuu', '1814991'
  ), 
  (
    158, 'TW', 'TWN', 'TW', 'Taiwan', 'AS', 
    'TWD', 'Dollar', '886', '^(d{5})$', 
    'zh-TW,zh,nan,hak', '1668284'
  ), 
  (
    162, 'CX', 'CXR', 'KT', 'Christmas Island', 
    'AS', 'AUD', 'Dollar', '61', '^(d{4})$', 
    'en,zh,ms-CC', '2078138'
  ), 
  (
    166, 'CC', 'CCK', 'CK', 'Cocos Islands', 
    'AS', 'AUD', 'Dollar', '61', '', 'ms-CC,en', 
    '1547376'
  ), 
  (
    170, 'CO', 'COL', 'CO', 'Colombia', 
    'SA', 'COP', 'Peso', '57', '', 'es-CO', 
    '3686110'
  ), 
  (
    174, 'KM', 'COM', 'CN', 'Comoros', 'AF', 
    'KMF', 'Franc', '269', '', 'ar,fr-KM', 
    '921929'
  ), 
  (
    175, 'YT', 'MYT', 'MF', 'Mayotte', 'AF', 
    'EUR', 'Euro', '269', '^(d{5})$', 
    'fr-YT', '1024031'
  ), 
  (
    178, 'CG', 'COG', 'CF', 'Republic of the Congo', 
    'AF', 'XAF', 'Franc', '242', '', 'fr-CG,kg,ln-CG', 
    '2260494'
  ), 
  (
    180, 'CD', 'COD', 'CG', 'Democratic Republic of the Congo', 
    'AF', 'CDF', 'Franc', '243', '', 'fr-CD,ln,kg', 
    '203312'
  ), 
  (
    184, 'CK', 'COK', 'CW', 'Cook Islands', 
    'OC', 'NZD', 'Dollar', '682', '', 'en-CK,mi', 
    '1899402'
  ), 
  (
    188, 'CR', 'CRI', 'CS', 'Costa Rica', 
    'NA', 'CRC', 'Colon', '506', '^(d{4})$', 
    'es-CR,en', '3624060'
  ), 
  (
    191, 'HR', 'HRV', 'HR', 'Croatia', 'EU', 
    'HRK', 'Kuna', '385', '^(?:HR)*(d{5})$', 
    'hr-HR,sr', '3202326'
  ), 
  (
    192, 'CU', 'CUB', 'CU', 'Cuba', 'NA', 
    'CUP', 'Peso', '53', '^(?:CP)*(d{5})$', 
    'es-CU', '3562981'
  ), 
  (
    196, 'CY', 'CYP', 'CY', 'Cyprus', 'EU', 
    'EUR', 'Euro', '357', '^(d{4})$', 
    'el-CY,tr-CY,en', '146669'
  ), 
  (
    203, 'CZ', 'CZE', 'EZ', 'Czech Republic', 
    'EU', 'CZK', 'Koruna', '420', '^(d{5})$', 
    'cs,sk', '3077311'
  ), 
  (
    204, 'BJ', 'BEN', 'BN', 'Benin', 'AF', 
    'XOF', 'Franc', '229', '', 'fr-BJ', 
    '2395170'
  ), 
  (
    208, 'DK', 'DNK', 'DA', 'Denmark', 'EU', 
    'DKK', 'Krone', '45', '^(d{4})$', 
    'da-DK,en,fo,de-DK', '2623032'
  ), 
  (
    212, 'DM', 'DMA', 'DO', 'Dominica', 
    'NA', 'XCD', 'Dollar', '+1-767', '', 
    'en-DM', '3575830'
  ), 
  (
    214, 'DO', 'DOM', 'DR', 'Dominican Republic', 
    'NA', 'DOP', 'Peso', '+1-809 and 1-829', 
    '^(d{5})$', 'es-DO', '3508796'
  ), 
  (
    218, 'EC', 'ECU', 'EC', 'Ecuador', 'SA', 
    'USD', 'Dollar', '593', '^([a-zA-Z]d{4}[a-zA-Z])$', 
    'es-EC', '3658394'
  ), 
  (
    222, 'SV', 'SLV', 'ES', 'El Salvador', 
    'NA', 'USD', 'Dollar', '503', '^(?:CP)*(d{4})$', 
    'es-SV', '3585968'
  ), 
  (
    226, 'GQ', 'GNQ', 'EK', 'Equatorial Guinea', 
    'AF', 'XAF', 'Franc', '240', '', 'es-GQ,fr', 
    '2309096'
  ), 
  (
    231, 'ET', 'ETH', 'ET', 'Ethiopia', 
    'AF', 'ETB', 'Birr', '251', '^(d{4})$', 
    'am,en-ET,om-ET,ti-ET,so-ET,sid', 
    '337996'
  ), 
  (
    232, 'ER', 'ERI', 'ER', 'Eritrea', 'AF', 
    'ERN', 'Nakfa', '291', '', 'aa-ER,ar,tig,kun,ti-ER', 
    '338010'
  ), 
  (
    233, 'EE', 'EST', 'EN', 'Estonia', 'EU', 
    'EEK', 'Kroon', '372', '^(d{5})$', 
    'et,ru', '453733'
  ), 
  (
    234, 'FO', 'FRO', 'FO', 'Faroe Islands', 
    'EU', 'DKK', 'Krone', '298', '^(?:FO)*(d{3})$', 
    'fo,da-FO', '2622320'
  ), 
  (
    238, 'FK', 'FLK', 'FK', 'Falkland Islands', 
    'SA', 'FKP', 'Pound', '500', '', 'en-FK', 
    '3474414'
  ), 
  (
    239, 'GS', 'SGS', 'SX', 'South Georgia and the South Sandwich Islands', 
    'AN', 'GBP', 'Pound', '', '', 'en', 
    '3474415'
  ), 
  (
    242, 'FJ', 'FJI', 'FJ', 'Fiji', 'OC', 
    'FJD', 'Dollar', '679', '', 'en-FJ,fj', 
    '2205218'
  ), 
  (
    246, 'FI', 'FIN', 'FI', 'Finland', 'EU', 
    'EUR', 'Euro', '358', '^(?:FI)*(d{5})$', 
    'fi-FI,sv-FI,smn', '660013'
  ), 
  (
    248, 'AX', 'ALA', '', 'Aland Islands', 
    'EU', 'EUR', 'Euro', '+358-18', '', 
    'sv-AX', '661882'
  ), 
  (
    250, 'FR', 'FRA', 'FR', 'France', 'EU', 
    'EUR', 'Euro', '33', '^(d{5})$', 'fr-FR,frp,br,co,ca,eu', 
    '3017382'
  ), 
  (
    254, 'GF', 'GUF', 'FG', 'French Guiana', 
    'SA', 'EUR', 'Euro', '594', '^((97)|(98)3d{2})$', 
    'fr-GF', '3381670'
  ), 
  (
    258, 'PF', 'PYF', 'FP', 'French Polynesia', 
    'OC', 'XPF', 'Franc', '689', '^((97)|(98)7d{2})$', 
    'fr-PF,ty', '4020092'
  ), 
  (
    260, 'TF', 'ATF', 'FS', 'French Southern Territories', 
    'AN', 'EUR', 'Euro  ', '', '', 'fr', 
    '1546748'
  ), 
  (
    262, 'DJ', 'DJI', 'DJ', 'Djibouti', 
    'AF', 'DJF', 'Franc', '253', '', 'fr-DJ,ar,so-DJ,aa', 
    '223816'
  ), 
  (
    266, 'GA', 'GAB', 'GB', 'Gabon', 'AF', 
    'XAF', 'Franc', '241', '', 'fr-GA', 
    '2400553'
  ), 
  (
    268, 'GE', 'GEO', 'GG', 'Georgia', 'AS', 
    'GEL', 'Lari', '995', '^(d{4})$', 
    'ka,ru,hy,az', '614540'
  ), 
  (
    270, 'GM', 'GMB', 'GA', 'Gambia', 'AF', 
    'GMD', 'Dalasi', '220', '', 'en-GM,mnk,wof,wo,ff', 
    '2413451'
  ), 
  (
    275, 'PS', 'PSE', 'WE', 'Palestinian Territory', 
    'AS', 'ILS', 'Shekel', '970', '', 'ar-PS', 
    '6254930'
  ), 
  (
    276, 'DE', 'DEU', 'GM', 'Germany', 'EU', 
    'EUR', 'Euro', '49', '^(d{5})$', 'de', 
    '2921044'
  ), 
  (
    288, 'GH', 'GHA', 'GH', 'Ghana', 'AF', 
    'GHS', 'Cedi', '233', '', 'en-GH,ak,ee,tw', 
    '2300660'
  ), 
  (
    292, 'GI', 'GIB', 'GI', 'Gibraltar', 
    'EU', 'GIP', 'Pound', '350', '', 'en-GI,es,it,pt', 
    '2411586'
  ), 
  (
    296, 'KI', 'KIR', 'KR', 'Kiribati', 
    'OC', 'AUD', 'Dollar', '686', '', 'en-KI,gil', 
    '4030945'
  ), 
  (
    300, 'GR', 'GRC', 'GR', 'Greece', 'EU', 
    'EUR', 'Euro', '30', '^(d{5})$', 'el-GR,en,fr', 
    '390903'
  ), 
  (
    304, 'GL', 'GRL', 'GL', 'Greenland', 
    'NA', 'DKK', 'Krone', '299', '^(d{4})$', 
    'kl,da-GL,en', '3425505'
  ), 
  (
    308, 'GD', 'GRD', 'GJ', 'Grenada', 'NA', 
    'XCD', 'Dollar', '+1-473', '', 'en-GD', 
    '3580239'
  ), 
  (
    312, 'GP', 'GLP', 'GP', 'Guadeloupe', 
    'NA', 'EUR', 'Euro', '590', '^((97)|(98)d{3})$', 
    'fr-GP', '3579143'
  ), 
  (
    316, 'GU', 'GUM', 'GQ', 'Guam', 'OC', 
    'USD', 'Dollar', '+1-671', '^(969d{2})$', 
    'en-GU,ch-GU', '4043988'
  ), 
  (
    320, 'GT', 'GTM', 'GT', 'Guatemala', 
    'NA', 'GTQ', 'Quetzal', '502', '^(d{5})$', 
    'es-GT', '3595528'
  ), 
  (
    324, 'GN', 'GIN', 'GV', 'Guinea', 'AF', 
    'GNF', 'Franc', '224', '', 'fr-GN', 
    '2420477'
  ), 
  (
    328, 'GY', 'GUY', 'GY', 'Guyana', 'SA', 
    'GYD', 'Dollar', '592', '', 'en-GY', 
    '3378535'
  ), 
  (
    332, 'HT', 'HTI', 'HA', 'Haiti', 'NA', 
    'HTG', 'Gourde', '509', '^(?:HT)*(d{4})$', 
    'ht,fr-HT', '3723988'
  ), 
  (
    334, 'HM', 'HMD', 'HM', 'Heard Island and McDonald Islands', 
    'AN', 'AUD', 'Dollar', ' ', '', '', 
    '1547314'
  ), 
  (
    336, 'VA', 'VAT', 'VT', 'Vatican', 'EU', 
    'EUR', 'Euro', '379', '', 'la,it,fr', 
    '3164670'
  ), 
  (
    340, 'HN', 'HND', 'HO', 'Honduras', 
    'NA', 'HNL', 'Lempira', '504', '^([A-Z]{2}d{4})$', 
    'es-HN', '3608932'
  ), 
  (
    344, 'HK', 'HKG', 'HK', 'Hong Kong', 
    'AS', 'HKD', 'Dollar', '852', '', 'zh-HK,yue,zh,en', 
    '1819730'
  ), 
  (
    348, 'HU', 'HUN', 'HU', 'Hungary', 'EU', 
    'HUF', 'Forint', '36', '^(d{4})$', 
    'hu-HU', '719819'
  ), 
  (
    352, 'IS', 'ISL', 'IC', 'Iceland', 'EU', 
    'ISK', 'Krona', '354', '^(d{3})$', 
    'is,en,de,da,sv,no', '2629691'
  ), 
  (
    356, 'IN', 'IND', 'IN', 'India', 'AS', 
    'INR', 'Rupee', '91', '^(d{6})$', 
    'en-IN,hi,bn,te,mr,ta,ur,gu,ml,kn,or,pa,as,ks,', 
    '1269750'
  ), 
  (
    360, 'ID', 'IDN', 'ID', 'Indonesia', 
    'AS', 'IDR', 'Rupiah', '62', '^(d{5})$', 
    'id,en,nl,jv', '1643084'
  ), 
  (
    364, 'IR', 'IRN', 'IR', 'Iran', 'AS', 
    'IRR', 'Rial', '98', '^(d{10})$', 
    'fa-IR,ku', '130758'
  ), 
  (
    368, 'IQ', 'IRQ', 'IZ', 'Iraq', 'AS', 
    'IQD', 'Dinar', '964', '^(d{5})$', 
    'ar-IQ,ku,hy', '99237'
  ), 
  (
    372, 'IE', 'IRL', 'EI', 'Ireland', 'EU', 
    'EUR', 'Euro', '353', '', 'en-IE,ga-IE', 
    '2963597'
  ), 
  (
    376, 'IL', 'ISR', 'IS', 'Israel', 'AS', 
    'ILS', 'Shekel', '972', '^(d{5})$', 
    'he,ar-IL,en-IL,', '294640'
  ), 
  (
    380, 'IT', 'ITA', 'IT', 'Italy', 'EU', 
    'EUR', 'Euro', '39', '^(d{5})$', 'it-IT,de-IT,fr-IT,sl', 
    '3175395'
  ), 
  (
    384, 'CI', 'CIV', 'IV', 'Ivory Coast', 
    'AF', 'XOF', 'Franc', '225', '', 'fr-CI', 
    '2287781'
  ), 
  (
    388, 'JM', 'JAM', 'JM', 'Jamaica', 'NA', 
    'JMD', 'Dollar', '+1-876', '', 'en-JM', 
    '3489940'
  ), 
  (
    392, 'JP', 'JPN', 'JA', 'Japan', 'AS', 
    'JPY', 'Yen', '81', '^(d{7})$', 'ja', 
    '1861060'
  ), 
  (
    398, 'KZ', 'KAZ', 'KZ', 'Kazakhstan', 
    'AS', 'KZT', 'Tenge', '7', '^(d{6})$', 
    'kk,ru', '1522867'
  ), 
  (
    400, 'JO', 'JOR', 'JO', 'Jordan', 'AS', 
    'JOD', 'Dinar', '962', '^(d{5})$', 
    'ar-JO,en', '248816'
  ), 
  (
    404, 'KE', 'KEN', 'KE', 'Kenya', 'AF', 
    'KES', 'Shilling', '254', '^(d{5})$', 
    'en-KE,sw-KE', '192950'
  ), 
  (
    408, 'KP', 'PRK', 'KN', 'North Korea', 
    'AS', 'KPW', 'Won', '850', '^(d{6})$', 
    'ko-KP', '1873107'
  ), 
  (
    410, 'KR', 'KOR', 'KS', 'South Korea', 
    'AS', 'KRW', 'Won', '82', '^(?:SEOUL)*(d{6})$', 
    'ko-KR,en', '1835841'
  ), 
  (
    414, 'KW', 'KWT', 'KU', 'Kuwait', 'AS', 
    'KWD', 'Dinar', '965', '^(d{5})$', 
    'ar-KW,en', '285570'
  ), 
  (
    417, 'KG', 'KGZ', 'KG', 'Kyrgyzstan', 
    'AS', 'KGS', 'Som', '996', '^(d{6})$', 
    'ky,uz,ru', '1527747'
  ), 
  (
    418, 'LA', 'LAO', 'LA', 'Laos', 'AS', 
    'LAK', 'Kip', '856', '^(d{5})$', 'lo,fr,en', 
    '1655842'
  ), 
  (
    422, 'LB', 'LBN', 'LE', 'Lebanon', 'AS', 
    'LBP', 'Pound', '961', '^(d{4}(d{4})?)$', 
    'ar-LB,fr-LB,en,hy', '272103'
  ), 
  (
    426, 'LS', 'LSO', 'LT', 'Lesotho', 'AF', 
    'LSL', 'Loti', '266', '^(d{3})$', 
    'en-LS,st,zu,xh', '932692'
  ), 
  (
    428, 'LV', 'LVA', 'LG', 'Latvia', 'EU', 
    'LVL', 'Lat', '371', '^(?:LV)*(d{4})$', 
    'lv,ru,lt', '458258'
  ), 
  (
    430, 'LR', 'LBR', 'LI', 'Liberia', 'AF', 
    'LRD', 'Dollar', '231', '^(d{4})$', 
    'en-LR', '2275384'
  ), 
  (
    434, 'LY', 'LBY', 'LY', 'Libya', 'AF', 
    'LYD', 'Dinar', '218', '', 'ar-LY,it,en', 
    '2215636'
  ), 
  (
    438, 'LI', 'LIE', 'LS', 'Liechtenstein', 
    'EU', 'CHF', 'Franc', '423', '^(d{4})$', 
    'de-LI', '3042058'
  ), 
  (
    440, 'LT', 'LTU', 'LH', 'Lithuania', 
    'EU', 'LTL', 'Litas', '370', '^(?:LT)*(d{5})$', 
    'lt,ru,pl', '597427'
  ), 
  (
    442, 'LU', 'LUX', 'LU', 'Luxembourg', 
    'EU', 'EUR', 'Euro', '352', '^(d{4})$', 
    'lb,de-LU,fr-LU', '2960313'
  ), 
  (
    446, 'MO', 'MAC', 'MC', 'Macao', 'AS', 
    'MOP', 'Pataca', '853', '', 'zh,zh-MO', 
    '1821275'
  ), 
  (
    450, 'MG', 'MDG', 'MA', 'Madagascar', 
    'AF', 'MGA', 'Ariary', '261', '^(d{3})$', 
    'fr-MG,mg', '1062947'
  ), 
  (
    454, 'MW', 'MWI', 'MI', 'Malawi', 'AF', 
    'MWK', 'Kwacha', '265', '', 'ny,yao,tum,swk', 
    '927384'
  ), 
  (
    458, 'MY', 'MYS', 'MY', 'Malaysia', 
    'AS', 'MYR', 'Ringgit', '60', '^(d{5})$', 
    'ms-MY,en,zh,ta,te,ml,pa,th', '1733045'
  ), 
  (
    462, 'MV', 'MDV', 'MV', 'Maldives', 
    'AS', 'MVR', 'Rufiyaa', '960', '^(d{5})$', 
    'dv,en', '1282028'
  ), 
  (
    466, 'ML', 'MLI', 'ML', 'Mali', 'AF', 
    'XOF', 'Franc', '223', '', 'fr-ML,bm', 
    '2453866'
  ), 
  (
    470, 'MT', 'MLT', 'MT', 'Malta', 'EU', 
    'EUR', 'Euro', '356', '^([A-Z]{3}d{2}d?)$', 
    'mt,en-MT', '2562770'
  ), 
  (
    474, 'MQ', 'MTQ', 'MB', 'Martinique', 
    'NA', 'EUR', 'Euro', '596', '^(d{5})$', 
    'fr-MQ', '3570311'
  ), 
  (
    478, 'MR', 'MRT', 'MR', 'Mauritania', 
    'AF', 'MRO', 'Ouguiya', '222', '', 
    'ar-MR,fuc,snk,fr,mey,wo', '2378080'
  ), 
  (
    480, 'MU', 'MUS', 'MP', 'Mauritius', 
    'AF', 'MUR', 'Rupee', '230', '', 'en-MU,bho,fr', 
    '934292'
  ), 
  (
    484, 'MX', 'MEX', 'MX', 'Mexico', 'NA', 
    'MXN', 'Peso', '52', '^(d{5})$', 'es-MX', 
    '3996063'
  ), 
  (
    492, 'MC', 'MCO', 'MN', 'Monaco', 'EU', 
    'EUR', 'Euro', '377', '^(d{5})$', 
    'fr-MC,en,it', '2993457'
  ), 
  (
    496, 'MN', 'MNG', 'MG', 'Mongolia', 
    'AS', 'MNT', 'Tugrik', '976', '^(d{6})$', 
    'mn,ru', '2029969'
  ), 
  (
    498, 'MD', 'MDA', 'MD', 'Moldova', 'EU', 
    'MDL', 'Leu', '373', '^(?:MD)*(d{4})$', 
    'ro,ru,gag,tr', '617790'
  ), 
  (
    499, 'ME', 'MNE', 'MJ', 'Montenegro', 
    'EU', 'EUR', 'Euro', '381', '^(d{5})$', 
    'sr,hu,bs,sq,hr,rom', '3194884'
  ), 
  (
    500, 'MS', 'MSR', 'MH', 'Montserrat', 
    'NA', 'XCD', 'Dollar', '+1-664', '', 
    'en-MS', '3578097'
  ), 
  (
    504, 'MA', 'MAR', 'MO', 'Morocco', 'AF', 
    'MAD', 'Dirham', '212', '^(d{5})$', 
    'ar-MA,fr', '2542007'
  ), 
  (
    508, 'MZ', 'MOZ', 'MZ', 'Mozambique', 
    'AF', 'MZN', 'Meticail', '258', '^(d{4})$', 
    'pt-MZ,vmw', '1036973'
  ), 
  (
    512, 'OM', 'OMN', 'MU', 'Oman', 'AS', 
    'OMR', 'Rial', '968', '^(d{3})$', 
    'ar-OM,en,bal,ur', '286963'
  ), 
  (
    516, 'NA', 'NAM', 'WA', 'Namibia', 'AF', 
    'NAD', 'Dollar', '264', '', 'en-NA,af,de,hz,naq', 
    '3355338'
  ), 
  (
    520, 'NR', 'NRU', 'NR', 'Nauru', 'OC', 
    'AUD', 'Dollar', '674', '', 'na,en-NR', 
    '2110425'
  ), 
  (
    524, 'NP', 'NPL', 'NP', 'Nepal', 'AS', 
    'NPR', 'Rupee', '977', '^(d{5})$', 
    'ne,en', '1282988'
  ), 
  (
    528, 'NL', 'NLD', 'NL', 'Netherlands', 
    'EU', 'EUR', 'Euro', '31', '^(d{4}[A-Z]{2})$', 
    'nl-NL,fy-NL', '2750405'
  ), 
  (
    530, 'AN', 'ANT', 'NT', 'Netherlands Antilles', 
    'NA', 'ANG', 'Guilder', '599', '', 
    'nl-AN,en,es', '3513447'
  ), 
  (
    533, 'AW', 'ABW', 'AA', 'Aruba', 'NA', 
    'AWG', 'Guilder', '297', '', 'nl-AW,es,en', 
    '3577279'
  ), 
  (
    540, 'NC', 'NCL', 'NC', 'New Caledonia', 
    'OC', 'XPF', 'Franc', '687', '^(d{5})$', 
    'fr-NC', '2139685'
  ), 
  (
    548, 'VU', 'VUT', 'NH', 'Vanuatu', 'OC', 
    'VUV', 'Vatu', '678', '', 'bi,en-VU,fr-VU', 
    '2134431'
  ), 
  (
    554, 'NZ', 'NZL', 'NZ', 'New Zealand', 
    'OC', 'NZD', 'Dollar', '64', '^(d{4})$', 
    'en-NZ,mi', '2186224'
  ), 
  (
    558, 'NI', 'NIC', 'NU', 'Nicaragua', 
    'NA', 'NIO', 'Cordoba', '505', '^(d{7})$', 
    'es-NI,en', '3617476'
  ), 
  (
    562, 'NE', 'NER', 'NG', 'Niger', 'AF', 
    'XOF', 'Franc', '227', '^(d{4})$', 
    'fr-NE,ha,kr,dje', '2440476'
  ), 
  (
    566, 'NG', 'NGA', 'NI', 'Nigeria', 'AF', 
    'NGN', 'Naira', '234', '^(d{6})$', 
    'en-NG,ha,yo,ig,ff', '2328926'
  ), 
  (
    570, 'NU', 'NIU', 'NE', 'Niue', 'OC', 
    'NZD', 'Dollar', '683', '', 'niu,en-NU', 
    '4036232'
  ), 
  (
    574, 'NF', 'NFK', 'NF', 'Norfolk Island', 
    'OC', 'AUD', 'Dollar', '672', '', 'en-NF', 
    '2155115'
  ), 
  (
    578, 'NO', 'NOR', 'NO', 'Norway', 'EU', 
    'NOK', 'Krone', '47', '^(d{4})$', 
    'no,nb,nn', '3144096'
  ), 
  (
    580, 'MP', 'MNP', 'CQ', 'Northern Mariana Islands', 
    'OC', 'USD', 'Dollar', '+1-670', '', 
    'fil,tl,zh,ch-MP,en-MP', '4041467'
  ), 
  (
    581, 'UM', 'UMI', '', 'United States Minor Outlying Islands', 
    'OC', 'USD', 'Dollar ', '', '', 'en-UM', 
    '5854968'
  ), 
  (
    583, 'FM', 'FSM', 'FM', 'Micronesia', 
    'OC', 'USD', 'Dollar', '691', '^(d{5})$', 
    'en-FM,chk,pon,yap,kos,uli,woe,nkr,kpg', 
    '2081918'
  ), 
  (
    584, 'MH', 'MHL', 'RM', 'Marshall Islands', 
    'OC', 'USD', 'Dollar', '692', '', 'mh,en-MH', 
    '2080185'
  ), 
  (
    585, 'PW', 'PLW', 'PS', 'Palau', 'OC', 
    'USD', 'Dollar', '680', '^(96940)$', 
    'pau,sov,en-PW,tox,ja,fil,zh', 
    '1559582'
  ), 
  (
    586, 'PK', 'PAK', 'PK', 'Pakistan', 
    'AS', 'PKR', 'Rupee', '92', '^(d{5})$', 
    'ur-PK,en-PK,pa,sd,ps,brh', '1168579'
  ), 
  (
    591, 'PA', 'PAN', 'PM', 'Panama', 'NA', 
    'PAB', 'Balboa', '507', '', 'es-PA,en', 
    '3703430'
  ), 
  (
    598, 'PG', 'PNG', 'PP', 'Papua New Guinea', 
    'OC', 'PGK', 'Kina', '675', '^(d{3})$', 
    'en-PG,ho,meu,tpi', '2088628'
  ), 
  (
    600, 'PY', 'PRY', 'PA', 'Paraguay', 
    'SA', 'PYG', 'Guarani', '595', '^(d{4})$', 
    'es-PY,gn', '3437598'
  ), 
  (
    604, 'PE', 'PER', 'PE', 'Peru', 'SA', 
    'PEN', 'Sol', '51', '', 'es-PE,qu,ay', 
    '3932488'
  ), 
  (
    608, 'PH', 'PHL', 'RP', 'Philippines', 
    'AS', 'PHP', 'Peso', '63', '^(d{4})$', 
    'tl,en-PH,fil', '1694008'
  ), 
  (
    612, 'PN', 'PCN', 'PC', 'Pitcairn', 
    'OC', 'NZD', 'Dollar', '', '', 'en-PN', 
    '4030699'
  ), 
  (
    616, 'PL', 'POL', 'PL', 'Poland', 'EU', 
    'PLN', 'Zloty', '48', '^(d{5})$', 
    'pl', '798544'
  ), 
  (
    620, 'PT', 'PRT', 'PO', 'Portugal', 
    'EU', 'EUR', 'Euro', '351', '^(d{7})$', 
    'pt-PT,mwl', '2264397'
  ), 
  (
    624, 'GW', 'GNB', 'PU', 'Guinea-Bissau', 
    'AF', 'XOF', 'Franc', '245', '^(d{4})$', 
    'pt-GW,pov', '2372248'
  ), 
  (
    626, 'TL', 'TLS', 'TT', 'East Timor', 
    'OC', 'USD', 'Dollar', '670', '', 'tet,pt-TL,id,en', 
    '1966436'
  ), 
  (
    630, 'PR', 'PRI', 'RQ', 'Puerto Rico', 
    'NA', 'USD', 'Dollar', '+1-787 and 1-939', 
    '^(d{9})$', 'en-PR,es-PR', '4566966'
  ), 
  (
    634, 'QA', 'QAT', 'QA', 'Qatar', 'AS', 
    'QAR', 'Rial', '974', '', 'ar-QA,es', 
    '289688'
  ), 
  (
    638, 'RE', 'REU', 'RE', 'Reunion', 'AF', 
    'EUR', 'Euro', '262', '^((97)|(98)(4|7|8)d{2})$', 
    'fr-RE', '935317'
  ), 
  (
    642, 'RO', 'ROU', 'RO', 'Romania', 'EU', 
    'RON', 'Leu', '40', '^(d{6})$', 'ro,hu,rom', 
    '798549'
  ), 
  (
    643, 'RU', 'RUS', 'RS', 'Russia', 'EU', 
    'RUB', 'Ruble', '7', '^(d{6})$', 'ru-RU', 
    '2017370'
  ), 
  (
    646, 'RW', 'RWA', 'RW', 'Rwanda', 'AF', 
    'RWF', 'Franc', '250', '', 'rw,en-RW,fr-RW,sw', 
    '49518'
  ), 
  (
    652, 'BL', 'BLM', 'TB', 'Saint Barthélemy', 
    'NA', 'EUR', 'Euro', '590', '', 'fr', 
    '3578476'
  ), 
  (
    654, 'SH', 'SHN', 'SH', 'Saint Helena', 
    'AF', 'SHP', 'Pound', '290', '^(STHL1ZZ)$', 
    'en-SH', '3370751'
  ), 
  (
    659, 'KN', 'KNA', 'SC', 'Saint Kitts and Nevis', 
    'NA', 'XCD', 'Dollar', '+1-869', '', 
    'en-KN', '3575174'
  ), 
  (
    660, 'AI', 'AIA', 'AV', 'Anguilla', 
    'NA', 'XCD', 'Dollar', '+1-264', '', 
    'en-AI', '3573511'
  ), 
  (
    662, 'LC', 'LCA', 'ST', 'Saint Lucia', 
    'NA', 'XCD', 'Dollar', '+1-758', '', 
    'en-LC', '3576468'
  ), 
  (
    663, 'MF', 'MAF', 'RN', 'Saint Martin', 
    'NA', 'EUR', 'Euro', '590', '', 'fr', 
    '3578421'
  ), 
  (
    666, 'PM', 'SPM', 'SB', 'Saint Pierre and Miquelon', 
    'NA', 'EUR', 'Euro', '508', '^(97500)$', 
    'fr-PM', '3424932'
  ), 
  (
    670, 'VC', 'VCT', 'VC', 'Saint Vincent and the Grenadines', 
    'NA', 'XCD', 'Dollar', '+1-784', '', 
    'en-VC,fr', '3577815'
  ), 
  (
    674, 'SM', 'SMR', 'SM', 'San Marino', 
    'EU', 'EUR', 'Euro', '378', '^(4789d)$', 
    'it-SM', '3168068'
  ), 
  (
    678, 'ST', 'STP', 'TP', 'Sao Tome and Principe', 
    'AF', 'STD', 'Dobra', '239', '', 'pt-ST', 
    '2410758'
  ), 
  (
    682, 'SA', 'SAU', 'SA', 'Saudi Arabia', 
    'AS', 'SAR', 'Rial', '966', '^(d{5})$', 
    'ar-SA', '102358'
  ), 
  (
    686, 'SN', 'SEN', 'SG', 'Senegal', 'AF', 
    'XOF', 'Franc', '221', '^(d{5})$', 
    'fr-SN,wo,fuc,mnk', '2245662'
  ), 
  (
    688, 'RS', 'SRB', 'RB', 'Serbia', 'EU', 
    'RSD', 'Dinar', '381', '^(d{6})$', 
    'sr,hu,bs,rom', '6290252'
  ), 
  (
    690, 'SC', 'SYC', 'SE', 'Seychelles', 
    'AF', 'SCR', 'Rupee', '248', '', 'en-SC,fr-SC', 
    '241170'
  ), 
  (
    694, 'SL', 'SLE', 'SL', 'Sierra Leone', 
    'AF', 'SLL', 'Leone', '232', '', 'en-SL,men,tem', 
    '2403846'
  ), 
  (
    702, 'SG', 'SGP', 'SN', 'Singapore', 
    'AS', 'SGD', 'Dollar', '65', '^(d{6})$', 
    'cmn,en-SG,ms-SG,ta-SG,zh-SG', 
    '1880251'
  ), 
  (
    703, 'SK', 'SVK', 'LO', 'Slovakia', 
    'EU', 'EUR', 'Euro', '421', '^(d{5})$', 
    'sk,hu', '3057568'
  ), 
  (
    704, 'VN', 'VNM', 'VM', 'Vietnam', 'AS', 
    'VND', 'Dong', '84', '^(d{6})$', 'vi,en,fr,zh,km', 
    '1562822'
  ), 
  (
    705, 'SI', 'SVN', 'SI', 'Slovenia', 
    'EU', 'EUR', 'Euro', '386', '^(?:SI)*(d{4})$', 
    'sl,sh', '3190538'
  ), 
  (
    706, 'SO', 'SOM', 'SO', 'Somalia', 'AF', 
    'SOS', 'Shilling', '252', '^([A-Z]{2}d{5})$', 
    'so-SO,ar-SO,it,en-SO', '51537'
  ), 
  (
    710, 'ZA', 'ZAF', 'SF', 'South Africa', 
    'AF', 'ZAR', 'Rand', '27', '^(d{4})$', 
    'zu,xh,af,nso,en-ZA,tn,st,ts', 
    '953987'
  ), 
  (
    716, 'ZW', 'ZWE', 'ZI', 'Zimbabwe', 
    'AF', 'ZWL', 'Dollar', '263', '', 'en-ZW,sn,nr,nd', 
    '878675'
  ), 
  (
    724, 'ES', 'ESP', 'SP', 'Spain', 'EU', 
    'EUR', 'Euro', '34', '^(d{5})$', 'es-ES,ca,gl,eu', 
    '2510769'
  ), 
  (
    732, 'EH', 'ESH', 'WI', 'Western Sahara', 
    'AF', 'MAD', 'Dirham', '212', '', 'ar,mey', 
    '2461445'
  ), 
  (
    736, 'SD', 'SDN', 'SU', 'Sudan', 'AF', 
    'SDG', 'Dinar', '249', '^(d{5})$', 
    'ar-SD,en,fia', '366755'
  ), 
  (
    740, 'SR', 'SUR', 'NS', 'Suriname', 
    'SA', 'SRD', 'Dollar', '597', '', 'nl-SR,en,srn,hns,jv', 
    '3382998'
  ), 
  (
    744, 'SJ', 'SJM', 'SV', 'Svalbard and Jan Mayen', 
    'EU', 'NOK', 'Krone', '47', '', 'no,ru', 
    '607072'
  ), 
  (
    748, 'SZ', 'SWZ', 'WZ', 'Swaziland', 
    'AF', 'SZL', 'Lilangeni', '268', '^([A-Z]d{3})$', 
    'en-SZ,ss-SZ', '934841'
  ), 
  (
    752, 'SE', 'SWE', 'SW', 'Sweden', 'EU', 
    'SEK', 'Krona', '46', '^(?:SE)*(d{5})$', 
    'sv-SE,se,sma,fi-SE', '2661886'
  ), 
  (
    756, 'CH', 'CHE', 'SZ', 'Switzerland', 
    'EU', 'CHF', 'Franc', '41', '^(d{4})$', 
    'de-CH,fr-CH,it-CH,rm', '2658434'
  ), 
  (
    760, 'SY', 'SYR', 'SY', 'Syria', 'AS', 
    'SYP', 'Pound', '963', '', 'ar-SY,ku,hy,arc,fr,en', 
    '163843'
  ), 
  (
    762, 'TJ', 'TJK', 'TI', 'Tajikistan', 
    'AS', 'TJS', 'Somoni', '992', '^(d{6})$', 
    'tg,ru', '1220409'
  ), 
  (
    764, 'TH', 'THA', 'TH', 'Thailand', 
    'AS', 'THB', 'Baht', '66', '^(d{5})$', 
    'th,en', '1605651'
  ), 
  (
    768, 'TG', 'TGO', 'TO', 'Togo', 'AF', 
    'XOF', 'Franc', '228', '', 'fr-TG,ee,hna,kbp,dag,ha', 
    '2363686'
  ), 
  (
    772, 'TK', 'TKL', 'TL', 'Tokelau', 'OC', 
    'NZD', 'Dollar', '690', '', 'tkl,en-TK', 
    '4031074'
  ), 
  (
    776, 'TO', 'TON', 'TN', 'Tonga', 'OC', 
    'TOP', 'Pa''anga', '676', '', 'to,en-TO', 
    '4032283'
  ), 
  (
    780, 'TT', 'TTO', 'TD', 'Trinidad and Tobago', 
    'NA', 'TTD', 'Dollar', '+1-868', '', 
    'en-TT,hns,fr,es,zh', '3573591'
  ), 
  (
    784, 'AE', 'ARE', 'AE', 'United Arab Emirates', 
    'AS', 'AED', 'Dirham', '971', '', 'ar-AE,fa,en,hi,ur', 
    '290557'
  ), 
  (
    788, 'TN', 'TUN', 'TS', 'Tunisia', 'AF', 
    'TND', 'Dinar', '216', '^(d{4})$', 
    'ar-TN,fr', '2464461'
  ), 
  (
    792, 'TR', 'TUR', 'TU', 'Turkey', 'AS', 
    'TRY', 'Lira', '90', '^(d{5})$', 'tr-TR,ku,diq,az,av', 
    '298795'
  ), 
  (
    795, 'TM', 'TKM', 'TX', 'Turkmenistan', 
    'AS', 'TMT', 'Manat', '993', '^(d{6})$', 
    'tk,ru,uz', '1218197'
  ), 
  (
    796, 'TC', 'TCA', 'TK', 'Turks and Caicos Islands', 
    'NA', 'USD', 'Dollar', '+1-649', '^(TKCA 1ZZ)$', 
    'en-TC', '3576916'
  ), 
  (
    798, 'TV', 'TUV', 'TV', 'Tuvalu', 'OC', 
    'AUD', 'Dollar', '688', '', 'tvl,en,sm,gil', 
    '2110297'
  ), 
  (
    800, 'UG', 'UGA', 'UG', 'Uganda', 'AF', 
    'UGX', 'Shilling', '256', '', 'en-UG,lg,sw,ar', 
    '226074'
  ), 
  (
    804, 'UA', 'UKR', 'UP', 'Ukraine', 'EU', 
    'UAH', 'Hryvnia', '380', '^(d{5})$', 
    'uk,ru-UA,rom,pl,hu', '690791'
  ), 
  (
    807, 'MK', 'MKD', 'MK', 'Macedonia', 
    'EU', 'MKD', 'Denar', '389', '^(d{4})$', 
    'mk,sq,tr,rmm,sr', '718075'
  ), 
  (
    818, 'EG', 'EGY', 'EG', 'Egypt', 'AF', 
    'EGP', 'Pound', '20', '^(d{5})$', 
    'ar-EG,en,fr', '357994'
  ), 
  (
    826, 'GB', 'GBR', 'UK', 'United Kingdom', 
    'EU', 'GBP', 'Pound', '44', '^(([A-Z]d{2}[A-Z]{2})|([A-Z]d{3}[A-Z]{2})|([A', 
    'en-GB,cy-GB,gd', '2635167'
  ), 
  (
    831, 'GG', 'GGY', 'GK', 'Guernsey', 
    'EU', 'GBP', 'Pound', '+44-1481', 
    '^(([A-Z]d{2}[A-Z]{2})|([A-Z]d{3}[A-Z]{2})|([A', 
    'en,fr', '3042362'
  ), 
  (
    832, 'JE', 'JEY', 'JE', 'Jersey', 'EU', 
    'GBP', 'Pound', '+44-1534', '^(([A-Z]d{2}[A-Z]{2})|([A-Z]d{3}[A-Z]{2})|([A', 
    'en,pt', '3042142'
  ), 
  (
    833, 'IM', 'IMN', 'IM', 'Isle of Man', 
    'EU', 'GBP', 'Pound', '+44-1624', 
    '^(([A-Z]d{2}[A-Z]{2})|([A-Z]d{3}[A-Z]{2})|([A', 
    'en,gv', '3042225'
  ), 
  (
    834, 'TZ', 'TZA', 'TZ', 'Tanzania', 
    'AF', 'TZS', 'Shilling', '255', '', 
    'sw-TZ,en,ar', '149590'
  ), 
  (
    840, 'US', 'USA', 'US', 'United States', 
    'NA', 'USD', 'Dollar', '1', '^(d{9})$', 
    'en-US,es-US,haw', '6252001'
  ), 
  (
    850, 'VI', 'VIR', 'VQ', 'U.S. Virgin Islands', 
    'NA', 'USD', 'Dollar', '+1-340', '', 
    'en-VI', '4796775'
  ), 
  (
    854, 'BF', 'BFA', 'UV', 'Burkina Faso', 
    'AF', 'XOF', 'Franc', '226', '', 'fr-BF', 
    '2361809'
  ), 
  (
    855, 'XK', 'XKX', 'KV', 'Kosovo', 'EU', 
    'EUR', 'Euro', '', '', 'sq,sr', '831053'
  ), 
  (
    858, 'UY', 'URY', 'UY', 'Uruguay', 'SA', 
    'UYU', 'Peso', '598', '^(d{5})$', 
    'es-UY', '3439705'
  ), 
  (
    860, 'UZ', 'UZB', 'UZ', 'Uzbekistan', 
    'AS', 'UZS', 'Som', '998', '^(d{6})$', 
    'uz,ru,tg', '1512440'
  ), 
  (
    862, 'VE', 'VEN', 'VE', 'Venezuela', 
    'SA', 'VEF', 'Bolivar', '58', '^(d{4})$', 
    'es-VE', '3625428'
  ), 
  (
    876, 'WF', 'WLF', 'WF', 'Wallis and Futuna', 
    'OC', 'XPF', 'Franc', '681', '^(986d{2})$', 
    'wls,fud,fr-WF', '4034749'
  ), 
  (
    882, 'WS', 'WSM', 'WS', 'Samoa', 'OC', 
    'WST', 'Tala', '685', '', 'sm,en-WS', 
    '4034894'
  ), 
  (
    887, 'YE', 'YEM', 'YM', 'Yemen', 'AS', 
    'YER', 'Rial', '967', '', 'ar-YE', 
    '69543'
  ), 
  (
    891, 'CS', 'SCG', 'YI', 'Serbia and Montenegro', 
    'EU', 'RSD', 'Dinar', '381', '^(d{5})$', 
    'cu,hu,sq,sr', '863038'
  ), 
  (
    894, 'ZM', 'ZMB', 'ZA', 'Zambia', 'AF', 
    'ZMK', 'Kwacha', '260', '^(d{5})$', 
    'en-ZM,bem,loz,lun,lue,ny,toi', 
    '895949'
  );
