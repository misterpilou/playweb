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

TNode<Object> LoadWithHoleCheck_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedArray, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedArray, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedArray, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArrayBase> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<FixedArray> tmp3;
    USE(tmp3);
    tmp3 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp4);
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp5);
    TNode<Smi>tmp6 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp3, tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp2});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<UintPtrT> tmp10;
    USE(tmp10);
    tmp10 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp9}, TNode<UintPtrT>{tmp10});
    ca_.Branch(tmp11, &block7, &block8, tmp0, tmp1, tmp2, tmp3, tmp3, tmp4, tmp7, tmp2, tmp2, tmp8, tmp3, tmp4, tmp7, tmp8, tmp8);
  }

  if (block7.is_used()) {
    TNode<Context> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<Smi> tmp14;
    TNode<FixedArray> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<HeapObject> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    ca_.Bind(&block7, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp26}, TNode<IntPtrT>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp23}, TNode<IntPtrT>{tmp28});
    TNode<HeapObject> tmp30;
    USE(tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    std::tie(tmp30, tmp31) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp22}, TNode<IntPtrT>{tmp29}).Flatten();
    TNode<Object>tmp32 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp30, tmp31});
    TNode<Oddball> tmp33;
    USE(tmp33);
    tmp33 = TheHole_0(state_);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp32}, TNode<HeapObject>{tmp33});
    ca_.Branch(tmp34, &block10, &block11, tmp12, tmp13, tmp14, tmp15, tmp32);
  }

  if (block8.is_used()) {
    TNode<Context> tmp35;
    TNode<FixedArrayBase> tmp36;
    TNode<Smi> tmp37;
    TNode<FixedArray> tmp38;
    TNode<FixedArray> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<HeapObject> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    ca_.Bind(&block8, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block10.is_used()) {
    TNode<Context> tmp50;
    TNode<FixedArrayBase> tmp51;
    TNode<Smi> tmp52;
    TNode<FixedArray> tmp53;
    TNode<Object> tmp54;
    ca_.Bind(&block10, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Goto(label_IfHole);
  }

  if (block11.is_used()) {
    TNode<Context> tmp55;
    TNode<FixedArrayBase> tmp56;
    TNode<Smi> tmp57;
    TNode<FixedArray> tmp58;
    TNode<Object> tmp59;
    ca_.Bind(&block11, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<Object> tmp60;
    USE(tmp60);
    tmp60 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp55}, TNode<Object>{tmp59});
    ca_.Goto(&block12, tmp55, tmp56, tmp57, tmp60);
  }

    TNode<Context> tmp61;
    TNode<FixedArrayBase> tmp62;
    TNode<Smi> tmp63;
    TNode<Object> tmp64;
    ca_.Bind(&block12, &tmp61, &tmp62, &tmp63, &tmp64);
  return TNode<Object>{tmp64};
}

TNode<Object> LoadWithHoleCheck_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArrayBase> p_elements, TNode<Smi> p_index, compiler::CodeAssemblerLabel* label_IfHole) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedDoubleArray, FixedDoubleArray, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, FixedDoubleArray, FixedDoubleArray, Smi, Float64T> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArrayBase, Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_elements, p_index);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArrayBase> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<FixedDoubleArray> tmp3;
    USE(tmp3);
    tmp3 = UnsafeCast_FixedDoubleArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Float64T> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = CodeStubAssembler(state_).LoadDoubleWithHoleCheck(TNode<FixedDoubleArray>{tmp3}, TNode<Smi>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp3, tmp2, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp3, tmp2);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<FixedArrayBase> tmp6;
    TNode<Smi> tmp7;
    TNode<FixedDoubleArray> tmp8;
    TNode<FixedDoubleArray> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    ca_.Goto(label_IfHole);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<FixedArrayBase> tmp12;
    TNode<Smi> tmp13;
    TNode<FixedDoubleArray> tmp14;
    TNode<FixedDoubleArray> tmp15;
    TNode<Smi> tmp16;
    TNode<Float64T> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<HeapNumber> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp17});
    ca_.Goto(&block5, tmp11, tmp12, tmp13, tmp18);
  }

    TNode<Context> tmp19;
    TNode<FixedArrayBase> tmp20;
    TNode<Smi> tmp21;
    TNode<Object> tmp22;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22);
  return TNode<Object>{tmp22};
}

