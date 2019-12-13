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

void EnsureWriteableFastElements_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSArray> p_array) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Number, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray, FixedArrayBase, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_array);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSArray> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp2);
    TNode<FixedArrayBase>tmp3 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp1, tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp4);
    TNode<Map>tmp5 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp3, tmp4});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = kCOWMap_0(state_);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp5}, TNode<HeapObject>{tmp6});
    ca_.Branch(tmp7, &block6, &block7, tmp0, tmp1, tmp3);
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<JSArray> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastElementsKind(array.map.elements_kind)' failed", "src/builtins/array.tq", 20);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<JSArray> tmp11;
    ca_.Bind(&block4, &tmp10, &tmp11);
  }

  if (block6.is_used()) {
    TNode<Context> tmp12;
    TNode<JSArray> tmp13;
    TNode<FixedArrayBase> tmp14;
    ca_.Bind(&block6, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1, tmp12, tmp13);
  }

  if (block7.is_used()) {
    TNode<Context> tmp15;
    TNode<JSArray> tmp16;
    TNode<FixedArrayBase> tmp17;
    ca_.Bind(&block7, &tmp15, &tmp16, &tmp17);
    TNode<IntPtrT> tmp18 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp18);
    TNode<Number>tmp19 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp16, tmp18});
    TNode<Smi> tmp20;
    USE(tmp20);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp20 = Cast_Smi_0(state_, TNode<Object>{tmp19}, &label0);
    ca_.Goto(&block14, tmp15, tmp16, tmp17, tmp19, tmp20);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp15, tmp16, tmp17, tmp19);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp21;
    TNode<JSArray> tmp22;
    TNode<FixedArrayBase> tmp23;
    ca_.Bind(&block11, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastSmiOrTaggedElementsKind(array.map.elements_kind)' failed", "src/builtins/array.tq", 27);
  }

  if (block10.is_used()) {
    TNode<Context> tmp24;
    TNode<JSArray> tmp25;
    TNode<FixedArrayBase> tmp26;
    ca_.Bind(&block10, &tmp24, &tmp25, &tmp26);
  }

  if (block15.is_used()) {
    TNode<Context> tmp27;
    TNode<JSArray> tmp28;
    TNode<FixedArrayBase> tmp29;
    TNode<Number> tmp30;
    ca_.Bind(&block15, &tmp27, &tmp28, &tmp29, &tmp30);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block14.is_used()) {
    TNode<Context> tmp31;
    TNode<JSArray> tmp32;
    TNode<FixedArrayBase> tmp33;
    TNode<Number> tmp34;
    TNode<Smi> tmp35;
    ca_.Bind(&block14, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    TNode<IntPtrT> tmp36 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp36);
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<FixedArrayBase> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).ExtractFixedArray(TNode<FixedArrayBase>{tmp33}, TNode<Smi>{tmp37}, TNode<Smi>{tmp35}, TNode<Smi>{tmp35}, CodeStubAssembler::ExtractFixedArrayFlag::kFixedArrays);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp32, tmp36}, tmp38);
    ca_.Goto(&block1, tmp31, tmp32);
  }

  if (block19.is_used()) {
    TNode<Context> tmp39;
    TNode<JSArray> tmp40;
    TNode<FixedArrayBase> tmp41;
    TNode<Smi> tmp42;
    ca_.Bind(&block19, &tmp39, &tmp40, &tmp41, &tmp42);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.elements.map != kCOWMap' failed", "src/builtins/array.tq", 32);
  }

  if (block18.is_used()) {
    TNode<Context> tmp43;
    TNode<JSArray> tmp44;
    TNode<FixedArrayBase> tmp45;
    TNode<Smi> tmp46;
    ca_.Bind(&block18, &tmp43, &tmp44, &tmp45, &tmp46);
  }

  if (block1.is_used()) {
    TNode<Context> tmp47;
    TNode<JSArray> tmp48;
    ca_.Bind(&block1, &tmp47, &tmp48);
    ca_.Goto(&block20, tmp47, tmp48);
  }

    TNode<Context> tmp49;
    TNode<JSArray> tmp50;
    ca_.Bind(&block20, &tmp49, &tmp50);
}

