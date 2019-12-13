#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_GENERATOR_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_GENERATOR_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<JSFunction> LoadJSGeneratorObjectFunction_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectFunction_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<JSFunction> p_v);
TNode<Context> LoadJSGeneratorObjectContext_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectContext_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<Context> p_v);
TNode<Object> LoadJSGeneratorObjectReceiver_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectReceiver_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<Object> p_v);
TNode<Object> LoadJSGeneratorObjectInputOrDebugPos_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectInputOrDebugPos_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<Object> p_v);
TNode<Smi> LoadJSGeneratorObjectResumeMode_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectResumeMode_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<Smi> p_v);
TNode<Smi> LoadJSGeneratorObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectContinuation_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<Smi> p_v);
TNode<FixedArray> LoadJSGeneratorObjectParametersAndRegisters_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o);
void StoreJSGeneratorObjectParametersAndRegisters_0(compiler::CodeAssemblerState* state_, TNode<JSGeneratorObject> p_o, TNode<FixedArray> p_v);
TNode<JSPromise> LoadJSAsyncFunctionObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFunctionObject> p_o);
void StoreJSAsyncFunctionObjectPromise_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncFunctionObject> p_o, TNode<JSPromise> p_v);
TNode<HeapObject> LoadJSAsyncGeneratorObjectQueue_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncGeneratorObject> p_o);
void StoreJSAsyncGeneratorObjectQueue_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncGeneratorObject> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSAsyncGeneratorObjectIsAwaiting_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncGeneratorObject> p_o);
void StoreJSAsyncGeneratorObjectIsAwaiting_0(compiler::CodeAssemblerState* state_, TNode<JSAsyncGeneratorObject> p_o, TNode<Smi> p_v);
TNode<HeapObject> LoadAsyncGeneratorRequestNext_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o);
void StoreAsyncGeneratorRequestNext_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadAsyncGeneratorRequestResumeMode_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o);
void StoreAsyncGeneratorRequestResumeMode_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o, TNode<Smi> p_v);
TNode<Object> LoadAsyncGeneratorRequestValue_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o);
void StoreAsyncGeneratorRequestValue_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o, TNode<Object> p_v);
TNode<JSPromise> LoadAsyncGeneratorRequestPromise_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o);
void StoreAsyncGeneratorRequestPromise_0(compiler::CodeAssemblerState* state_, TNode<AsyncGeneratorRequest> p_o, TNode<JSPromise> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_GENERATOR_TQ_H_