TNode<Number> GetFromIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_length, TorqueStructArguments p_arguments) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT, Number, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, RawPtrT, RawPtrT, IntPtrT, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_length, p_arguments.frame, p_arguments.base, p_arguments.length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Number> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp7;
    TNode<Number> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Number> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp8}, TNode<Number>{tmp12});
    ca_.Goto(&block4, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block3.is_used()) {
    TNode<Context> tmp14;
    TNode<Number> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<RawPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    ca_.Bind(&block3, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp16}, TNode<RawPtrT>{tmp17}, TNode<IntPtrT>{tmp18}}, TNode<IntPtrT>{tmp19});
    TNode<Number> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp14}, TNode<Object>{tmp20}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    ca_.Goto(&block4, tmp14, tmp15, tmp16, tmp17, tmp18, tmp21);
  }

  if (block4.is_used()) {
    TNode<Context> tmp22;
    TNode<Number> tmp23;
    TNode<RawPtrT> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<Number> tmp27;
    ca_.Bind(&block4, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<Smi> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<Number> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number>{tmp27}, TNode<Number>{tmp29});
    ca_.Branch(tmp30, &block6, &block7, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block6.is_used()) {
    TNode<Context> tmp31;
    TNode<Number> tmp32;
    TNode<RawPtrT> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<Number> tmp36;
    TNode<Number> tmp37;
    ca_.Bind(&block6, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<Number> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp32}, TNode<Number>{tmp38});
    TNode<Number> tmp40;
    USE(tmp40);
    tmp40 = Min_0(state_, TNode<Number>{tmp36}, TNode<Number>{tmp39});
    ca_.Goto(&block8, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp40);
  }

  if (block7.is_used()) {
    TNode<Context> tmp41;
    TNode<Number> tmp42;
    TNode<RawPtrT> tmp43;
    TNode<RawPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<Number> tmp46;
    TNode<Number> tmp47;
    ca_.Bind(&block7, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Number> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp42}, TNode<Number>{tmp46});
    ca_.Goto(&block8, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp48);
  }

  if (block8.is_used()) {
    TNode<Context> tmp49;
    TNode<Number> tmp50;
    TNode<RawPtrT> tmp51;
    TNode<RawPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<Number> tmp54;
    TNode<Number> tmp55;
    ca_.Bind(&block8, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block9, tmp49, tmp50, tmp51, tmp52, tmp53, tmp55);
  }

    TNode<Context> tmp56;
    TNode<Number> tmp57;
    TNode<RawPtrT> tmp58;
    TNode<RawPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<Number> tmp61;
    ca_.Bind(&block9, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
  return TNode<Number>{tmp61};
}

