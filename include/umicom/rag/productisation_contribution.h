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

#include "umicom/application/productisation/session.h"

#ifdef __cplusplus
extern "C" {
#endif

const UmiProductApplicationAdoption *
umi_rag_productisation_contribution(void);
UmiStatus umi_rag_productisation_snapshot(
    UmiProductApplicationAdoptionSnapshot *out_snapshot);
UmiStatus umi_rag_product_session_init(
    UmiProductApplicationSession *out_session);

#ifdef __cplusplus
}
#endif

#endif
