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

const char* kBuiltinNameReduce_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return "%TypedArray%.prototype.reduce";
}

TNode<Object> ReduceAllElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_array, TNode<JSReceiver> p_callbackfn, TNode<Object> p_initialValue) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT, Object, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT, Object, Object, Object, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, UintPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, Object, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, JSTypedArray, JSTypedArray, BuiltinPtr, UintPtrT, Object, Object, Object, Oddball> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSTypedArray, JSReceiver, Object, Object> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array, p_callbackfn, p_initialValue);

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
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8, tmp3, tmp9);
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
    TNode<Object> tmp18;
    TNode<UintPtrT> tmp19;
    ca_.Bind(&block5, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp19}, TNode<UintPtrT>{tmp17});
    ca_.Branch(tmp20, &block3, &block4, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<Context> tmp21;
    TNode<JSTypedArray> tmp22;
    TNode<JSReceiver> tmp23;
    TNode<Object> tmp24;
    TNode<JSTypedArray> tmp25;
    TNode<JSTypedArray> tmp26;
    TNode<BuiltinPtr> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<Object> tmp29;
    TNode<UintPtrT> tmp30;
    ca_.Bind(&block3, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31 = ca_.IntPtrConstant(JSArrayBufferView::kBufferOffset);
    USE(tmp31);
    TNode<JSArrayBuffer>tmp32 = CodeStubAssembler(state_).LoadReference<JSArrayBuffer>(CodeStubAssembler::Reference{tmp25, tmp31});
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).IsDetachedBuffer(TNode<JSArrayBuffer>{tmp32});
    ca_.Branch(tmp33, &block10, &block11, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30);
  }

  if (block10.is_used()) {
    TNode<Context> tmp34;
    TNode<JSTypedArray> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<Object> tmp37;
    TNode<JSTypedArray> tmp38;
    TNode<JSTypedArray> tmp39;
    TNode<BuiltinPtr> tmp40;
    TNode<UintPtrT> tmp41;
    TNode<Object> tmp42;
    TNode<UintPtrT> tmp43;
    ca_.Bind(&block10, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block4, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block11.is_used()) {
    TNode<Context> tmp44;
    TNode<JSTypedArray> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<Object> tmp47;
    TNode<JSTypedArray> tmp48;
    TNode<JSTypedArray> tmp49;
    TNode<BuiltinPtr> tmp50;
    TNode<UintPtrT> tmp51;
    TNode<Object> tmp52;
    TNode<UintPtrT> tmp53;
    ca_.Bind(&block11, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<JSTypedArray> tmp54;
    USE(tmp54);
    tmp54 = (TNode<JSTypedArray>{tmp48});
    TNode<Numeric> tmp55 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(1)).descriptor(), tmp50, tmp44, tmp54, tmp53)); 
    USE(tmp55);
    TNode<Oddball> tmp56;
    USE(tmp56);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp56 = Cast_TheHole_0(state_, TNode<Object>{tmp52}, &label0);
    ca_.Goto(&block15, tmp44, tmp45, tmp46, tmp47, tmp48, tmp54, tmp50, tmp51, tmp52, tmp53, tmp55, tmp52, tmp52, tmp56);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp44, tmp45, tmp46, tmp47, tmp48, tmp54, tmp50, tmp51, tmp52, tmp53, tmp55, tmp52, tmp52);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp57;
    TNode<JSTypedArray> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<Object> tmp60;
    TNode<JSTypedArray> tmp61;
    TNode<JSTypedArray> tmp62;
    TNode<BuiltinPtr> tmp63;
    TNode<UintPtrT> tmp64;
    TNode<Object> tmp65;
    TNode<UintPtrT> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    ca_.Bind(&block16, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<Oddball> tmp70;
    USE(tmp70);
    tmp70 = Undefined_0(state_);
    TNode<Number> tmp71;
    USE(tmp71);
    tmp71 = Convert_Number_uintptr_0(state_, TNode<UintPtrT>{tmp66});
    TNode<Object> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).Call(TNode<Context>{tmp57}, TNode<JSReceiver>{tmp59}, TNode<Object>{tmp70}, TNode<Object>{ca_.UncheckedCast<Object>(tmp68)}, TNode<Object>{tmp67}, TNode<Object>{tmp71}, TNode<Object>{tmp61});
    ca_.Goto(&block13, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp72, tmp66, tmp67, tmp68);
  }

  if (block15.is_used()) {
    TNode<Context> tmp73;
    TNode<JSTypedArray> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Object> tmp76;
    TNode<JSTypedArray> tmp77;
    TNode<JSTypedArray> tmp78;
    TNode<BuiltinPtr> tmp79;
    TNode<UintPtrT> tmp80;
    TNode<Object> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<Object> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<Oddball> tmp86;
    ca_.Bind(&block15, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    ca_.Goto(&block13, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp83, tmp82, tmp83, tmp84);
  }

  if (block13.is_used()) {
    TNode<Context> tmp87;
    TNode<JSTypedArray> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Object> tmp90;
    TNode<JSTypedArray> tmp91;
    TNode<JSTypedArray> tmp92;
    TNode<BuiltinPtr> tmp93;
    TNode<UintPtrT> tmp94;
    TNode<Object> tmp95;
    TNode<UintPtrT> tmp96;
    TNode<Object> tmp97;
    TNode<Object> tmp98;
    ca_.Bind(&block13, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    TNode<UintPtrT> tmp99;
    USE(tmp99);
    tmp99 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp96}, TNode<UintPtrT>{tmp99});
    ca_.Goto(&block5, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp100);
  }

  if (block4.is_used()) {
    TNode<Context> tmp101;
    TNode<JSTypedArray> tmp102;
    TNode<JSReceiver> tmp103;
    TNode<Object> tmp104;
    TNode<JSTypedArray> tmp105;
    TNode<JSTypedArray> tmp106;
    TNode<BuiltinPtr> tmp107;
    TNode<UintPtrT> tmp108;
    TNode<Object> tmp109;
    TNode<UintPtrT> tmp110;
    ca_.Bind(&block4, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    TNode<Oddball> tmp111;
    USE(tmp111);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp111 = Cast_TheHole_0(state_, TNode<Object>{tmp109}, &label0);
    ca_.Goto(&block20, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp109, tmp109, tmp111);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp109, tmp109);
    }
  }

  if (block21.is_used()) {
    TNode<Context> tmp112;
    TNode<JSTypedArray> tmp113;
    TNode<JSReceiver> tmp114;
    TNode<Object> tmp115;
    TNode<JSTypedArray> tmp116;
    TNode<JSTypedArray> tmp117;
    TNode<BuiltinPtr> tmp118;
    TNode<UintPtrT> tmp119;
    TNode<Object> tmp120;
    TNode<Object> tmp121;
    TNode<Object> tmp122;
    ca_.Bind(&block21, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    ca_.Goto(&block22, tmp112, tmp113, tmp114, tmp115, ca_.UncheckedCast<Object>(tmp121));
  }

  if (block20.is_used()) {
    TNode<Context> tmp123;
    TNode<JSTypedArray> tmp124;
    TNode<JSReceiver> tmp125;
    TNode<Object> tmp126;
    TNode<JSTypedArray> tmp127;
    TNode<JSTypedArray> tmp128;
    TNode<BuiltinPtr> tmp129;
    TNode<UintPtrT> tmp130;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    TNode<Object> tmp133;
    TNode<Oddball> tmp134;
    ca_.Bind(&block20, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp123}, MessageTemplate::kReduceNoInitial, kBuiltinNameReduce_0(state_));
  }

    TNode<Context> tmp135;
    TNode<JSTypedArray> tmp136;
    TNode<JSReceiver> tmp137;
    TNode<Object> tmp138;
    TNode<Object> tmp139;
    ca_.Bind(&block22, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139);
  return TNode<Object>{tmp139};
}