TNode<Object> TryFastArrayLastIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<Object> p_searchElement, TNode<Number> p_from, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSReceiver, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSReceiver, Context, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Number, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Smi, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Smi, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Smi, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, JSArray, Smi, Smi, Int32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_searchElement, p_from);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Object> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSArray> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_FastJSArray_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<JSReceiver> tmp6;
    TNode<Object> tmp7;
    TNode<Number> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<Number> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Context> tmp16;
    TNode<JSArray> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp17});
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp18}, TNode<Smi>{tmp19});
    ca_.Branch(tmp20, &block5, &block6, tmp11, tmp12, tmp13, tmp14, tmp17, tmp18);
  }

  if (block5.is_used()) {
    TNode<Context> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Object> tmp23;
    TNode<Number> tmp24;
    TNode<JSArray> tmp25;
    TNode<Smi> tmp26;
    ca_.Bind(&block5, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<Smi> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).SmiConstant(-1);
    ca_.Goto(&block2, tmp21, tmp22, tmp23, tmp24, tmp27);
  }

  if (block6.is_used()) {
    TNode<Context> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Object> tmp30;
    TNode<Number> tmp31;
    TNode<JSArray> tmp32;
    TNode<Smi> tmp33;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Smi> tmp34;
    USE(tmp34);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp34 = Cast_Smi_0(state_, TNode<Object>{tmp31}, &label0);
    ca_.Goto(&block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp31, tmp34);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp31);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp35;
    TNode<JSReceiver> tmp36;
    TNode<Object> tmp37;
    TNode<Number> tmp38;
    TNode<JSArray> tmp39;
    TNode<Smi> tmp40;
    TNode<Number> tmp41;
    ca_.Bind(&block8, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    TNode<Context> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<Object> tmp44;
    TNode<Number> tmp45;
    TNode<JSArray> tmp46;
    TNode<Smi> tmp47;
    TNode<Number> tmp48;
    TNode<Smi> tmp49;
    ca_.Bind(&block7, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<IntPtrT> tmp50 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp50);
    TNode<Map>tmp51 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp46, tmp50});
    TNode<Int32T> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).LoadMapElementsKind(TNode<Map>{tmp51});
    TNode<BoolT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).IsFastSmiOrTaggedElementsKind(TNode<Int32T>{tmp52});
    ca_.Branch(tmp53, &block9, &block10, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp49, tmp52);
  }

  if (block9.is_used()) {
    TNode<Context> tmp54;
    TNode<JSReceiver> tmp55;
    TNode<Object> tmp56;
    TNode<Number> tmp57;
    TNode<JSArray> tmp58;
    TNode<Smi> tmp59;
    TNode<Smi> tmp60;
    TNode<Int32T> tmp61;
    ca_.Bind(&block9, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<Smi> tmp62;
    USE(tmp62);
    tmp62 = FastArrayLastIndexOf_FixedArray_0(state_, TNode<Context>{tmp54}, TNode<JSArray>{tmp58}, TNode<Smi>{tmp60}, TNode<Object>{tmp56});
    ca_.Goto(&block2, tmp54, tmp55, tmp56, tmp57, tmp62);
  }

  if (block10.is_used()) {
    TNode<Context> tmp63;
    TNode<JSReceiver> tmp64;
    TNode<Object> tmp65;
    TNode<Number> tmp66;
    TNode<JSArray> tmp67;
    TNode<Smi> tmp68;
    TNode<Smi> tmp69;
    TNode<Int32T> tmp70;
    ca_.Bind(&block10, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<Smi> tmp71;
    USE(tmp71);
    tmp71 = FastArrayLastIndexOf_FixedDoubleArray_0(state_, TNode<Context>{tmp63}, TNode<JSArray>{tmp67}, TNode<Smi>{tmp69}, TNode<Object>{tmp65});
    ca_.Goto(&block2, tmp63, tmp64, tmp65, tmp66, tmp71);
  }

  if (block14.is_used()) {
    TNode<Context> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<Object> tmp74;
    TNode<Number> tmp75;
    TNode<JSArray> tmp76;
    TNode<Smi> tmp77;
    TNode<Smi> tmp78;
    TNode<Int32T> tmp79;
    ca_.Bind(&block14, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsDoubleElementsKind(kind)' failed", "src/builtins/array-lastindexof.tq", 96);
  }

  if (block13.is_used()) {
    TNode<Context> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<Object> tmp82;
    TNode<Number> tmp83;
    TNode<JSArray> tmp84;
    TNode<Smi> tmp85;
    TNode<Smi> tmp86;
    TNode<Int32T> tmp87;
    ca_.Bind(&block13, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87);
  }

  if (block2.is_used()) {
    TNode<Context> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Object> tmp90;
    TNode<Number> tmp91;
    TNode<Object> tmp92;
    ca_.Bind(&block2, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92);
    ca_.Goto(&block15, tmp88, tmp89, tmp90, tmp91, tmp92);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

    TNode<Context> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    TNode<Number> tmp96;
    TNode<Object> tmp97;
    ca_.Bind(&block15, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
  return TNode<Object>{tmp97};
}

TNode<Object> GenericArrayLastIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_object, TNode<Object> p_searchElement, TNode<Number> p_from) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number, Oddball, Object, Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number, Oddball, Object, Oddball> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Object, Number, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_object, p_searchElement, p_from);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Object> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp3);
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<JSReceiver> tmp5;
    TNode<Object> tmp6;
    TNode<Number> tmp7;
    TNode<Number> tmp8;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Number> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number>{tmp8}, TNode<Number>{tmp9});
    ca_.Branch(tmp10, &block2, &block3, tmp4, tmp5, tmp6, tmp7, tmp8);
  }

  if (block2.is_used()) {
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    TNode<Object> tmp13;
    TNode<Number> tmp14;
    TNode<Number> tmp15;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Oddball> tmp16;
    tmp16 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kHasProperty, tmp11, tmp12, tmp15));
    USE(tmp16);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = True_0(state_);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp16}, TNode<HeapObject>{tmp17});
    ca_.Branch(tmp18, &block5, &block6, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Object> tmp21;
    TNode<Number> tmp22;
    TNode<Number> tmp23;
    TNode<Oddball> tmp24;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp19}, TNode<Object>{tmp20}, TNode<Object>{tmp23});
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{tmp21}, TNode<Object>{tmp25});
    TNode<Oddball> tmp27;
    USE(tmp27);
    tmp27 = True_0(state_);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block7, &block8, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block7.is_used()) {
    TNode<Context> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<Object> tmp31;
    TNode<Number> tmp32;
    TNode<Number> tmp33;
    TNode<Oddball> tmp34;
    TNode<Object> tmp35;
    TNode<Oddball> tmp36;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    ca_.Goto(&block1, tmp29, tmp30, tmp31, tmp32, tmp33);
  }

  if (block8.is_used()) {
    TNode<Context> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<Object> tmp39;
    TNode<Number> tmp40;
    TNode<Number> tmp41;
    TNode<Oddball> tmp42;
    TNode<Object> tmp43;
    TNode<Oddball> tmp44;
    ca_.Bind(&block8, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    ca_.Goto(&block6, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42);
  }

  if (block6.is_used()) {
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<Object> tmp47;
    TNode<Number> tmp48;
    TNode<Number> tmp49;
    TNode<Oddball> tmp50;
    ca_.Bind(&block6, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<Number> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp49}, TNode<Number>{tmp51});
    ca_.Goto(&block4, tmp45, tmp46, tmp47, tmp48, tmp52);
  }

  if (block3.is_used()) {
    TNode<Context> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<Object> tmp55;
    TNode<Number> tmp56;
    TNode<Number> tmp57;
    ca_.Bind(&block3, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<Smi> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).SmiConstant(-1);
    ca_.Goto(&block1, tmp53, tmp54, tmp55, tmp56, tmp58);
  }

  if (block1.is_used()) {
    TNode<Context> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Object> tmp61;
    TNode<Number> tmp62;
    TNode<Object> tmp63;
    ca_.Bind(&block1, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    ca_.Goto(&block9, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

    TNode<Context> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<Object> tmp66;
    TNode<Number> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block9, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68);
  return TNode<Object>{tmp68};
}

TF_BUILTIN(ArrayPrototypeLastIndexOf, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Object, NativeContext, JSReceiver, Object, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Object, NativeContext, JSReceiver, Object, Number, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = GetLengthProperty_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp5});
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = IsNumberEqual_0(state_, TNode<Number>{tmp6}, TNode<Number>{tmp7});
    ca_.Branch(tmp8, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp9;
    TNode<RawPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<NativeContext> tmp12;
    TNode<Object> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<Number> tmp15;
    ca_.Bind(&block1, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).SmiConstant(-1);
    arguments.PopAndReturn(tmp16);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<NativeContext> tmp20;
    TNode<Object> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Number> tmp23;
    ca_.Bind(&block2, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<Number> tmp24;
    USE(tmp24);
    tmp24 = GetFromIndex_0(state_, TNode<Context>{tmp20}, TNode<Number>{tmp23}, TorqueStructArguments{TNode<RawPtrT>{tmp17}, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp19}});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp17}, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp19}}, TNode<IntPtrT>{tmp25});
    TNode<Object> tmp27;
    USE(tmp27);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp27 = TryFastArrayLastIndexOf_0(state_, TNode<Context>{tmp20}, TNode<JSReceiver>{tmp22}, TNode<Object>{tmp26}, TNode<Number>{tmp24}, &label0);
    ca_.Goto(&block5, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp26, tmp20, tmp22, tmp26, tmp24, tmp27);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp26, tmp20, tmp22, tmp26, tmp24);
    }
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp28;
    TNode<RawPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Number> tmp34;
    TNode<Number> tmp35;
    TNode<Object> tmp36;
    TNode<NativeContext> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<Object> tmp39;
    TNode<Number> tmp40;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<Object> tmp41;
    USE(tmp41);
    tmp41 = GenericArrayLastIndexOf_0(state_, TNode<Context>{tmp31}, TNode<JSReceiver>{tmp33}, TNode<Object>{tmp36}, TNode<Number>{tmp35});
    arguments.PopAndReturn(tmp41);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp42;
    TNode<RawPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<Number> tmp48;
    TNode<Number> tmp49;
    TNode<Object> tmp50;
    TNode<NativeContext> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    TNode<Number> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block5, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    arguments.PopAndReturn(tmp55);
  }
}

