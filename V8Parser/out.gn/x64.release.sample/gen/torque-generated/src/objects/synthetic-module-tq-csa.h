#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SYNTHETIC_MODULE_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SYNTHETIC_MODULE_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<String> LoadSyntheticModuleName_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o);
void StoreSyntheticModuleName_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o, TNode<String> p_v);
TNode<FixedArray> LoadSyntheticModuleExportNames_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o);
void StoreSyntheticModuleExportNames_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o, TNode<FixedArray> p_v);
TNode<Foreign> LoadSyntheticModuleEvaluationSteps_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o);
void StoreSyntheticModuleEvaluationSteps_0(compiler::CodeAssemblerState* state_, TNode<SyntheticModule> p_o, TNode<Foreign> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SYNTHETIC_MODULE_TQ_H_
