/* Include files */

#include <stddef.h>
#include "blas.h"
#include "QR2Dsim_sfun.h"
#include "c9_QR2Dsim.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "QR2Dsim_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c9_debug_family_names[7] = { "a", "b", "c", "nargin",
  "nargout", "A", "fcnhat" };

/* Function Declarations */
static void initialize_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void initialize_params_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance);
static void enable_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void disable_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void c9_update_debugger_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance);
static void set_sim_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_st);
static void finalize_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void sf_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void initSimStructsc9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance, const
  mxArray *c9_fcnhat, const char_T *c9_identifier, real_T c9_y[9]);
static void c9_b_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_c_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_e_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_QR2Dsim, const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_QR2DsimInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c9_is_active_c9_QR2Dsim = 0U;
}

static void initialize_params_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance)
{
}

static void enable_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c9_update_debugger_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance)
{
}

static const mxArray *get_sim_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct
  *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[9];
  const mxArray *c9_b_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T (*c9_fcnhat)[9];
  c9_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellarray(2), FALSE);
  for (c9_i0 = 0; c9_i0 < 9; c9_i0++) {
    c9_u[c9_i0] = (*c9_fcnhat)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_QR2Dsim;
  c9_b_u = c9_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  sf_mex_assign(&c9_st, c9_y, FALSE);
  return c9_st;
}

static void set_sim_state_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[9];
  int32_T c9_i1;
  real_T (*c9_fcnhat)[9];
  c9_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c9_doneDoubleBufferReInit = TRUE;
  c9_u = sf_mex_dup(c9_st);
  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                      "fcnhat", c9_dv0);
  for (c9_i1 = 0; c9_i1 < 9; c9_i1++) {
    (*c9_fcnhat)[c9_i1] = c9_dv0[c9_i1];
  }

  chartInstance->c9_is_active_c9_QR2Dsim = c9_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 1)), "is_active_c9_QR2Dsim");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_QR2Dsim(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
}

static void sf_c9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
  int32_T c9_i2;
  int32_T c9_i3;
  int32_T c9_i4;
  real_T c9_A[3];
  uint32_T c9_debug_family_var_map[7];
  real_T c9_a;
  real_T c9_b;
  real_T c9_c;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 1.0;
  real_T c9_fcnhat[9];
  int32_T c9_i5;
  real_T (*c9_b_fcnhat)[9];
  real_T (*c9_b_A)[3];
  c9_b_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
  c9_b_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  for (c9_i2 = 0; c9_i2 < 3; c9_i2++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_A)[c9_i2], 0U);
  }

  for (c9_i3 = 0; c9_i3 < 9; c9_i3++) {
    _SFD_DATA_RANGE_CHECK((*c9_b_fcnhat)[c9_i3], 1U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  for (c9_i4 = 0; c9_i4 < 3; c9_i4++) {
    c9_A[c9_i4] = (*c9_b_A)[c9_i4];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_a, 0U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_b, 1U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_c, 2U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 3U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 4U, c9_c_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_A, 5U, c9_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_fcnhat, 6U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  c9_a = c9_A[0];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 4);
  c9_b = c9_A[1];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 5);
  c9_c = c9_A[2];
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_fcnhat[0] = 0.0;
  c9_fcnhat[3] = -c9_c;
  c9_fcnhat[6] = c9_b;
  c9_fcnhat[1] = c9_c;
  c9_fcnhat[4] = 0.0;
  c9_fcnhat[7] = -c9_a;
  c9_fcnhat[2] = -c9_b;
  c9_fcnhat[5] = c9_a;
  c9_fcnhat[8] = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -6);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i5 = 0; c9_i5 < 9; c9_i5++) {
    (*c9_b_fcnhat)[c9_i5] = c9_fcnhat[c9_i5];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_QR2DsimMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc9_QR2Dsim(SFc9_QR2DsimInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber)
{
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i6;
  int32_T c9_i7;
  int32_T c9_i8;
  real_T c9_b_inData[9];
  int32_T c9_i9;
  int32_T c9_i10;
  int32_T c9_i11;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i6 = 0;
  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    for (c9_i8 = 0; c9_i8 < 3; c9_i8++) {
      c9_b_inData[c9_i8 + c9_i6] = (*(real_T (*)[9])c9_inData)[c9_i8 + c9_i6];
    }

    c9_i6 += 3;
  }

  c9_i9 = 0;
  for (c9_i10 = 0; c9_i10 < 3; c9_i10++) {
    for (c9_i11 = 0; c9_i11 < 3; c9_i11++) {
      c9_u[c9_i11 + c9_i9] = c9_b_inData[c9_i11 + c9_i9];
    }

    c9_i9 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance, const
  mxArray *c9_fcnhat, const char_T *c9_identifier, real_T c9_y[9])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_fcnhat), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_fcnhat);
}

