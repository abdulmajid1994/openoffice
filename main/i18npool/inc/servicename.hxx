/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/


/* 
Service Name
  com.sun.star.i18n.Transliteration     ... dispatching UNO object and generic methods
  com.sun.star.i18n.Transliteration.u2l ... upper to lower
  com.sun.star.i18n.Transliteration.l2u ... lower to upper
  com.sun.star.i18n.Transliteration.caseignore ... case ignore
  com.sun.star.i18n.Transliteration.l10n ... other

  We have to adopt different service name for internal UNO objects.
  Case realted functionality vary depending on Locale.


Implementation Name
  For geneic service: com.sun.star.i18n.Transliteration,
         com.sun.star.i18n.Transliteration

  com.sun.star.i18n.Transliteration.u2l
  com.sun.star.i18n.Transliteration.l2u
  com.sun.star.i18n.Transliteration.caseignore
  For these there services above, 

   	  com.sun.star.i18n.Transliteration.ja_JP
                                            ^^^^^
					    Locale name
                                            
  For com.sun.star.i18n.l10n.Transliteration service,
   	  com.sun.star.i18n.Transliteration.HALFWIDTH_FULLWIDTH,
   	  com.sun.star.i18n.Transliteration.FULLWIDTH_HALFWIDTH,
   	  com.sun.star.i18n.Transliteration.IGNORE_WIDTH,
   	  com.sun.star.i18n.Transliteration.KATAKANA_HIRAGANA,
   	  com.sun.star.i18n.Transliteration.HIRAGANA_KATAKANA,
   	  com.sun.star.i18n.Transliteration.IGNORE_KANA,

          ... These objects above can be used in every Locale context.

*/          


#ifndef _I18N_SERVICENAME_HXX_
#define _I18N_SERVICENAME_HXX_



#define	TRLT_SERVICELNAME "com.sun.star.i18n.Transliteration"
#define	TRLT_SERVICELNAME_PREFIX TRLT_SERVICELNAME "."
#define	TRLT_SERVICELNAME_U2L	TRLT_SERVICELNAME_PREFIX "u2l"
#define	TRLT_SERVICELNAME_L2U	TRLT_SERVICELNAME_PREFIX "l2u"
#define	TRLT_SERVICELNAME_CASEIGNORE TRLT_SERVICELNAME_PREFIX "caseignore"
#define	TRLT_SERVICELNAME_L10N	TRLT_SERVICELNAME_PREFIX "l10n"

#define	TRLT_IMPLNAME "com.sun.star.i18n.Transliteration"
#define	TRLT_IMPLNAME_PREFIX_LEN	34
#define	TRLT_IMPLNAME_PREFIX "com.sun.star.i18n.Transliteration."
//	 		      1...5...901...5...901...5...901..4  --> 34

#define	TRLT_IMPLNAME_L10N  TRLT_IMPLNAME_PREFIX "l10n"
#define	TRLT_IMPLNAME_FH  TRLT_IMPLNAME_PREFIX "FULLWIDTH_HALFWIDTH" // for test
#define	TRLT_IMPLNAME_Ja_JP TRLT_IMPLNAME_PREFIX "ja_JP"

#endif
