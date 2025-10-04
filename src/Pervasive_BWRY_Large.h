///
/// @file Pervasive_BWRY_Large.h
/// @brief Driver for BWRY large screens
///
/// @details Project Pervasive Displays Library Suite
///
/// @version 904
///
/// @copyright (c) Pervasive Displays, 2010-2025
/// @copyright All rights reserved
/// @copyright For exclusive use with Pervasive Displays screens
///
/// * Basic edition: for hobbyists and for basic usage
/// @n Creative Commons Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)
/// @see https://creativecommons.org/licenses/by-sa/4.0/
///
/// @n Consider the Evaluation or Commercial editions for professionals or organisations and for commercial usage
///
/// * Evaluation edition: for professionals or organisations, evaluation only, no commercial usage
/// @n All rights reserved
///
/// * Commercial edition: for professionals or organisations, commercial usage
/// @n All rights reserved
///
/// * Viewer edition: for professionals or organisations
/// @n All rights reserved
///
/// * Documentation
/// @n All rights reserved
///
/// @see Application notes
/// *
///

// SDK and configuration
#include "PDLS_Common.h"

#if (PDLS_COMMON_RELEASE < 902)
#error Required PDLS_COMMON_RELEASE 902
#endif // PDLS_COMMON_RELEASE

// Driver
#include "Driver_EPD_Virtual.h"

#ifndef DRIVER_BWRY_LARGE_RELEASE
///
/// @brief Library release number
///
#define DRIVER_BWRY_LARGE_RELEASE 904

///
/// @name List of supported screens
/// @details Colour black-white-red-yellow "Spectra 4" screens
///
/// @note Normal update
/// @see https://www.pervasivedisplays.com/products/?_sft_etc_itc=itc&_sft_product_colour=black-white-red-yellow
/// @{
///
#define eScreen_EPD_969_QS_0B SCREEN(SIZE_969, FILM_Q, DRIVER_B) ///< reference 970-QS-0B
/// @}

///
/// @name List of features
/// @{
///
#define WITH_COLOURS ///< With colours
#define WITH_COLOURS_BWRY ///< Black-White-Red-Yellow colours
/// @}

///
/// @brief Driver variant
///
#define DRIVER_EPD_RELEASE DRIVER_BWRY_LARGE_RELEASE
#define DRIVER_EPD_VARIANT "BWRY large"

///
/// @brief BWRY large screens class
///
class Pervasive_BWRY_Large : public Driver_EPD_Virtual
{
public:

    ///
    /// @brief Constructor
    /// @param eScreen_EPD
    /// @param board
    ///
    Pervasive_BWRY_Large(eScreen_EPD_t eScreen_EPD, pins_t board);

    /// @name General
    /// @{

    ///
    /// @brief Initialisation
    /// @details Initialise the board and read OTP
    ///
    void begin();

    ///
    /// @brief Driver reference
    ///
    /// @return STRING_CONST_TYPE scope and release number
    /// @note Example `BWRY large v9.0.0`
    ///
    STRING_CONST_TYPE reference();

    ///
    /// @brief Normal update
    ///
    /// @param masterframe master half of next image
    /// @param slaveframe slave half of next image
    /// @param sizeFrame size of the frame
    ///
    void updateNormal(FRAMEBUFFER_CONST_TYPE masterframe, FRAMEBUFFER_CONST_TYPE slaveframe, uint32_t sizeFrame);

    /// @}

protected:

private:

    // Variables and functions specific to the screen
    uint8_t COG_data[112]; // OTP

    void COG_reset();
    void COG_getDataOTP();
    void COG_initial();
    void COG_sendImageDataNormal(FRAMEBUFFER_CONST_TYPE masterFrame, FRAMEBUFFER_CONST_TYPE slaveFrame, uint32_t sizeFrame);
    void COG_update();
    void COG_stopDCDC();
};

#endif // DRIVER_BWRY_LARGE_RELEASE
