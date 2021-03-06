// bslmf_islvaluereference.t.cpp                                      -*-C++-*-
#include <bslmf_islvaluereference.h>

#include <bsls_bsltestutil.h>

#include <stdio.h>   // 'printf'
#include <stdlib.h>  // 'atoi'

using namespace BloombergLP;

//=============================================================================
//                                TEST PLAN
//-----------------------------------------------------------------------------
//                                Overview
//                                --------
// The component under test defines a meta-function,
// 'bsl::is_lvalue_reference', that determines whether a template parameter
// type is an lvalue reference type.  Thus, we need to ensure that the value
// returned by this meta-function is correct for each possible category of
// types.
//
// ----------------------------------------------------------------------------
// PUBLIC CLASS DATA
// [ 1] bsl::is_lvalue_reference::value
//
// ----------------------------------------------------------------------------
// [ 2] USAGE EXAMPLE

//=============================================================================
//                  STANDARD BDE ASSERT TEST MACRO
//-----------------------------------------------------------------------------

static int testStatus = 0;

void aSsErT(bool b, const char *s, int i)
{
    if (b) {
        printf("Error " __FILE__ "(%d): %s    (failed)\n", i, s);
        if (testStatus >= 0 && testStatus <= 100) ++testStatus;
    }
}

#define ASSERT(X) { aSsErT(!(X), #X, __LINE__); }

//=============================================================================
//                       STANDARD BDE TEST DRIVER MACROS
//-----------------------------------------------------------------------------
#define LOOP_ASSERT  BSLS_BSLTESTUTIL_LOOP_ASSERT
#define LOOP2_ASSERT BSLS_BSLTESTUTIL_LOOP2_ASSERT
#define LOOP3_ASSERT BSLS_BSLTESTUTIL_LOOP3_ASSERT
#define LOOP4_ASSERT BSLS_BSLTESTUTIL_LOOP4_ASSERT
#define LOOP5_ASSERT BSLS_BSLTESTUTIL_LOOP5_ASSERT
#define LOOP6_ASSERT BSLS_BSLTESTUTIL_LOOP6_ASSERT

#define Q   BSLS_BSLTESTUTIL_Q   // Quote identifier literally.
#define P   BSLS_BSLTESTUTIL_P   // Print identifier and value.
#define P_  BSLS_BSLTESTUTIL_P_  // P(X) without '\n'.
#define T_  BSLS_BSLTESTUTIL_T_  // Print a tab (w/o newline).
#define L_  BSLS_BSLTESTUTIL_L_  // current Line number

//=============================================================================
//                  GLOBAL TYPEDEFS/CONSTANTS FOR TESTING
//-----------------------------------------------------------------------------

namespace {

enum EnumTestType {
    // This user-defined 'enum' type is intended to be used for testing as the
    // template parameter 'TYPE' of 'bsl::is_lvalue_reference'.
};

struct StructTestType {
    // This user-defined 'struct' type is intended to be used for testing as
    // the template parameter 'TYPE' of 'bsl::is_lvalue_reference'.
};

union UnionTestType {
    // This user-defined 'union' type is intended to be used for testing as the
    // template parameter 'TYPE' of 'bsl::is_lvalue_reference'.
};

class BaseClassTestType {
    // This user-defined base class type is intended to be used for testing as
    // the template parameter 'TYPE' of 'bsl::is_lvalue_reference'.
};

class DerivedClassTestType : public BaseClassTestType {
    // This user-defined derived class type is intended to be used for testing
    // as the template parameter 'TYPE' of 'bsl::is_lvalue_reference'.
};

typedef int (StructTestType::*MethodPtrTestType) ();
    // This pointer to non-static member function type is intended to be used
    // for testing as the template parameter 'TYPE' of
    // 'bsl::is_lvalue_reference'.

typedef void (*FunctionPtrTestType) ();
    // This function pointer type is intended to be used for testing as the
    // template parameter 'TYPE' of 'bsl::is_lvalue_reference'.

typedef int StructTestType::*PMD;
    // This pointer to member object type is intended to be used for testing as
    // the template parameter 'TYPE' of 'bsl::is_lvalue_reference'.

struct Incomplete;
    // This incomplete 'struct' type is intended to be used for testing as the
    // template parameter 'TYPE' of 'bsl::is_lvalue_reference'.

}  // close unnamed namespace

