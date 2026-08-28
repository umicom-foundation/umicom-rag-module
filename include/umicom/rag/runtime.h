/*-----------------------------------------------------------------------------
 * Umicom RAG Module
 * File: include/umicom/rag/runtime.h
 *
 * PURPOSE:
 *   Bind the thin product to the Framework-owned application workspace runtime without duplicating services.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_RAG_RUNTIME_H
#define UMICOM_RAG_RUNTIME_H

#include "umicom/application/runtime/runtime.h"

#ifdef __cplusplus
extern "C" {
#endif

UmiStatus umi_rag_runtime_init(
    UmiApplicationWorkspaceRuntime *out_runtime);
UmiStatus umi_rag_runtime_health(
    UmiApplicationCapabilityProbe probe,
    void *user_data,
    UmiApplicationRuntimeHealth *out_health);
const UmiApplicationExperienceDefinition *umi_rag_runtime_experience(void);

#ifdef __cplusplus
}
#endif

#endif
