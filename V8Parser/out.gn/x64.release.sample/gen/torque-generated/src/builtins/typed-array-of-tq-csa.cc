#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "torque-generated/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-find-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-map-tq-csa.h"
#include "torque-generated/src/builtins/array-of-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-some-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/bigint-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/console-tq-csa.h"
#include "torque-generated/src/builtins/data-view-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-tq-csa.h"
#include "torque-generated/src/builtins/reflect-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/src/builtins/string-html-tq-csa.h"
#include "torque-generated/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/src/builtins/symbol-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"
#include "torque-generated/src/objects/cell-tq-csa.h"
#include "torque-generated/src/objects/code-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/data-handler-tq-csa.h"
#include "torque-generated/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/foreign-tq-csa.h"
#include "torque-generated/src/objects/free-space-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/heap-object-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-collection-tq-csa.h"
#include "torque-generated/src/objects/js-generator-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/microtask-tq-csa.h"
#include "torque-generated/src/objects/module-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/oddball-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-array-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/script-tq-csa.h"
#include "torque-generated/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/src/objects/template-objects-tq-csa.h"
#include "torque-generated/src/objects/template-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

const char* kBuiltinNameOf_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return "%TypedArray%.of";
}

TF_BUILTIN(TypedArrayOf, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, Object, NativeContext, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT, Object, BuiltinPtr, BuiltinPtr, BuiltinPtr, NativeContext, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object, BuiltinPtr, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT, Object, BuiltinPtr, BuiltinPtr, BuiltinPtr, NativeContext, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object, BuiltinPtr, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT, Object, BuiltinPtr, BuiltinPtr, BuiltinPtr, NativeContext, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object, BuiltinPtr, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT, Object, BuiltinPtr, BuiltinPtr, BuiltinPtr, NativeContext, JSTypedArray, UintPtrT, Object, Context, JSTypedArray, UintPtrT, Object, BuiltinPtr, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, UintPtrT, JSReceiver, JSTypedArray, BuiltinPtr, BuiltinPtr, BuiltinPtr, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<UintPtrT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp2});
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_Constructor_1(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp3, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp3);
    }
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<Object> tmp13;
    TNode<NativeContext> tmp14;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp10}, MessageTemplate::kNotConstructor, TNode<Object>{tmp11});
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<NativeContext> tmp18;
    TNode<Object> tmp19;
    TNode<UintPtrT> tmp20;
    TNode<Object> tmp21;
    TNode<NativeContext> tmp22;
    TNode<JSReceiver> tmp23;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<Number> tmp24;
    USE(tmp24);
    tmp24 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp20});
    TNode<JSTypedArray> tmp25;
    USE(tmp25);
    tmp25 = TypedArrayCreateByLength_0(state_, TNode<Context>{tmp18}, TNode<JSReceiver>{tmp23}, TNode<Number>{tmp24}, kBuiltinNameOf_0(state_));
    TNode<Int32T> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).LoadElementsKind(TNode<JSTypedArray>{tmp25});
    TNode<BuiltinPtr> tmp27;
    USE(tmp27);
    TNode<BuiltinPtr> tmp28;
    USE(tmp28);
    TNode<BuiltinPtr> tmp29;
    USE(tmp29);
    std::tie(tmp27, tmp28, tmp29) = GetTypedArrayAccessor_0(state_, TNode<Int32T>{tmp26}).Flatten();
    TNode<UintPtrT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block9, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp23, tmp25, tmp27, tmp28, tmp29, tmp30);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<JSTypedArray> tmp38;
    TNode<BuiltinPtr> tmp39;
    TNode<BuiltinPtr> tmp40;
    TNode<BuiltinPtr> tmp41;
    TNode<UintPtrT> tmp42;
    ca_.Bind(&block9, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp42}, TNode<UintPtrT>{tmp36});
    ca_.Branch(tmp43, &block7, &block8, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp44;
    TNode<RawPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<NativeContext> tmp47;
    TNode<Object> tmp48;
    TNode<UintPtrT> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<JSTypedArray> tmp51;
    TNode<BuiltinPtr> tmp52;
    TNode<BuiltinPtr> tmp53;
    TNode<BuiltinPtr> tmp54;
    TNode<UintPtrT> tmp55;
    ca_.Bind(&block7, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp55});
    TNode<Object> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp44}, TNode<RawPtrT>{tmp45}, TNode<IntPtrT>{tmp46}}, TNode<IntPtrT>{tmp56});
    TNode<Smi> tmp58 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(3)).descriptor(), tmp54, tmp47, tmp51, tmp55, tmp57)); 
    USE(tmp58);
    TNode<Smi> tmp59;
    USE(tmp59);
    tmp59 = kStoreFailureArrayDetached_0(state_);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp58}, TNode<Smi>{tmp59});
    ca_.Branch(tmp60, &block12, &block13, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp57, tmp52, tmp53, tmp54, tmp47, tmp51, tmp55, tmp57, tmp47, tmp51, tmp55, tmp57, tmp54, tmp58);
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp61;
    TNode<RawPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<NativeContext> tmp64;
    TNode<Object> tmp65;
    TNode<UintPtrT> tmp66;
    TNode<JSReceiver> tmp67;
    TNode<JSTypedArray> tmp68;
    TNode<BuiltinPtr> tmp69;
    TNode<BuiltinPtr> tmp70;
    TNode<BuiltinPtr> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<Object> tmp73;
    TNode<BuiltinPtr> tmp74;
    TNode<BuiltinPtr> tmp75;
    TNode<BuiltinPtr> tmp76;
    TNode<NativeContext> tmp77;
    TNode<JSTypedArray> tmp78;
    TNode<UintPtrT> tmp79;
    TNode<Object> tmp80;
    TNode<Context> tmp81;
    TNode<JSTypedArray> tmp82;
    TNode<UintPtrT> tmp83;
    TNode<Object> tmp84;
    TNode<BuiltinPtr> tmp85;
    TNode<Smi> tmp86;
    ca_.Bind(&block12, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp64}, MessageTemplate::kDetachedOperation, kBuiltinNameOf_0(state_));
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp87;
    TNode<RawPtrT> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<NativeContext> tmp90;
    TNode<Object> tmp91;
    TNode<UintPtrT> tmp92;
    TNode<JSReceiver> tmp93;
    TNode<JSTypedArray> tmp94;
    TNode<BuiltinPtr> tmp95;
    TNode<BuiltinPtr> tmp96;
    TNode<BuiltinPtr> tmp97;
    TNode<UintPtrT> tmp98;
    TNode<Object> tmp99;
    TNode<BuiltinPtr> tmp100;
    TNode<BuiltinPtr> tmp101;
    TNode<BuiltinPtr> tmp102;
    TNode<NativeContext> tmp103;
    TNode<JSTypedArray> tmp104;
    TNode<UintPtrT> tmp105;
    TNode<Object> tmp106;
    TNode<Context> tmp107;
    TNode<JSTypedArray> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<Object> tmp110;
    TNode<BuiltinPtr> tmp111;
    TNode<Smi> tmp112;
    ca_.Bind(&block13, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112);
    TNode<UintPtrT> tmp113;
    USE(tmp113);
    tmp113 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp114;
    USE(tmp114);
    tmp114 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp98}, TNode<UintPtrT>{tmp113});
    ca_.Goto(&block9, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp114);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp115;
    TNode<RawPtrT> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<NativeContext> tmp118;
    TNode<Object> tmp119;
    TNode<UintPtrT> tmp120;
    TNode<JSReceiver> tmp121;
    TNode<JSTypedArray> tmp122;
    TNode<BuiltinPtr> tmp123;
    TNode<BuiltinPtr> tmp124;
    TNode<BuiltinPtr> tmp125;
    TNode<UintPtrT> tmp126;
    TNode<Object> tmp127;
    TNode<BuiltinPtr> tmp128;
    TNode<BuiltinPtr> tmp129;
    TNode<BuiltinPtr> tmp130;
    TNode<NativeContext> tmp131;
    TNode<JSTypedArray> tmp132;
    TNode<UintPtrT> tmp133;
    TNode<Object> tmp134;
    TNode<Context> tmp135;
    TNode<JSTypedArray> tmp136;
    TNode<UintPtrT> tmp137;
    TNode<Object> tmp138;
    TNode<BuiltinPtr> tmp139;
    TNode<Smi> tmp140;
    ca_.Bind(&block17, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    CodeStubAssembler(state_).FailAssert("Torque assert 'result == kStoreSucceded' failed", "src/builtins/typed-array.tq", 114);
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp141;
    TNode<RawPtrT> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<NativeContext> tmp144;
    TNode<Object> tmp145;
    TNode<UintPtrT> tmp146;
    TNode<JSReceiver> tmp147;
    TNode<JSTypedArray> tmp148;
    TNode<BuiltinPtr> tmp149;
    TNode<BuiltinPtr> tmp150;
    TNode<BuiltinPtr> tmp151;
    TNode<UintPtrT> tmp152;
    TNode<Object> tmp153;
    TNode<BuiltinPtr> tmp154;
    TNode<BuiltinPtr> tmp155;
    TNode<BuiltinPtr> tmp156;
    TNode<NativeContext> tmp157;
    TNode<JSTypedArray> tmp158;
    TNode<UintPtrT> tmp159;
    TNode<Object> tmp160;
    TNode<Context> tmp161;
    TNode<JSTypedArray> tmp162;
    TNode<UintPtrT> tmp163;
    TNode<Object> tmp164;
    TNode<BuiltinPtr> tmp165;
    TNode<Smi> tmp166;
    ca_.Bind(&block16, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp167;
    TNode<RawPtrT> tmp168;
    TNode<IntPtrT> tmp169;
    TNode<NativeContext> tmp170;
    TNode<Object> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<JSReceiver> tmp173;
    TNode<JSTypedArray> tmp174;
    TNode<BuiltinPtr> tmp175;
    TNode<BuiltinPtr> tmp176;
    TNode<BuiltinPtr> tmp177;
    TNode<UintPtrT> tmp178;
    ca_.Bind(&block8, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178);
    arguments.PopAndReturn(tmp174);
  }
}

}  // namespace internal
}  // namespace v8