#define TYPE_ASSERT_CVQ_PREFIX(META_FUNC, TYPE, result)       \
    ASSERT(result == META_FUNC<TYPE>::value);                 \
    ASSERT(result == META_FUNC<const TYPE>::value);           \
    ASSERT(result == META_FUNC<volatile TYPE>::value);        \
    ASSERT(result == META_FUNC<const volatile TYPE>::value);

#define TYPE_ASSERT_CVQ_SUFFIX(META_FUNC, TYPE, result)       \
    ASSERT(result == META_FUNC<TYPE>::value);                 \
    ASSERT(result == META_FUNC<TYPE const>::value);           \
    ASSERT(result == META_FUNC<TYPE volatile>::value);        \
    ASSERT(result == META_FUNC<TYPE const volatile>::value);

#define TYPE_ASSERT_CVQ_REF(META_FUNC, TYPE, result)           \
    ASSERT(result == META_FUNC<TYPE&>::value);                 \
    ASSERT(result == META_FUNC<TYPE const&>::value);           \
    ASSERT(result == META_FUNC<TYPE volatile&>::value);        \
    ASSERT(result == META_FUNC<TYPE const volatile&>::value);

#define TYPE_ASSERT_CVQ(META_FUNC, TYPE, result)                     \
    TYPE_ASSERT_CVQ_PREFIX(META_FUNC, TYPE, result);                 \
    TYPE_ASSERT_CVQ_PREFIX(META_FUNC, TYPE const, result);           \
    TYPE_ASSERT_CVQ_PREFIX(META_FUNC, TYPE volatile, result);        \
    TYPE_ASSERT_CVQ_PREFIX(META_FUNC, TYPE const volatile, result);  \

