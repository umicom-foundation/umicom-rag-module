/*-----------------------------------------------------------------------------
 * Umicom RAG Module
 * File: include/umicom/rag/application.h
 *
 * PURPOSE:
 *   Expose the thin application composition over Framework-owned experience metadata and services.
 *
 * Created by: Sammy Hegab
 * Organisation: Umicom Foundation
 * Licence: MIT
 *---------------------------------------------------------------------------*/

#ifndef UMICOM_RAG_APPLICATION_H
#define UMICOM_RAG_APPLICATION_H

#include "umicom/application/experience.h"
#include "umicom/application/experience_status.h"

#ifdef __cplusplus
extern "C" {
#endif

#define UMI_RAG_MODULE_API_VERSION 1U

const char *umi_rag_application_id(void);

const UmiApplicationExperienceDefinition *
umi_rag_application_experience(void);

UmiStatus umi_rag_application_status(
    UmiApplicationExperienceStatus *out_status);

#ifdef __cplusplus
}
#endif

#endif
