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

const char* kBuiltinNameFind_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return "%TypedArray%.prototype.find";
}

TNode<Object> FindAllElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_callbackfn, TNode<Object> p_thisArg) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array, p_callbackfn, p_thisArg);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSTypedArray> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSTypedArray> tmp4;
    USE(tmp4);
    TNode<JSTypedArray> tmp5;
    USE(tmp5);
    TNode<BuiltinPtr> tmp6;
    USE(tmp6);
    std::tie(tmp4, tmp5, tmp6) = NewAttachedJSTypedArrayWitness_0(state_, TNode<JSTypedArray>{tmp1}).Flatten();
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSTypedArray::kLengthOffset);
    USE(tmp7);
    TNode<UintPtrT>tmp8 = CodeStubAssembler(state_).LoadReference<UintPtrT>(CodeStubAssembler::Reference{tmp5, tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8, tmp9);
  }

  if (block5.is_used()) {
    TNode<Context> tmp10;
    TNode<JSTypedArray> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<JSTypedArray> tmp14;
    TNode<JSTypedArray> tmp15;
    TNode<BuiltinPtr> tmp16;
    TNode<UintPtrT> tmp17;
    TNode<UintPtrT> tmp18;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp18}, TNode<UintPtrT>{tmp17});
    ca_.Branch(tmp19, &block3, &block4, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block3.is_used()) {
    TNode<Context> tmp20;
    TNode<JSTypedArray> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Object> tmp23;
    TNode<JSTypedArray> tmp24;
    TNode<JSTypedArray> tmp25;
    TNode<BuiltinPtr> tmp26;
    TNode<UintPtrT> tmp27;
    TNode<UintPtrT> tmp28;
    ca_.Bind(&block3, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<IntPtrT> tmp29 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp29);
    TNode<JSArrayBuffer>tmp30 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp24, tmp29});
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp30});
    ca_.Branch(tmp31, &block10, &block11, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block10.is_used()) {
    TNode<Context> tmp32;
    TNode<JSTypedArray> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Object> tmp35;
    TNode<JSTypedArray> tmp36;
    TNode<JSTypedArray> tmp37;
    TNode<BuiltinPtr> tmp38;
    TNode<UintPtrT> tmp39;
    TNode<UintPtrT> tmp40;
    ca_.Bind(&block10, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block4, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40);
  }

  if (block11.is_used()) {
    TNode<Context> tmp41;
    TNode<JSTypedArray> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<Object> tmp44;
    TNode<JSTypedArray> tmp45;
    TNode<JSTypedArray> tmp46;
    TNode<BuiltinPtr> tmp47;
    TNode<UintPtrT> tmp48;
    TNode<UintPtrT> tmp49;
    ca_.Bind(&block11, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<JSTypedArray> tmp50;
    USE(tmp50);
    tmp50 = (TNode<JSTypedArray>{tmp45});
    TNode<Numeric> tmp51 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(1)).descriptor(), tmp47, tmp41, tmp50, tmp49)); 
    USE(tmp51);
    TNode<Number> tmp52;
    USE(tmp52);
    tmp52 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp49});
    TNode<Object> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).Call(TNode<Context>{tmp41}, TNode<JSReceiver>{tmp43}, TNode<Object>{tmp44}, TNode<Object>{tmp51}, TNode<Object>{tmp52}, TNode<Object>{tmp45});
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = ToBoolean_0(state_, TNode<Object>{tmp53});
    ca_.Branch(tmp54, &block14, &block15, tmp41, tmp42, tmp43, tmp44, tmp45, tmp50, tmp47, tmp48, tmp49, tmp51, tmp53);
  }

  if (block14.is_used()) {
    TNode<Context> tmp55;
    TNode<JSTypedArray> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<Object> tmp58;
    TNode<JSTypedArray> tmp59;
    TNode<JSTypedArray> tmp60;
    TNode<BuiltinPtr> tmp61;
    TNode<UintPtrT> tmp62;
    TNode<UintPtrT> tmp63;
    TNode<Object> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block14, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block1, tmp55, tmp56, tmp57, tmp58, tmp64);
  }

  if (block15.is_used()) {
    TNode<Context> tmp66;
    TNode<JSTypedArray> tmp67;
    TNode<JSReceiver> tmp68;
    TNode<Object> tmp69;
    TNode<JSTypedArray> tmp70;
    TNode<JSTypedArray> tmp71;
    TNode<BuiltinPtr> tmp72;
    TNode<UintPtrT> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    ca_.Bind(&block15, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<UintPtrT> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp74}, TNode<UintPtrT>{tmp77});
    ca_.Goto(&block5, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp78);
  }

  if (block4.is_used()) {
    TNode<Context> tmp79;
    TNode<JSTypedArray> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<Object> tmp82;
    TNode<JSTypedArray> tmp83;
    TNode<JSTypedArray> tmp84;
    TNode<BuiltinPtr> tmp85;
    TNode<UintPtrT> tmp86;
    TNode<UintPtrT> tmp87;
    ca_.Bind(&block4, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
    TNode<Oddball> tmp88;
    USE(tmp88);
    tmp88 = Undefined_0(state_);
    ca_.Goto(&block1, tmp79, tmp80, tmp81, tmp82, tmp88);
  }

  if (block1.is_used()) {
    TNode<Context> tmp89;
    TNode<JSTypedArray> tmp90;
    TNode<JSReceiver> tmp91;
    TNode<Object> tmp92;
    TNode<Object> tmp93;
    ca_.Bind(&block1, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    ca_.Goto(&block16, tmp89, tmp90, tmp91, tmp92, tmp93);
  }

    TNode<Context> tmp94;
    TNode<JSTypedArray> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<Object> tmp97;
    TNode<Object> tmp98;
    ca_.Bind(&block16, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
  return TNode<Object>{tmp98};
}

TF_BUILTIN(TypedArrayPrototypeFind, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext, JSTypedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, JSTypedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, Object, NativeContext> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, Object, NativeContext, JSReceiver> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSTypedArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_JSTypedArray_1(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block7, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3);
    }
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<NativeContext> tmp12;
    ca_.Bind(&block8, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp9}, MessageTemplate::kNotTypedArray, kBuiltinNameFind_0(state_));
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    TNode<JSTypedArray> tmp20;
    ca_.Bind(&block7, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<JSTypedArray> tmp21;
    USE(tmp21);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp21 = EnsureAttached_0(state_, TNode<JSTypedArray>{tmp20}, &label0);
    ca_.Goto(&block9, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp20, tmp21);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp20);
    }
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<JSTypedArray> tmp27;
    TNode<JSTypedArray> tmp28;
    ca_.Bind(&block10, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp25}, MessageTemplate::kDetachedOperation, kBuiltinNameFind_0(state_));
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp29;
    TNode<RawPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<NativeContext> tmp32;
    TNode<Object> tmp33;
    TNode<JSTypedArray> tmp34;
    TNode<JSTypedArray> tmp35;
    TNode<JSTypedArray> tmp36;
    ca_.Bind(&block9, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<IntPtrT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp29}, TNode<RawPtrT>{tmp30}, TNode<IntPtrT>{tmp31}}, TNode<IntPtrT>{tmp37});
    TNode<JSReceiver> tmp39;
    USE(tmp39);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp39 = Cast_Callable_1(state_, TNode<Context>{tmp32}, TNode<Object>{tmp38}, &label0);
    ca_.Goto(&block11, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp36, tmp38, tmp32, tmp39);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp36, tmp38, tmp32);
    }
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp40;
    TNode<RawPtrT> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<NativeContext> tmp43;
    TNode<Object> tmp44;
    TNode<JSTypedArray> tmp45;
    TNode<JSTypedArray> tmp46;
    TNode<Object> tmp47;
    TNode<NativeContext> tmp48;
    ca_.Bind(&block12, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<IntPtrT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp40}, TNode<RawPtrT>{tmp41}, TNode<IntPtrT>{tmp42}}, TNode<IntPtrT>{tmp49});
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp43}, MessageTemplate::kCalledNonCallable, TNode<Object>{tmp50});
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp51;
    TNode<RawPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<NativeContext> tmp54;
    TNode<Object> tmp55;
    TNode<JSTypedArray> tmp56;
    TNode<JSTypedArray> tmp57;
    TNode<Object> tmp58;
    TNode<NativeContext> tmp59;
    TNode<JSReceiver> tmp60;
    ca_.Bind(&block11, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    TNode<IntPtrT> tmp61;
    USE(tmp61);
    tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp51}, TNode<RawPtrT>{tmp52}, TNode<IntPtrT>{tmp53}}, TNode<IntPtrT>{tmp61});
    TNode<Object> tmp63;
    USE(tmp63);
    tmp63 = FindAllElements_0(state_, TNode<Context>{tmp54}, TNode<JSTypedArray>{tmp57}, TNode<JSReceiver>{tmp60}, TNode<Object>{tmp62});
    arguments.PopAndReturn(tmp63);
  }
}

}  // namespace internal
}  // namespace v8

