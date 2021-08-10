/*******************************************************************************
* File Name: ce.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ce_H) /* Pins ce_H */
#define CY_PINS_ce_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ce_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ce__PORT == 15 && ((ce__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ce_Write(uint8 value);
void    ce_SetDriveMode(uint8 mode);
uint8   ce_ReadDataReg(void);
uint8   ce_Read(void);
void    ce_SetInterruptMode(uint16 position, uint16 mode);
uint8   ce_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ce_SetDriveMode() function.
     *  @{
     */
        #define ce_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ce_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ce_DM_RES_UP          PIN_DM_RES_UP
        #define ce_DM_RES_DWN         PIN_DM_RES_DWN
        #define ce_DM_OD_LO           PIN_DM_OD_LO
        #define ce_DM_OD_HI           PIN_DM_OD_HI
        #define ce_DM_STRONG          PIN_DM_STRONG
        #define ce_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ce_MASK               ce__MASK
#define ce_SHIFT              ce__SHIFT
#define ce_WIDTH              1u

/* Interrupt constants */
#if defined(ce__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ce_SetInterruptMode() function.
     *  @{
     */
        #define ce_INTR_NONE      (uint16)(0x0000u)
        #define ce_INTR_RISING    (uint16)(0x0001u)
        #define ce_INTR_FALLING   (uint16)(0x0002u)
        #define ce_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ce_INTR_MASK      (0x01u) 
#endif /* (ce__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ce_PS                     (* (reg8 *) ce__PS)
/* Data Register */
#define ce_DR                     (* (reg8 *) ce__DR)
/* Port Number */
#define ce_PRT_NUM                (* (reg8 *) ce__PRT) 
/* Connect to Analog Globals */                                                  
#define ce_AG                     (* (reg8 *) ce__AG)                       
/* Analog MUX bux enable */
#define ce_AMUX                   (* (reg8 *) ce__AMUX) 
/* Bidirectional Enable */                                                        
#define ce_BIE                    (* (reg8 *) ce__BIE)
/* Bit-mask for Aliased Register Access */
#define ce_BIT_MASK               (* (reg8 *) ce__BIT_MASK)
/* Bypass Enable */
#define ce_BYP                    (* (reg8 *) ce__BYP)
/* Port wide control signals */                                                   
#define ce_CTL                    (* (reg8 *) ce__CTL)
/* Drive Modes */
#define ce_DM0                    (* (reg8 *) ce__DM0) 
#define ce_DM1                    (* (reg8 *) ce__DM1)
#define ce_DM2                    (* (reg8 *) ce__DM2) 
/* Input Buffer Disable Override */
#define ce_INP_DIS                (* (reg8 *) ce__INP_DIS)
/* LCD Common or Segment Drive */
#define ce_LCD_COM_SEG            (* (reg8 *) ce__LCD_COM_SEG)
/* Enable Segment LCD */
#define ce_LCD_EN                 (* (reg8 *) ce__LCD_EN)
/* Slew Rate Control */
#define ce_SLW                    (* (reg8 *) ce__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ce_PRTDSI__CAPS_SEL       (* (reg8 *) ce__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ce_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ce__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ce_PRTDSI__OE_SEL0        (* (reg8 *) ce__PRTDSI__OE_SEL0) 
#define ce_PRTDSI__OE_SEL1        (* (reg8 *) ce__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ce_PRTDSI__OUT_SEL0       (* (reg8 *) ce__PRTDSI__OUT_SEL0) 
#define ce_PRTDSI__OUT_SEL1       (* (reg8 *) ce__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ce_PRTDSI__SYNC_OUT       (* (reg8 *) ce__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ce__SIO_CFG)
    #define ce_SIO_HYST_EN        (* (reg8 *) ce__SIO_HYST_EN)
    #define ce_SIO_REG_HIFREQ     (* (reg8 *) ce__SIO_REG_HIFREQ)
    #define ce_SIO_CFG            (* (reg8 *) ce__SIO_CFG)
    #define ce_SIO_DIFF           (* (reg8 *) ce__SIO_DIFF)
#endif /* (ce__SIO_CFG) */

/* Interrupt Registers */
#if defined(ce__INTSTAT)
    #define ce_INTSTAT            (* (reg8 *) ce__INTSTAT)
    #define ce_SNAP               (* (reg8 *) ce__SNAP)
    
	#define ce_0_INTTYPE_REG 		(* (reg8 *) ce__0__INTTYPE)
#endif /* (ce__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ce_H */


/* [] END OF FILE */