TNode<Object> LoadElementOrUndefined_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_a, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_a, p_i);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp3);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp4);
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp2});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp7});
    TNode<UintPtrT> tmp9;
    USE(tmp9);
    tmp9 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp8}, TNode<UintPtrT>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp0, tmp1, tmp2, tmp1, tmp3, tmp6, tmp2, tmp2, tmp7, tmp1, tmp3, tmp6, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<FixedArray> tmp12;
    TNode<Smi> tmp13;
    TNode<FixedArray> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<Smi> tmp17;
    TNode<Smi> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<HeapObject> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp25});
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp26});
    TNode<HeapObject> tmp28;
    USE(tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    std::tie(tmp28, tmp29) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp20}, TNode<IntPtrT>{tmp27}).Flatten();
    TNode<Object>tmp30 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp28, tmp29});
    TNode<Object> tmp31;
    USE(tmp31);
    tmp31 = UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(state_, TNode<Context>{tmp11}, TNode<Object>{tmp30});
    TNode<Object> tmp32;
    USE(tmp32);
    tmp32 = ReplaceTheHoleWithUndefined_0(state_, TNode<Object>{tmp31});
    ca_.Goto(&block9, tmp11, tmp12, tmp13, tmp32);
  }

  if (block7.is_used()) {
    TNode<Context> tmp33;
    TNode<FixedArray> tmp34;
    TNode<Smi> tmp35;
    TNode<FixedArray> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Smi> tmp39;
    TNode<Smi> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<HeapObject> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    ca_.Bind(&block7, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp47;
    TNode<FixedArray> tmp48;
    TNode<Smi> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block9, &tmp47, &tmp48, &tmp49, &tmp50);
  return TNode<Object>{tmp50};
}

TNode<Object> LoadElementOrUndefined_1(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_a, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, FixedDoubleArray, Smi, Float64T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a, p_i);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Float64T> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).LoadDoubleWithHoleCheck(TNode<FixedDoubleArray>{tmp0}, TNode<Smi>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp0, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp0, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<FixedDoubleArray> tmp3;
    TNode<Smi> tmp4;
    TNode<FixedDoubleArray> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Oddball> tmp7;
    USE(tmp7);
    tmp7 = Undefined_0(state_);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<FixedDoubleArray> tmp8;
    TNode<Smi> tmp9;
    TNode<FixedDoubleArray> tmp10;
    TNode<Smi> tmp11;
    TNode<Float64T> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<HeapNumber> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp12});
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<FixedDoubleArray> tmp14;
    TNode<Smi> tmp15;
    TNode<Object> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<FixedDoubleArray> tmp17;
    TNode<Smi> tmp18;
    TNode<Object> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<Object>{tmp19};
}

void StoreArrayHole_0(compiler::CodeAssemblerState* state_, TNode<FixedDoubleArray> p_elements, TNode<Smi> p_k) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedDoubleArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_k);

  if (block0.is_used()) {
    TNode<FixedDoubleArray> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    CodeStubAssembler(state_).StoreFixedDoubleArrayHoleSmi(TNode<FixedDoubleArray>{tmp0}, TNode<Smi>{tmp1});
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<FixedDoubleArray> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
}

void StoreArrayHole_1(compiler::CodeAssemblerState* state_, TNode<FixedArray> p_elements, TNode<Smi> p_k) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_elements, p_k);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp3);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp3});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp7}, TNode<UintPtrT>{tmp8});
    ca_.Branch(tmp9, &block6, &block7, tmp0, tmp1, tmp0, tmp2, tmp5, tmp1, tmp1, tmp6, tmp0, tmp2, tmp5, tmp6, tmp6);
  }

  if (block6.is_used()) {
    TNode<FixedArray> tmp10;
    TNode<Smi> tmp11;
    TNode<FixedArray> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<HeapObject> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp22}, TNode<IntPtrT>{tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp19}, TNode<IntPtrT>{tmp24});
    TNode<HeapObject> tmp26;
    USE(tmp26);
    TNode<IntPtrT> tmp27;
    USE(tmp27);
    std::tie(tmp26, tmp27) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp18}, TNode<IntPtrT>{tmp25}).Flatten();
    TNode<Oddball> tmp28;
    USE(tmp28);
    tmp28 = TheHole_0(state_);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp26, tmp27}, tmp28);
    ca_.Goto(&block9, tmp10, tmp11);
  }

  if (block7.is_used()) {
    TNode<FixedArray> tmp29;
    TNode<Smi> tmp30;
    TNode<FixedArray> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<Smi> tmp34;
    TNode<Smi> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<HeapObject> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block7, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<FixedArray> tmp42;
    TNode<Smi> tmp43;
    ca_.Bind(&block9, &tmp42, &tmp43);
}

