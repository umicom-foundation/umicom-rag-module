/*-----------------------------------------------------------------------------
 * Umicom RAG Module
 * File: include/umicom/rag/productisation_contribution.h
 *
 * PURPOSE:
 *   Declare this thin module's adoption of Framework-owned application
 *   experience, components, layouts and productisation evidence.
 *
 * AUTHOR AND ORGANISATION:
 * Sammy Hegab
 * Umicom Foundation
 *
 * LICENCE:
 * MIT
 *---------------------------------------------------------------------------*/
#ifndef UMICOM_RAG_PRODUCTISATION_CONTRIBUTION_H
#define UMICOM_RAG_PRODUCTISATION_CONTRIBUTION_H

#include "umicom/application/productisation/adoption.h"

#ifdef __cplusplus
extern "C" {
#endif

const UmiProductApplicationAdoption *
umi_rag_productisation_contribution(void);
UmiStatus umi_rag_productisation_snapshot(
    UmiProductApplicationAdoptionSnapshot *out_snapshot);

#ifdef __cplusplus
}
#endif

#endif
