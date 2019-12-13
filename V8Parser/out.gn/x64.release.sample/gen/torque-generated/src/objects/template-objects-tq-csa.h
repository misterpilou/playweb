#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<FixedArray> LoadTemplateObjectDescriptionRawStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o);
void StoreTemplateObjectDescriptionRawStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o, TNode<FixedArray> p_v);
TNode<FixedArray> LoadTemplateObjectDescriptionCookedStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o);
void StoreTemplateObjectDescriptionCookedStrings_0(compiler::CodeAssemblerState* state_, TNode<TemplateObjectDescription> p_o, TNode<FixedArray> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_TEMPLATE_OBJECTS_TQ_H_