void EnsureArrayLengthWritable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_map, compiler::CodeAssemblerLabel* label_Bailout) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, DescriptorArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, DescriptorArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, DescriptorArray, HeapObject, IntPtrT, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_map);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = ConstructorBuiltinsAssembler(state_).IsDictionaryMap(TNode<Map>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<Map> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    ca_.Goto(&block1);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Map> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(Map::kInstanceDescriptorsOffset);
    USE(tmp7);
    TNode<DescriptorArray>tmp8 = CodeStubAssembler(state_).LoadReference<DescriptorArray>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(DescriptorArray::kDescriptorsOffset);
    USE(tmp9);
    TNode<IntPtrT> tmp10 = ca_.IntPtrConstant(DescriptorArray::kNumberOfAllDescriptorsOffset);
    USE(tmp10);
    TNode<Uint16T>tmp11 = CodeStubAssembler(state_).LoadReference<Uint16T>(CodeStubAssembler::Reference{tmp8, tmp10});
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = Convert_intptr_uint16_0(state_, TNode<Uint16T>{tmp11});
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = Convert_intptr_constexpr_int31_0(state_, JSArray::kLengthDescriptorIndex);
    TNode<UintPtrT> tmp14;
    USE(tmp14);
    tmp14 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp13});
    TNode<UintPtrT> tmp15;
    USE(tmp15);
    tmp15 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp12});
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp14}, TNode<UintPtrT>{tmp15});
    ca_.Branch(tmp16, &block9, &block10, tmp5, tmp6, tmp8, tmp8, tmp9, tmp12, tmp13, tmp8, tmp9, tmp12, tmp13, tmp13);
  }

  if (block9.is_used()) {
    TNode<Context> tmp17;
    TNode<Map> tmp18;
    TNode<DescriptorArray> tmp19;
    TNode<DescriptorArray> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<IntPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<HeapObject> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    ca_.Bind(&block9, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, 12);
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp29});
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp25}, TNode<IntPtrT>{tmp30});
    TNode<HeapObject> tmp32;
    USE(tmp32);
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    std::tie(tmp32, tmp33) = UnsafeNewReference_DescriptorEntry_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp31}).Flatten();
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_intptr_0(state_, 4);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34});
    TNode<Object>tmp36 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp32, tmp35});
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp17}, TNode<Object>{tmp36});
    TNode<Smi> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_Smi_constexpr_int31_0(state_, PropertyDetails::kAttributesReadOnlyMask);
    TNode<Smi> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).SmiAnd(TNode<Smi>{tmp37}, TNode<Smi>{tmp38});
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp39}, TNode<Smi>{tmp40});
    ca_.Branch(tmp41, &block16, &block17, tmp17, tmp18, tmp19, tmp32, tmp33, tmp37);
  }

  if (block10.is_used()) {
    TNode<Context> tmp42;
    TNode<Map> tmp43;
    TNode<DescriptorArray> tmp44;
    TNode<DescriptorArray> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<HeapObject> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    ca_.Bind(&block10, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp54;
    TNode<Map> tmp55;
    TNode<DescriptorArray> tmp56;
    TNode<HeapObject> tmp57;
    TNode<IntPtrT> tmp58;
    ca_.Bind(&block15, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(descriptor->key, LengthStringConstant())' failed", "src/builtins/array.tq", 75);
  }

  if (block14.is_used()) {
    TNode<Context> tmp59;
    TNode<Map> tmp60;
    TNode<DescriptorArray> tmp61;
    TNode<HeapObject> tmp62;
    TNode<IntPtrT> tmp63;
    ca_.Bind(&block14, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
  }

  if (block16.is_used()) {
    TNode<Context> tmp64;
    TNode<Map> tmp65;
    TNode<DescriptorArray> tmp66;
    TNode<HeapObject> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<Smi> tmp69;
    ca_.Bind(&block16, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    ca_.Goto(&block1);
  }

  if (block17.is_used()) {
    TNode<Context> tmp70;
    TNode<Map> tmp71;
    TNode<DescriptorArray> tmp72;
    TNode<HeapObject> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<Smi> tmp75;
    ca_.Bind(&block17, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    ca_.Goto(&block18, tmp70, tmp71);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Bailout);
  }

    TNode<Context> tmp76;
    TNode<Map> tmp77;
    ca_.Bind(&block18, &tmp76, &tmp77);
}

TNode<Object> UnsafeCast_JSReceiver_OR_Smi_OR_HeapNumber_OR_BigInt_OR_String_OR_Symbol_OR_True_OR_False_OR_Null_OR_Undefined_OR_TheHole_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = (TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Object>{tmp9};
}

}  // namespace internal
}  // namespace v8

