#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SCRIPT_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SCRIPT_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<Object> LoadScriptSource_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptSource_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Object> LoadScriptName_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptName_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Smi> LoadScriptLineOffset_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptLineOffset_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Smi> p_v);
TNode<Smi> LoadScriptColumnOffset_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptColumnOffset_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Smi> p_v);
TNode<Object> LoadScriptContext_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptContext_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Smi> LoadScriptScriptType_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptScriptType_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Smi> p_v);
TNode<Object> LoadScriptLineEnds_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptLineEnds_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Smi> LoadScriptId_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptId_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Smi> p_v);
TNode<Object> LoadScriptEvalFromSharedOrWrappedArguments_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptEvalFromSharedOrWrappedArguments_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Object> LoadScriptEvalFromPosition_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptEvalFromPosition_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Object> LoadScriptSharedFunctionInfos_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptSharedFunctionInfos_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Smi> LoadScriptFlags_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptFlags_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Smi> p_v);
TNode<Object> LoadScriptSourceUrl_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptSourceUrl_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Object> LoadScriptSourceMappingUrl_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptSourceMappingUrl_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
TNode<Object> LoadScriptHostDefinedOptions_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o);
void StoreScriptHostDefinedOptions_0(compiler::CodeAssemblerState* state_, TNode<Script> p_o, TNode<Object> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_SCRIPT_TQ_H_
