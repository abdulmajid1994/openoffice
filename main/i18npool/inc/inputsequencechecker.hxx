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


#ifndef _I18N_INPUTCHECKER_HXX_
#define _I18N_INPUTCHECKER_HXX_

#include <comphelper/processfactory.hxx>
#include <cppuhelper/implbase2.hxx> // helper for implementations
#include <com/sun/star/lang/XMultiServiceFactory.hpp>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/i18n/XExtendedInputSequenceChecker.hpp>

#include <vector>

namespace com { namespace sun { namespace star { namespace i18n {

//	----------------------------------------------------
//	class InputSequenceCheckerImpl
//	----------------------------------------------------
class InputSequenceCheckerImpl : public cppu::WeakImplHelper2
<
	com::sun::star::i18n::XExtendedInputSequenceChecker,
	com::sun::star::lang::XServiceInfo
>
{
public:
	InputSequenceCheckerImpl( const com::sun::star::uno::Reference < com::sun::star::lang::XMultiServiceFactory >& rxMSF );
	InputSequenceCheckerImpl();
	~InputSequenceCheckerImpl();

	virtual sal_Bool SAL_CALL checkInputSequence(const rtl::OUString& Text, sal_Int32 nStartPos,
		sal_Unicode inputChar, sal_Int16 inputCheckMode) throw(com::sun::star::uno::RuntimeException);

	virtual sal_Int32 SAL_CALL correctInputSequence(rtl::OUString& Text, sal_Int32 nStartPos,
		sal_Unicode inputChar, sal_Int16 inputCheckMode) throw(com::sun::star::uno::RuntimeException);

	//XServiceInfo
	virtual rtl::OUString SAL_CALL getImplementationName() throw( com::sun::star::uno::RuntimeException );
	virtual sal_Bool SAL_CALL supportsService(const rtl::OUString& ServiceName) 
		throw( com::sun::star::uno::RuntimeException );
	virtual com::sun::star::uno::Sequence< rtl::OUString > SAL_CALL getSupportedServiceNames()
		throw( com::sun::star::uno::RuntimeException );

protected:
	sal_Int16 checkMode;
	const sal_Char *serviceName;

private :
	struct lookupTableItem {
	    lookupTableItem(const sal_Char* rLanguage, const com::sun::star::uno::Reference < com::sun::star::i18n::XExtendedInputSequenceChecker >& rxISC) :
			aLanguage(rLanguage), xISC(rxISC) {}
	    const sal_Char* aLanguage;
	    com::sun::star::uno::Reference < com::sun::star::i18n::XExtendedInputSequenceChecker > xISC;
	};
	std::vector<lookupTableItem*> lookupTable;
	lookupTableItem *cachedItem;

	com::sun::star::uno::Reference < com::sun::star::lang::XMultiServiceFactory > xMSF;

	com::sun::star::uno::Reference< com::sun::star::i18n::XExtendedInputSequenceChecker >& SAL_CALL getInputSequenceChecker(sal_Char* rLanguage)
		throw (com::sun::star::uno::RuntimeException);
	sal_Char* SAL_CALL getLanguageByScripType(sal_Unicode cChar, sal_Unicode nChar);
};

} } } } 

#endif // _I18N_BREAKITERATOR_HXX_