//=============================================================================
//                              MAIN PROGRAM
//-----------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    int test = argc > 1 ? atoi(argv[1]) : 0;
    int verbose = argc > 2;
    int veryVerbose = argc > 3;

    (void) veryVerbose;

    printf("TEST " __FILE__ " CASE %d\n", test);

    switch (test) { case 0:
      case 2: {
        // --------------------------------------------------------------------
        // USAGE EXAMPLE
        //
        // Concerns:
        //: 1 The usage example provided in the component header file compiles,
        //:   links, and runs as shown.
        //
        // Plan:
        //: 1 Incorporate usage example from header into test driver, remove
        //:   leading comment characters, and replace 'assert' with 'ASSERT'.
        //:   (C-1)
        //
        // Testing:
        //   USAGE EXAMPLE
        // --------------------------------------------------------------------

        if (verbose) printf("USAGE EXAMPLE\n"
                            "=============\n");

///Usage
///-----
// In this section we show intended use of this component.
//
///Example 1: Verify Lvalue Reference Types
/// - - - - - - - - - - - - - - - - - - - -
// Suppose that we want to assert whether a set of types are lvalue reference
// types.
//
// Now, we instantiate the 'bsl::is_lvalue_reference' template for both a
// non-reference type and a reference type, and assert the 'value' static data
// member of each instantiation:
//..
    ASSERT(false == bsl::is_lvalue_reference<int>::value);
    ASSERT(true  == bsl::is_lvalue_reference<int&>::value);
//..

      } break;
      case 1: {
        // --------------------------------------------------------------------
        // 'bsl::is_lvalue_reference::value'
        //   Ensure that the static data member 'value' of
        //   'bsl::is_lvalue_reference' instantiations having various (template
        //   parameter) 'TYPE's has the correct value.
        //
        // Concerns:
        //: 1 'is_lvalue_reference::value' is 'false' when 'TYPE' is a
        //:   (possibly cv-qualified) primitive type.
        //:
        //: 2 'is_lvalue_reference::value' is 'false' when 'TYPE' is a
        //:   (possibly cv-qualified) user-defined type.
        //:
        //: 3 'is_lvalue_reference::value' is 'false' when 'TYPE' is a
        //:   (possibly cv-qualified) pointer type.
        //:
        //: 4 'is_lvalue_reference::value' is 'true' when 'TYPE' is an
        //:   (possibly cv-qualified) lvalue reference type.
        //:
        //: 5 'is_lvalue_reference::value' is 'false' when 'TYPE' is a
        //:   (possibly cv-qualified) function type.
        //
        // Plan:
        //   Verify that 'bsl::is_lvalue_reference::value' has the correct
        //   value for each (template parameter) 'TYPE' in the concerns.
        //
        // Testing:
        //   bsl::is_lvalue_reference::value
        // --------------------------------------------------------------------

        if (verbose)  printf("'bsl::is_lvalue_reference::value'\n"
                             "=================================\n");

        // C-1
        TYPE_ASSERT_CVQ_SUFFIX(bsl::is_lvalue_reference, void, false);
        TYPE_ASSERT_CVQ_SUFFIX(bsl::is_lvalue_reference, int,  false);

        // C-2
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_lvalue_reference, EnumTestType,         false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_lvalue_reference, StructTestType,       false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_lvalue_reference, UnionTestType,        false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_lvalue_reference, BaseClassTestType,    false);
        TYPE_ASSERT_CVQ_SUFFIX(
                        bsl::is_lvalue_reference, DerivedClassTestType, false);

        // C-3
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, int*,                       false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, StructTestType*,            false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, int StructTestType::*,      false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, int StructTestType::* *,    false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, UnionTestType*,             false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, PMD BaseClassTestType::*,   false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, PMD BaseClassTestType::* *, false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, BaseClassTestType*,         false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, DerivedClassTestType*,      false);
        TYPE_ASSERT_CVQ(
                  bsl::is_lvalue_reference, Incomplete*,                false);
        TYPE_ASSERT_CVQ_SUFFIX(
                         bsl::is_lvalue_reference, MethodPtrTestType,   false);
        TYPE_ASSERT_CVQ_SUFFIX(
                         bsl::is_lvalue_reference, FunctionPtrTestType, false);

        // C-4
        TYPE_ASSERT_CVQ_REF(bsl::is_lvalue_reference, int,  true);

        TYPE_ASSERT_CVQ_REF(
                         bsl::is_lvalue_reference, EnumTestType,         true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_lvalue_reference, StructTestType,       true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_lvalue_reference, UnionTestType,        true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_lvalue_reference, BaseClassTestType,    true);
        TYPE_ASSERT_CVQ_REF(
                         bsl::is_lvalue_reference, DerivedClassTestType, true);

        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, int*,                     true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, StructTestType*,          true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, int StructTestType::*,    true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, int StructTestType::* *,  true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, UnionTestType*,           true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, PMD BaseClassTestType::*, true);
        TYPE_ASSERT_CVQ_REF(
                   bsl::is_lvalue_reference, PMD BaseClassTestType::* *, true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, BaseClassTestType*,       true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, DerivedClassTestType*,    true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, Incomplete*,              true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, MethodPtrTestType,        true);
        TYPE_ASSERT_CVQ_REF(
                     bsl::is_lvalue_reference, FunctionPtrTestType,      true);

        // C-5
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_lvalue_reference, int  (int),  false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_lvalue_reference, void (void), false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_lvalue_reference, int  (void), false);
        TYPE_ASSERT_CVQ_PREFIX(bsl::is_lvalue_reference, void (int),  false);
      } break;
      default: {
        fprintf(stderr, "WARNING: CASE `%d' NOT FOUND.\n", test);
        testStatus = -1;
      }
    }

    if (testStatus > 0) {
        fprintf(stderr, "Error, non-zero test status = %d.\n", testStatus);
    }
    return testStatus;
}

// ----------------------------------------------------------------------------
// Copyright 2013 Bloomberg Finance L.P.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ----------------------------- END-OF-FILE ----------------------------------
