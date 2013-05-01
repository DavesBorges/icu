/*
*****************************************************************************************
* Copyright (C) 2013, International Business Machines Corporation and others.
* All Rights Reserved.
*****************************************************************************************
*/

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "unicode/uregion.h"
#include "unicode/region.h"
#include "unicode/uenum.h"

U_NAMESPACE_USE


U_CAPI const URegion* U_EXPORT2
uregion_getRegionFromCode(const char *regionCode, UErrorCode *status)
{
    return (URegion*)Region::getInstance(regionCode, *status);
}


U_CAPI const URegion* U_EXPORT2
uregion_getRegionFromNumericCode (int32_t code, UErrorCode *status)
{
    return (URegion*)Region::getInstance(code, *status);
}


U_CAPI UEnumeration* U_EXPORT2
uregion_getAvailable(URegionType type, UErrorCode *status)
{
    return uenum_openFromStringEnumeration( Region::getAvailable(type), status );
}


U_CAPI UBool U_EXPORT2
uregion_isEqualTo(const URegion* uregion, const URegion* otherRegion)
{
    return ( (Region*)uregion == (Region*)otherRegion );
}


U_CAPI const URegion* U_EXPORT2
uregion_getContainingRegion(const URegion* uregion)
{
    return (URegion*)((Region*)uregion)->getContainingRegion();
}


U_CAPI const URegion* U_EXPORT2
uregion_getContainingRegionOfType(const URegion* uregion, URegionType type)
{
    return (URegion*)((Region*)uregion)->getContainingRegion(type);
}


U_CAPI UEnumeration* U_EXPORT2
uregion_getContainedRegions(const URegion* uregion, UErrorCode *status)
{
    return uenum_openFromStringEnumeration( ((Region*)uregion)->getContainedRegions(), status);
}


U_CAPI UEnumeration* U_EXPORT2
uregion_getContainedRegionsOfType(const URegion* uregion, URegionType type, UErrorCode *status)
{
    return uenum_openFromStringEnumeration( ((Region*)uregion)->getContainedRegions(type), status);
}


U_CAPI UBool U_EXPORT2
uregion_contains(const URegion* uregion, const URegion* otherRegion)
{
    return ((Region*)uregion)->contains(*((Region*)otherRegion));
}


U_CAPI UEnumeration* U_EXPORT2
uregion_getPreferredValues(const URegion* uregion, UErrorCode *status)
{
    return uenum_openFromStringEnumeration( ((Region*)uregion)->getPreferredValues(), status);
}


U_CAPI const char* U_EXPORT2
uregion_getRegionCode(const URegion* uregion)
{
    return ((Region*)uregion)->getRegionCode();
}


U_CAPI int32_t U_EXPORT2
uregion_getNumericCode(const URegion* uregion)
{
    return ((Region*)uregion)->getNumericCode();
}


U_CAPI URegionType U_EXPORT2
uregion_getType(const URegion* uregion)
{
    return ((Region*)uregion)->getType();
}


#endif /* #if !UCONFIG_NO_FORMATTING */