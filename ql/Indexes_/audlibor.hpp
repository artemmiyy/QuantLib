/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2003, 2004, 2005, 2006 StatPro Italia srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file audlibor.hpp
    \brief %AUD %LIBOR rate
*/

#ifndef quantlib_aud_libor_hpp
#define quantlib_aud_libor_hpp

#include <ql/Indexes/libor.hpp>
#include <ql/Calendars/unitedkingdom.hpp>
#include <ql/Calendars/australia.hpp>
#include <ql/DayCounters/actual360.hpp>
#include <ql/Currencies/oceania.hpp>

namespace QuantLib {

    //! %AUD %LIBOR rate
    /*! Australian Dollar LIBOR fixed by BBA.

        See <http://www.bba.org.uk/bba/jsp/polopoly.jsp?d=225&a=1414>.
    */
    class AUDLibor : public Libor {
      public:
        AUDLibor(const Period& tenor,
                 const Handle<YieldTermStructure>& h =
                                     Handle<YieldTermStructure>(),
                 BusinessDayConvention convention = ModifiedFollowing,
                 bool endOfMonth = true,
                 Natural settlementDays = 2)
        : Libor("AUDLibor", tenor, settlementDays, AUDCurrency(),
                UnitedKingdom(UnitedKingdom::Exchange), Australia(),
                convention, endOfMonth, Actual360(), h) {}
    };

}


#endif