TF_BUILTIN(TypedArrayPrototypeReduce, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, JSReceiver> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, JSReceiver> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSTypedArray, JSTypedArray, JSReceiver, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp9}, MessageTemplate::kNotTypedArray, kBuiltinNameReduce_0(state_));
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
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp25}, MessageTemplate::kDetachedOperation, kBuiltinNameReduce_0(state_));
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
    tmp61 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).IntPtrGreaterThanOrEqual(TNode<IntPtrT>{tmp53}, TNode<IntPtrT>{tmp61});
    ca_.Branch(tmp62, &block13, &block14, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp60);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp63;
    TNode<RawPtrT> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<NativeContext> tmp66;
    TNode<Object> tmp67;
    TNode<JSTypedArray> tmp68;
    TNode<JSTypedArray> tmp69;
    TNode<JSReceiver> tmp70;
    ca_.Bind(&block13, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<IntPtrT> tmp71;
    USE(tmp71);
    tmp71 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp63}, TNode<RawPtrT>{tmp64}, TNode<IntPtrT>{tmp65}}, TNode<IntPtrT>{tmp71});
    ca_.Goto(&block15, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp72);
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp73;
    TNode<RawPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<NativeContext> tmp76;
    TNode<Object> tmp77;
    TNode<JSTypedArray> tmp78;
    TNode<JSTypedArray> tmp79;
    TNode<JSReceiver> tmp80;
    ca_.Bind(&block14, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<Oddball> tmp81;
    USE(tmp81);
    tmp81 = TheHole_0(state_);
    ca_.Goto(&block15, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81);
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp82;
    TNode<RawPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<NativeContext> tmp85;
    TNode<Object> tmp86;
    TNode<JSTypedArray> tmp87;
    TNode<JSTypedArray> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Object> tmp90;
    ca_.Bind(&block15, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<Object> tmp91;
    USE(tmp91);
    tmp91 = ReduceAllElements_0(state_, TNode<Context>{tmp85}, TNode<JSTypedArray>{tmp88}, TNode<JSReceiver>{tmp89}, TNode<Object>{tmp90});
    arguments.PopAndReturn(tmp91);
  }
}

}  // namespace internal
}  // namespace v8