TNode<Smi> FastArrayLastIndexOf_FixedArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, FixedArrayBase, Smi, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, FixedArrayBase, Smi, Context, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array, p_from, p_searchElement);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp4);
    TNode<FixedArrayBase>tmp5 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp6);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp6});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<JSArray> tmp10;
    TNode<Smi> tmp11;
    TNode<Object> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp15);
    TNode<Smi>tmp16 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp13, tmp15});
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp16}, TNode<Smi>{tmp17});
    ca_.Goto(&block3, tmp9, tmp10, tmp11, tmp12, tmp13, tmp18);
  }

  if (block3.is_used()) {
    TNode<Context> tmp19;
    TNode<JSArray> tmp20;
    TNode<Smi> tmp21;
    TNode<Object> tmp22;
    TNode<FixedArrayBase> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block3, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Goto(&block6, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24);
  }

  if (block6.is_used()) {
    TNode<Context> tmp25;
    TNode<JSArray> tmp26;
    TNode<Smi> tmp27;
    TNode<Object> tmp28;
    TNode<FixedArrayBase> tmp29;
    TNode<Smi> tmp30;
    ca_.Bind(&block6, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp31});
    ca_.Branch(tmp32, &block4, &block5, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30);
  }

  if (block4.is_used()) {
    TNode<Context> tmp33;
    TNode<JSArray> tmp34;
    TNode<Smi> tmp35;
    TNode<Object> tmp36;
    TNode<FixedArrayBase> tmp37;
    TNode<Smi> tmp38;
    ca_.Bind(&block4, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<Object> tmp39;
    USE(tmp39);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp39 = LoadWithHoleCheck_FixedArray_0(state_, TNode<Context>{tmp33}, TNode<FixedArrayBase>{tmp37}, TNode<Smi>{tmp38}, &label0);
    ca_.Goto(&block9, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp37, tmp38, tmp33, tmp39);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp37, tmp38, tmp33);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp40;
    TNode<JSArray> tmp41;
    TNode<Smi> tmp42;
    TNode<Object> tmp43;
    TNode<FixedArrayBase> tmp44;
    TNode<Smi> tmp45;
    TNode<FixedArrayBase> tmp46;
    TNode<Smi> tmp47;
    TNode<Context> tmp48;
    ca_.Bind(&block10, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    ca_.Goto(&block7, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45);
  }

  if (block9.is_used()) {
    TNode<Context> tmp49;
    TNode<JSArray> tmp50;
    TNode<Smi> tmp51;
    TNode<Object> tmp52;
    TNode<FixedArrayBase> tmp53;
    TNode<Smi> tmp54;
    TNode<FixedArrayBase> tmp55;
    TNode<Smi> tmp56;
    TNode<Context> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<Oddball> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{tmp52}, TNode<Object>{tmp58});
    TNode<Oddball> tmp60;
    USE(tmp60);
    tmp60 = True_0(state_);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp59}, TNode<HeapObject>{tmp60});
    ca_.Branch(tmp61, &block11, &block12, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp58, tmp59);
  }

  if (block11.is_used()) {
    TNode<Context> tmp62;
    TNode<JSArray> tmp63;
    TNode<Smi> tmp64;
    TNode<Object> tmp65;
    TNode<FixedArrayBase> tmp66;
    TNode<Smi> tmp67;
    TNode<Object> tmp68;
    TNode<Oddball> tmp69;
    ca_.Bind(&block11, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    ca_.Goto(&block1, tmp62, tmp63, tmp64, tmp65, tmp67);
  }

  if (block16.is_used()) {
    TNode<Context> tmp70;
    TNode<JSArray> tmp71;
    TNode<Smi> tmp72;
    TNode<Object> tmp73;
    TNode<FixedArrayBase> tmp74;
    TNode<Smi> tmp75;
    TNode<Object> tmp76;
    TNode<Oddball> tmp77;
    ca_.Bind(&block16, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", "src/builtins/array-lastindexof.tq", 48);
  }

  if (block15.is_used()) {
    TNode<Context> tmp78;
    TNode<JSArray> tmp79;
    TNode<Smi> tmp80;
    TNode<Object> tmp81;
    TNode<FixedArrayBase> tmp82;
    TNode<Smi> tmp83;
    TNode<Object> tmp84;
    TNode<Oddball> tmp85;
    ca_.Bind(&block15, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
  }

  if (block12.is_used()) {
    TNode<Context> tmp86;
    TNode<JSArray> tmp87;
    TNode<Smi> tmp88;
    TNode<Object> tmp89;
    TNode<FixedArrayBase> tmp90;
    TNode<Smi> tmp91;
    TNode<Object> tmp92;
    TNode<Oddball> tmp93;
    ca_.Bind(&block12, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    ca_.Goto(&block7, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91);
  }

  if (block7.is_used()) {
    TNode<Context> tmp94;
    TNode<JSArray> tmp95;
    TNode<Smi> tmp96;
    TNode<Object> tmp97;
    TNode<FixedArrayBase> tmp98;
    TNode<Smi> tmp99;
    ca_.Bind(&block7, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<Smi> tmp100;
    USE(tmp100);
    tmp100 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp99}, TNode<Smi>{tmp100});
    ca_.Goto(&block6, tmp94, tmp95, tmp96, tmp97, tmp98, tmp101);
  }

  if (block5.is_used()) {
    TNode<Context> tmp102;
    TNode<JSArray> tmp103;
    TNode<Smi> tmp104;
    TNode<Object> tmp105;
    TNode<FixedArrayBase> tmp106;
    TNode<Smi> tmp107;
    ca_.Bind(&block5, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    TNode<Smi> tmp108;
    USE(tmp108);
    tmp108 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp102, tmp103, tmp104, tmp105, tmp108);
  }

  if (block20.is_used()) {
    TNode<Context> tmp109;
    TNode<JSArray> tmp110;
    TNode<Smi> tmp111;
    TNode<Object> tmp112;
    TNode<FixedArrayBase> tmp113;
    TNode<Smi> tmp114;
    ca_.Bind(&block20, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", "src/builtins/array-lastindexof.tq", 57);
  }

  if (block19.is_used()) {
    TNode<Context> tmp115;
    TNode<JSArray> tmp116;
    TNode<Smi> tmp117;
    TNode<Object> tmp118;
    TNode<FixedArrayBase> tmp119;
    TNode<Smi> tmp120;
    ca_.Bind(&block19, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120);
  }

  if (block1.is_used()) {
    TNode<Context> tmp121;
    TNode<JSArray> tmp122;
    TNode<Smi> tmp123;
    TNode<Object> tmp124;
    TNode<Smi> tmp125;
    ca_.Bind(&block1, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    ca_.Goto(&block21, tmp121, tmp122, tmp123, tmp124, tmp125);
  }

    TNode<Context> tmp126;
    TNode<JSArray> tmp127;
    TNode<Smi> tmp128;
    TNode<Object> tmp129;
    TNode<Smi> tmp130;
    ca_.Bind(&block21, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
  return TNode<Smi>{tmp130};
}

TNode<Smi> FastArrayLastIndexOf_FixedDoubleArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array, TNode<Smi> p_from, TNode<Object> p_searchElement) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, FixedArrayBase, Smi, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, FixedArrayBase, Smi, Context, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi, Object, Oddball> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, FixedArrayBase, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, Smi, Object, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array, p_from, p_searchElement);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp4);
    TNode<FixedArrayBase>tmp5 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp6);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp5, tmp6});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<JSArray> tmp10;
    TNode<Smi> tmp11;
    TNode<Object> tmp12;
    TNode<FixedArrayBase> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp15);
    TNode<Smi>tmp16 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp13, tmp15});
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp16}, TNode<Smi>{tmp17});
    ca_.Goto(&block3, tmp9, tmp10, tmp11, tmp12, tmp13, tmp18);
  }

  if (block3.is_used()) {
    TNode<Context> tmp19;
    TNode<JSArray> tmp20;
    TNode<Smi> tmp21;
    TNode<Object> tmp22;
    TNode<FixedArrayBase> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block3, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Goto(&block6, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24);
  }

  if (block6.is_used()) {
    TNode<Context> tmp25;
    TNode<JSArray> tmp26;
    TNode<Smi> tmp27;
    TNode<Object> tmp28;
    TNode<FixedArrayBase> tmp29;
    TNode<Smi> tmp30;
    ca_.Bind(&block6, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).SmiGreaterThanOrEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp31});
    ca_.Branch(tmp32, &block4, &block5, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30);
  }

  if (block4.is_used()) {
    TNode<Context> tmp33;
    TNode<JSArray> tmp34;
    TNode<Smi> tmp35;
    TNode<Object> tmp36;
    TNode<FixedArrayBase> tmp37;
    TNode<Smi> tmp38;
    ca_.Bind(&block4, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<Object> tmp39;
    USE(tmp39);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp39 = LoadWithHoleCheck_FixedDoubleArray_0(state_, TNode<Context>{tmp33}, TNode<FixedArrayBase>{tmp37}, TNode<Smi>{tmp38}, &label0);
    ca_.Goto(&block9, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp37, tmp38, tmp33, tmp39);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp37, tmp38, tmp33);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp40;
    TNode<JSArray> tmp41;
    TNode<Smi> tmp42;
    TNode<Object> tmp43;
    TNode<FixedArrayBase> tmp44;
    TNode<Smi> tmp45;
    TNode<FixedArrayBase> tmp46;
    TNode<Smi> tmp47;
    TNode<Context> tmp48;
    ca_.Bind(&block10, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    ca_.Goto(&block7, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45);
  }

  if (block9.is_used()) {
    TNode<Context> tmp49;
    TNode<JSArray> tmp50;
    TNode<Smi> tmp51;
    TNode<Object> tmp52;
    TNode<FixedArrayBase> tmp53;
    TNode<Smi> tmp54;
    TNode<FixedArrayBase> tmp55;
    TNode<Smi> tmp56;
    TNode<Context> tmp57;
    TNode<Object> tmp58;
    ca_.Bind(&block9, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    TNode<Oddball> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).StrictEqual(TNode<Object>{tmp52}, TNode<Object>{tmp58});
    TNode<Oddball> tmp60;
    USE(tmp60);
    tmp60 = True_0(state_);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp59}, TNode<HeapObject>{tmp60});
    ca_.Branch(tmp61, &block11, &block12, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp58, tmp59);
  }

  if (block11.is_used()) {
    TNode<Context> tmp62;
    TNode<JSArray> tmp63;
    TNode<Smi> tmp64;
    TNode<Object> tmp65;
    TNode<FixedArrayBase> tmp66;
    TNode<Smi> tmp67;
    TNode<Object> tmp68;
    TNode<Oddball> tmp69;
    ca_.Bind(&block11, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    ca_.Goto(&block1, tmp62, tmp63, tmp64, tmp65, tmp67);
  }

  if (block16.is_used()) {
    TNode<Context> tmp70;
    TNode<JSArray> tmp71;
    TNode<Smi> tmp72;
    TNode<Object> tmp73;
    TNode<FixedArrayBase> tmp74;
    TNode<Smi> tmp75;
    TNode<Object> tmp76;
    TNode<Oddball> tmp77;
    ca_.Bind(&block16, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", "src/builtins/array-lastindexof.tq", 48);
  }

  if (block15.is_used()) {
    TNode<Context> tmp78;
    TNode<JSArray> tmp79;
    TNode<Smi> tmp80;
    TNode<Object> tmp81;
    TNode<FixedArrayBase> tmp82;
    TNode<Smi> tmp83;
    TNode<Object> tmp84;
    TNode<Oddball> tmp85;
    ca_.Bind(&block15, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
  }

  if (block12.is_used()) {
    TNode<Context> tmp86;
    TNode<JSArray> tmp87;
    TNode<Smi> tmp88;
    TNode<Object> tmp89;
    TNode<FixedArrayBase> tmp90;
    TNode<Smi> tmp91;
    TNode<Object> tmp92;
    TNode<Oddball> tmp93;
    ca_.Bind(&block12, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93);
    ca_.Goto(&block7, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91);
  }

  if (block7.is_used()) {
    TNode<Context> tmp94;
    TNode<JSArray> tmp95;
    TNode<Smi> tmp96;
    TNode<Object> tmp97;
    TNode<FixedArrayBase> tmp98;
    TNode<Smi> tmp99;
    ca_.Bind(&block7, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<Smi> tmp100;
    USE(tmp100);
    tmp100 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp99}, TNode<Smi>{tmp100});
    ca_.Goto(&block6, tmp94, tmp95, tmp96, tmp97, tmp98, tmp101);
  }

  if (block5.is_used()) {
    TNode<Context> tmp102;
    TNode<JSArray> tmp103;
    TNode<Smi> tmp104;
    TNode<Object> tmp105;
    TNode<FixedArrayBase> tmp106;
    TNode<Smi> tmp107;
    ca_.Bind(&block5, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    TNode<Smi> tmp108;
    USE(tmp108);
    tmp108 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp102, tmp103, tmp104, tmp105, tmp108);
  }

  if (block20.is_used()) {
    TNode<Context> tmp109;
    TNode<JSArray> tmp110;
    TNode<Smi> tmp111;
    TNode<Object> tmp112;
    TNode<FixedArrayBase> tmp113;
    TNode<Smi> tmp114;
    ca_.Bind(&block20, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSArray>(array)' failed", "src/builtins/array-lastindexof.tq", 57);
  }

  if (block19.is_used()) {
    TNode<Context> tmp115;
    TNode<JSArray> tmp116;
    TNode<Smi> tmp117;
    TNode<Object> tmp118;
    TNode<FixedArrayBase> tmp119;
    TNode<Smi> tmp120;
    ca_.Bind(&block19, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120);
  }

  if (block1.is_used()) {
    TNode<Context> tmp121;
    TNode<JSArray> tmp122;
    TNode<Smi> tmp123;
    TNode<Object> tmp124;
    TNode<Smi> tmp125;
    ca_.Bind(&block1, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    ca_.Goto(&block21, tmp121, tmp122, tmp123, tmp124, tmp125);
  }

    TNode<Context> tmp126;
    TNode<JSArray> tmp127;
    TNode<Smi> tmp128;
    TNode<Object> tmp129;
    TNode<Smi> tmp130;
    ca_.Bind(&block21, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
  return TNode<Smi>{tmp130};
}

TNode<BoolT> Is_FastJSArray_JSArray_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, JSArray, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, JSArray, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArray_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<JSArray> tmp4;
    TNode<JSArray> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<JSArray> tmp9;
    TNode<JSArray> tmp10;
    TNode<Context> tmp11;
    TNode<JSArray> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<JSArray> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<JSArray> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

}  // namespace internal
}  // namespace v8