static void c9_b_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId, real_T c9_y[9])
{
  real_T c9_dv1[9];
  int32_T c9_i12;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv1, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i12 = 0; c9_i12 < 9; c9_i12++) {
    c9_y[c9_i12] = c9_dv1[c9_i12];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_fcnhat;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i13;
  int32_T c9_i14;
  int32_T c9_i15;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_fcnhat = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_fcnhat), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_fcnhat);
  c9_i13 = 0;
  for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
    for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
      (*(real_T (*)[9])c9_outData)[c9_i15 + c9_i13] = c9_y[c9_i15 + c9_i13];
    }

    c9_i13 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i16;
  real_T c9_b_inData[3];
  int32_T c9_i17;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i16 = 0; c9_i16 < 3; c9_i16++) {
    c9_b_inData[c9_i16] = (*(real_T (*)[3])c9_inData)[c9_i16];
  }

  for (c9_i17 = 0; c9_i17 < 3; c9_i17++) {
    c9_u[c9_i17] = c9_b_inData[c9_i17];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 1), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static real_T c9_c_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_QR2Dsim_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), FALSE);
  return c9_nameCaptureInfo;
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, FALSE);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i18;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i18, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i18;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_b_is_active_c9_QR2Dsim, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_QR2Dsim), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_QR2Dsim);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_QR2DsimInstanceStruct *chartInstance,
  const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_QR2DsimInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c9_QR2Dsim_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4131461561U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2773855065U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3367629386U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1329840116U);
}

mxArray *sf_c9_QR2Dsim_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("OkOaE7PIG6hStSXjKfx8dC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_QR2Dsim_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_QR2Dsim_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c9_QR2Dsim(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"fcnhat\",},{M[8],M[0],T\"is_active_c9_QR2Dsim\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_QR2Dsim_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_QR2DsimInstanceStruct *chartInstance;
    chartInstance = (SFc9_QR2DsimInstanceStruct *) ((ChartInfoStruct *)
      (ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _QR2DsimMachineNumber_,
           9,
           1,
           1,
           2,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_QR2DsimMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_QR2DsimMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _QR2DsimMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"A");
          _SFD_SET_DATA_PROPS(1,2,0,1,"fcnhat");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,112);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          real_T (*c9_A)[3];
          real_T (*c9_fcnhat)[9];
          c9_fcnhat = (real_T (*)[9])ssGetOutputPortSignal(chartInstance->S, 1);
          c9_A = (real_T (*)[3])ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, *c9_A);
          _SFD_SET_DATA_VALUE_PTR(1U, *c9_fcnhat);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _QR2DsimMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "GfIs82lQvdn1MFOTGXJ1UF";
}

static void sf_opaque_initialize_c9_QR2Dsim(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_QR2DsimInstanceStruct*) chartInstanceVar)->S,
    0);
  initialize_params_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
  initialize_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c9_QR2Dsim(void *chartInstanceVar)
{
  enable_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_QR2Dsim(void *chartInstanceVar)
{
  disable_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_QR2Dsim(void *chartInstanceVar)
{
  sf_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c9_QR2Dsim(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c9_QR2Dsim(SimStruct* S, const mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c9_QR2Dsim();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*)chartInfo->chartInstance,
    mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c9_QR2Dsim(SimStruct* S)
{
  return sf_internal_get_sim_state_c9_QR2Dsim(S);
}

static void sf_opaque_set_sim_state_c9_QR2Dsim(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c9_QR2Dsim(S, st);
}

static void sf_opaque_terminate_c9_QR2Dsim(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_QR2DsimInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_QR2Dsim_optimization_info();
    }

    finalize_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc9_QR2Dsim((SFc9_QR2DsimInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_QR2Dsim(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c9_QR2Dsim((SFc9_QR2DsimInstanceStruct*)(((ChartInfoStruct
      *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_QR2Dsim_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,9,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1502744395U));
  ssSetChecksum1(S,(1388126807U));
  ssSetChecksum2(S,(2128390740U));
  ssSetChecksum3(S,(815326924U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_QR2Dsim(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_QR2Dsim(SimStruct *S)
{
  SFc9_QR2DsimInstanceStruct *chartInstance;
  chartInstance = (SFc9_QR2DsimInstanceStruct *)utMalloc(sizeof
    (SFc9_QR2DsimInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_QR2DsimInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_QR2Dsim;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c9_QR2Dsim;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_QR2Dsim;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_QR2Dsim;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_QR2Dsim;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c9_QR2Dsim;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c9_QR2Dsim;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c9_QR2Dsim;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_QR2Dsim;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_QR2Dsim;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_QR2Dsim;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c9_QR2Dsim_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_QR2Dsim(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_QR2Dsim(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_QR2Dsim(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_QR2Dsim_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
