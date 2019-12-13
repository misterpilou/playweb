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

void RegExpReplaceCallableNoExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesLength, TNode<String> p_string, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Object, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, HeapObject> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, HeapObject, String> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, String, Object, String, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object, String, Object, String, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver, Smi, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, String, JSReceiver> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_matchesElements, p_matchesLength, p_string, p_replaceFn);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<String> tmp3;
    TNode<JSReceiver> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<FixedArray> tmp8;
    TNode<IntPtrT> tmp9;
    TNode<String> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<Smi> tmp12;
    TNode<IntPtrT> tmp13;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp13}, TNode<IntPtrT>{tmp9});
    ca_.Branch(tmp14, &block2, &block3, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13);
  }

  if (block2.is_used()) {
    TNode<Context> tmp15;
    TNode<FixedArray> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<String> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    ca_.Bind(&block2, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<IntPtrT> tmp22 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp22);
    TNode<IntPtrT> tmp23 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp23);
    TNode<Smi>tmp24 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp16, tmp23});
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    tmp25 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp24});
    TNode<UintPtrT> tmp26;
    USE(tmp26);
    tmp26 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp21});
    TNode<UintPtrT> tmp27;
    USE(tmp27);
    tmp27 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp25});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp26}, TNode<UintPtrT>{tmp27});
    ca_.Branch(tmp28, &block10, &block11, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp16, tmp22, tmp25, tmp21, tmp21, tmp16, tmp22, tmp25, tmp21, tmp21);
  }

  if (block10.is_used()) {
    TNode<Context> tmp29;
    TNode<FixedArray> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<String> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Smi> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<FixedArray> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<HeapObject> tmp41;
    TNode<IntPtrT> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    ca_.Bind(&block10, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp45}, TNode<IntPtrT>{tmp46});
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp42}, TNode<IntPtrT>{tmp47});
    TNode<HeapObject> tmp49;
    USE(tmp49);
    TNode<IntPtrT> tmp50;
    USE(tmp50);
    std::tie(tmp49, tmp50) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp41}, TNode<IntPtrT>{tmp48}).Flatten();
    TNode<Object>tmp51 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp49, tmp50});
    TNode<Smi> tmp52;
    USE(tmp52);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp52 = Cast_Smi_0(state_, TNode<Object>{tmp51}, &label0);
    ca_.Goto(&block15, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp51, tmp51, tmp52);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp51, tmp51);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp53;
    TNode<FixedArray> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<String> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<Smi> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<FixedArray> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<HeapObject> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    ca_.Bind(&block11, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block16.is_used()) {
    TNode<Context> tmp70;
    TNode<FixedArray> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<String> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Smi> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    ca_.Bind(&block16, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<String> tmp79;
    USE(tmp79);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp79 = Cast_String_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp77)}, &label0);
    ca_.Goto(&block29, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, ca_.UncheckedCast<HeapObject>(tmp77), tmp79);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block30, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, ca_.UncheckedCast<HeapObject>(tmp77));
    }
  }

  if (block15.is_used()) {
    TNode<Context> tmp80;
    TNode<FixedArray> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<String> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Smi> tmp85;
    TNode<IntPtrT> tmp86;
    TNode<Object> tmp87;
    TNode<Object> tmp88;
    TNode<Smi> tmp89;
    ca_.Bind(&block15, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<Smi> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp89}, TNode<Smi>{tmp90});
    ca_.Branch(tmp91, &block17, &block18, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp89);
  }

  if (block17.is_used()) {
    TNode<Context> tmp92;
    TNode<FixedArray> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<String> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<Smi> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<Object> tmp99;
    TNode<Smi> tmp100;
    ca_.Bind(&block17, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<IntPtrT> tmp101;
    USE(tmp101);
    tmp101 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp100});
    TNode<IntPtrT> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_intptr_constexpr_int31_0(state_, 11);
    TNode<IntPtrT> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{tmp101}, TNode<IntPtrT>{tmp102});
    TNode<IntPtrT> tmp104;
    USE(tmp104);
    tmp104 = FromConstexpr_intptr_constexpr_int31_0(state_, 0x7FF);
    TNode<IntPtrT> tmp105;
    USE(tmp105);
    tmp105 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp101}, TNode<IntPtrT>{tmp104});
    TNode<IntPtrT> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp103}, TNode<IntPtrT>{tmp105});
    TNode<Smi> tmp107;
    USE(tmp107);
    tmp107 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp106});
    ca_.Goto(&block19, tmp92, tmp93, tmp94, tmp95, tmp96, tmp107, tmp98, tmp99, tmp100);
  }

  if (block18.is_used()) {
    TNode<Context> tmp108;
    TNode<FixedArray> tmp109;
    TNode<IntPtrT> tmp110;
    TNode<String> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<Smi> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<Object> tmp115;
    TNode<Smi> tmp116;
    ca_.Bind(&block18, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    TNode<IntPtrT> tmp117 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp117);
    TNode<IntPtrT> tmp118 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp118);
    TNode<Smi>tmp119 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp109, tmp118});
    TNode<IntPtrT> tmp120;
    USE(tmp120);
    tmp120 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp119});
    TNode<IntPtrT> tmp121;
    USE(tmp121);
    tmp121 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp122;
    USE(tmp122);
    tmp122 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp114}, TNode<IntPtrT>{tmp121});
    TNode<UintPtrT> tmp123;
    USE(tmp123);
    tmp123 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp122});
    TNode<UintPtrT> tmp124;
    USE(tmp124);
    tmp124 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp120});
    TNode<BoolT> tmp125;
    USE(tmp125);
    tmp125 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp123}, TNode<UintPtrT>{tmp124});
    ca_.Branch(tmp125, &block24, &block25, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp122, tmp115, tmp116, tmp109, tmp117, tmp120, tmp122, tmp122, tmp109, tmp117, tmp120, tmp122, tmp122);
  }

  if (block24.is_used()) {
    TNode<Context> tmp126;
    TNode<FixedArray> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<String> tmp129;
    TNode<JSReceiver> tmp130;
    TNode<Smi> tmp131;
    TNode<IntPtrT> tmp132;
    TNode<Object> tmp133;
    TNode<Smi> tmp134;
    TNode<FixedArray> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<IntPtrT> tmp139;
    TNode<HeapObject> tmp140;
    TNode<IntPtrT> tmp141;
    TNode<IntPtrT> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<IntPtrT> tmp144;
    ca_.Bind(&block24, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144);
    TNode<IntPtrT> tmp145;
    USE(tmp145);
    tmp145 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp146;
    USE(tmp146);
    tmp146 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp144}, TNode<IntPtrT>{tmp145});
    TNode<IntPtrT> tmp147;
    USE(tmp147);
    tmp147 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp141}, TNode<IntPtrT>{tmp146});
    TNode<HeapObject> tmp148;
    USE(tmp148);
    TNode<IntPtrT> tmp149;
    USE(tmp149);
    std::tie(tmp148, tmp149) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp140}, TNode<IntPtrT>{tmp147}).Flatten();
    TNode<Object>tmp150 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp148, tmp149});
    TNode<Smi> tmp151;
    USE(tmp151);
    tmp151 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp126}, TNode<Object>{tmp150});
    TNode<Smi> tmp152;
    USE(tmp152);
    tmp152 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp151}, TNode<Smi>{tmp134});
    ca_.Goto(&block19, tmp126, tmp127, tmp128, tmp129, tmp130, tmp152, tmp132, tmp133, tmp134);
  }

  if (block25.is_used()) {
    TNode<Context> tmp153;
    TNode<FixedArray> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<String> tmp156;
    TNode<JSReceiver> tmp157;
    TNode<Smi> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<Object> tmp160;
    TNode<Smi> tmp161;
    TNode<FixedArray> tmp162;
    TNode<IntPtrT> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<HeapObject> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<IntPtrT> tmp169;
    TNode<IntPtrT> tmp170;
    TNode<IntPtrT> tmp171;
    ca_.Bind(&block25, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<Context> tmp172;
    TNode<FixedArray> tmp173;
    TNode<IntPtrT> tmp174;
    TNode<String> tmp175;
    TNode<JSReceiver> tmp176;
    TNode<Smi> tmp177;
    TNode<IntPtrT> tmp178;
    TNode<Object> tmp179;
    TNode<Smi> tmp180;
    ca_.Bind(&block19, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180);
    ca_.Goto(&block13, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179);
  }

  if (block30.is_used()) {
    TNode<Context> tmp181;
    TNode<FixedArray> tmp182;
    TNode<IntPtrT> tmp183;
    TNode<String> tmp184;
    TNode<JSReceiver> tmp185;
    TNode<Smi> tmp186;
    TNode<IntPtrT> tmp187;
    TNode<Object> tmp188;
    TNode<HeapObject> tmp189;
    ca_.Bind(&block30, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block29.is_used()) {
    TNode<Context> tmp190;
    TNode<FixedArray> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<String> tmp193;
    TNode<JSReceiver> tmp194;
    TNode<Smi> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<Object> tmp197;
    TNode<HeapObject> tmp198;
    TNode<String> tmp199;
    ca_.Bind(&block29, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199);
    TNode<Oddball> tmp200;
    USE(tmp200);
    tmp200 = Undefined_0(state_);
    TNode<Object> tmp201;
    USE(tmp201);
    tmp201 = CodeStubAssembler(state_).Call(TNode<Context>{tmp190}, TNode<JSReceiver>{tmp194}, TNode<Object>{tmp200}, TNode<Object>{tmp199}, TNode<Object>{tmp195}, TNode<Object>{tmp193});
    TNode<String> tmp202;
    USE(tmp202);
    tmp202 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp190}, TNode<Object>{tmp201});
    TNode<IntPtrT> tmp203 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp203);
    TNode<IntPtrT> tmp204 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp204);
    TNode<Smi>tmp205 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp191, tmp204});
    TNode<IntPtrT> tmp206;
    USE(tmp206);
    tmp206 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp205});
    TNode<UintPtrT> tmp207;
    USE(tmp207);
    tmp207 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp196});
    TNode<UintPtrT> tmp208;
    USE(tmp208);
    tmp208 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp206});
    TNode<BoolT> tmp209;
    USE(tmp209);
    tmp209 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp207}, TNode<UintPtrT>{tmp208});
    ca_.Branch(tmp209, &block35, &block36, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp199, tmp201, tmp202, tmp191, tmp203, tmp206, tmp196, tmp196, tmp191, tmp203, tmp206, tmp196, tmp196);
  }

  if (block35.is_used()) {
    TNode<Context> tmp210;
    TNode<FixedArray> tmp211;
    TNode<IntPtrT> tmp212;
    TNode<String> tmp213;
    TNode<JSReceiver> tmp214;
    TNode<Smi> tmp215;
    TNode<IntPtrT> tmp216;
    TNode<Object> tmp217;
    TNode<String> tmp218;
    TNode<Object> tmp219;
    TNode<String> tmp220;
    TNode<FixedArray> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<IntPtrT> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<HeapObject> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<IntPtrT> tmp229;
    TNode<IntPtrT> tmp230;
    ca_.Bind(&block35, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    TNode<IntPtrT> tmp231;
    USE(tmp231);
    tmp231 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp232;
    USE(tmp232);
    tmp232 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp230}, TNode<IntPtrT>{tmp231});
    TNode<IntPtrT> tmp233;
    USE(tmp233);
    tmp233 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp227}, TNode<IntPtrT>{tmp232});
    TNode<HeapObject> tmp234;
    USE(tmp234);
    TNode<IntPtrT> tmp235;
    USE(tmp235);
    std::tie(tmp234, tmp235) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp226}, TNode<IntPtrT>{tmp233}).Flatten();
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp234, tmp235}, tmp220);
    TNode<Smi> tmp236;
    USE(tmp236);
    tmp236 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp218});
    TNode<Smi> tmp237;
    USE(tmp237);
    tmp237 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp215}, TNode<Smi>{tmp236});
    ca_.Goto(&block13, tmp210, tmp211, tmp212, tmp213, tmp214, tmp237, tmp216, tmp217);
  }

  if (block36.is_used()) {
    TNode<Context> tmp238;
    TNode<FixedArray> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<String> tmp241;
    TNode<JSReceiver> tmp242;
    TNode<Smi> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<Object> tmp245;
    TNode<String> tmp246;
    TNode<Object> tmp247;
    TNode<String> tmp248;
    TNode<FixedArray> tmp249;
    TNode<IntPtrT> tmp250;
    TNode<IntPtrT> tmp251;
    TNode<IntPtrT> tmp252;
    TNode<IntPtrT> tmp253;
    TNode<HeapObject> tmp254;
    TNode<IntPtrT> tmp255;
    TNode<IntPtrT> tmp256;
    TNode<IntPtrT> tmp257;
    TNode<IntPtrT> tmp258;
    ca_.Bind(&block36, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block13.is_used()) {
    TNode<Context> tmp259;
    TNode<FixedArray> tmp260;
    TNode<IntPtrT> tmp261;
    TNode<String> tmp262;
    TNode<JSReceiver> tmp263;
    TNode<Smi> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<Object> tmp266;
    ca_.Bind(&block13, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266);
    TNode<IntPtrT> tmp267;
    USE(tmp267);
    tmp267 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp268;
    USE(tmp268);
    tmp268 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp265}, TNode<IntPtrT>{tmp267});
    ca_.Goto(&block4, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp268);
  }

  if (block3.is_used()) {
    TNode<Context> tmp269;
    TNode<FixedArray> tmp270;
    TNode<IntPtrT> tmp271;
    TNode<String> tmp272;
    TNode<JSReceiver> tmp273;
    TNode<Smi> tmp274;
    TNode<IntPtrT> tmp275;
    ca_.Bind(&block3, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275);
    ca_.Goto(&block38, tmp269, tmp270, tmp271, tmp272, tmp273);
  }

    TNode<Context> tmp276;
    TNode<FixedArray> tmp277;
    TNode<IntPtrT> tmp278;
    TNode<String> tmp279;
    TNode<JSReceiver> tmp280;
    ca_.Bind(&block38, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280);
}

void RegExpReplaceCallableWithExplicitCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<FixedArray> p_matchesElements, TNode<IntPtrT> p_matchesLength, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, Object, Context> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, Object, Context, JSArray> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, JSArray, Object, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT, JSArray, Object, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, JSReceiver> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_matchesElements, p_matchesLength, p_replaceFn);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<FixedArray> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<JSReceiver> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<FixedArray> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp9}, TNode<IntPtrT>{tmp7});
    ca_.Branch(tmp10, &block2, &block3, tmp5, tmp6, tmp7, tmp8, tmp9);
  }

  if (block2.is_used()) {
    TNode<Context> tmp11;
    TNode<FixedArray> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<IntPtrT> tmp15;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<IntPtrT> tmp16 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp16);
    TNode<IntPtrT> tmp17 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp17);
    TNode<Smi>tmp18 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp17});
    TNode<IntPtrT> tmp19;
    USE(tmp19);
    tmp19 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp18});
    TNode<UintPtrT> tmp20;
    USE(tmp20);
    tmp20 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp15});
    TNode<UintPtrT> tmp21;
    USE(tmp21);
    tmp21 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp19});
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp20}, TNode<UintPtrT>{tmp21});
    ca_.Branch(tmp22, &block12, &block13, tmp11, tmp12, tmp13, tmp14, tmp15, tmp12, tmp16, tmp19, tmp15, tmp15, tmp12, tmp16, tmp19, tmp15, tmp15);
  }

  if (block12.is_used()) {
    TNode<Context> tmp23;
    TNode<FixedArray> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<FixedArray> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    ca_.Bind(&block12, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp37}, TNode<IntPtrT>{tmp38});
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp34}, TNode<IntPtrT>{tmp39});
    TNode<HeapObject> tmp41;
    USE(tmp41);
    TNode<IntPtrT> tmp42;
    USE(tmp42);
    std::tie(tmp41, tmp42) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp33}, TNode<IntPtrT>{tmp40}).Flatten();
    TNode<Object>tmp43 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp41, tmp42});
    TNode<JSArray> tmp44;
    USE(tmp44);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp44 = Cast_JSArray_1(state_, TNode<Context>{tmp23}, TNode<Object>{tmp43}, &label0);
    ca_.Goto(&block15, tmp23, tmp24, tmp25, tmp26, tmp27, tmp43, tmp23, tmp44);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp23, tmp24, tmp25, tmp26, tmp27, tmp43, tmp23);
    }
  }

  if (block13.is_used()) {
    TNode<Context> tmp45;
    TNode<FixedArray> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<FixedArray> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<HeapObject> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block13, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block16.is_used()) {
    TNode<Context> tmp60;
    TNode<FixedArray> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<Object> tmp65;
    TNode<Context> tmp66;
    ca_.Bind(&block16, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    ca_.Goto(&block5, tmp60, tmp61, tmp62, tmp63, tmp64);
  }

  if (block15.is_used()) {
    TNode<Context> tmp67;
    TNode<FixedArray> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<Object> tmp72;
    TNode<Context> tmp73;
    TNode<JSArray> tmp74;
    ca_.Bind(&block15, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<JSReceiver> tmp75;
    USE(tmp75);
    tmp75 = GetReflectApply_0(state_, TNode<Context>{tmp67});
    TNode<Oddball> tmp76;
    USE(tmp76);
    tmp76 = Undefined_0(state_);
    TNode<Oddball> tmp77;
    USE(tmp77);
    tmp77 = Undefined_0(state_);
    TNode<Object> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).Call(TNode<Context>{tmp67}, TNode<JSReceiver>{tmp75}, TNode<Object>{tmp76}, TNode<Object>{tmp70}, TNode<Object>{tmp77}, TNode<Object>{tmp74});
    TNode<IntPtrT> tmp79 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp79);
    TNode<IntPtrT> tmp80 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp80);
    TNode<Smi>tmp81 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp68, tmp80});
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp81});
    TNode<UintPtrT> tmp83;
    USE(tmp83);
    tmp83 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp71});
    TNode<UintPtrT> tmp84;
    USE(tmp84);
    tmp84 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp82});
    TNode<BoolT> tmp85;
    USE(tmp85);
    tmp85 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp83}, TNode<UintPtrT>{tmp84});
    ca_.Branch(tmp85, &block21, &block22, tmp67, tmp68, tmp69, tmp70, tmp71, tmp74, tmp78, tmp68, tmp79, tmp82, tmp71, tmp71, tmp68, tmp79, tmp82, tmp71, tmp71);
  }

  if (block21.is_used()) {
    TNode<Context> tmp86;
    TNode<FixedArray> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<JSArray> tmp91;
    TNode<Object> tmp92;
    TNode<FixedArray> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<IntPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<HeapObject> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    ca_.Bind(&block21, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    TNode<IntPtrT> tmp103;
    USE(tmp103);
    tmp103 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp104;
    USE(tmp104);
    tmp104 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp102}, TNode<IntPtrT>{tmp103});
    TNode<IntPtrT> tmp105;
    USE(tmp105);
    tmp105 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp99}, TNode<IntPtrT>{tmp104});
    TNode<HeapObject> tmp106;
    USE(tmp106);
    TNode<IntPtrT> tmp107;
    USE(tmp107);
    std::tie(tmp106, tmp107) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp98}, TNode<IntPtrT>{tmp105}).Flatten();
    TNode<String> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp86}, TNode<Object>{tmp92});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp106, tmp107}, tmp108);
    ca_.Goto(&block5, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

  if (block22.is_used()) {
    TNode<Context> tmp109;
    TNode<FixedArray> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<JSArray> tmp114;
    TNode<Object> tmp115;
    TNode<FixedArray> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<IntPtrT> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<HeapObject> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    ca_.Bind(&block22, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp126;
    TNode<FixedArray> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<JSReceiver> tmp129;
    TNode<IntPtrT> tmp130;
    ca_.Bind(&block5, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    TNode<IntPtrT> tmp131;
    USE(tmp131);
    tmp131 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp132;
    USE(tmp132);
    tmp132 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp130}, TNode<IntPtrT>{tmp131});
    ca_.Goto(&block4, tmp126, tmp127, tmp128, tmp129, tmp132);
  }

  if (block3.is_used()) {
    TNode<Context> tmp133;
    TNode<FixedArray> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<JSReceiver> tmp136;
    TNode<IntPtrT> tmp137;
    ca_.Bind(&block3, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137);
    ca_.Goto(&block24, tmp133, tmp134, tmp135, tmp136);
  }

    TNode<Context> tmp138;
    TNode<FixedArray> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<JSReceiver> tmp141;
    ca_.Bind(&block24, &tmp138, &tmp139, &tmp140, &tmp141);
}

TNode<String> RegExpReplaceFastGlobalCallable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<JSReceiver> p_replaceFn) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject, JSArray, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject, JSArray, Number, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject, JSArray, Smi, IntPtrT, FixedArray, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject, JSArray, Smi, IntPtrT, FixedArray, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, IntPtrT, Smi, HeapObject, JSArray, Smi, IntPtrT, FixedArray, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, JSReceiver, String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string, p_replaceFn);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    TNode<JSReceiver> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp1}, TNode<Smi>{tmp4});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 16);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<RegExpMatchInfo> tmp7;
    USE(tmp7);
    tmp7 = GetRegExpLastMatchInfo_0(state_, TNode<Context>{tmp0});
    TNode<Map> tmp8;
    USE(tmp8);
    tmp8 = GetFastPackedElementsJSArrayMap_0(state_, TNode<Context>{tmp0});
    TNode<JSArray> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).AllocateJSArray(PACKED_ELEMENTS, TNode<Map>{tmp8}, TNode<IntPtrT>{tmp5}, TNode<Smi>{tmp6});
    TNode<HeapObject> tmp10;
    tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpExecMultiple, tmp0, tmp1, tmp2, tmp7, tmp9)); 
    USE(tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp1}, TNode<Smi>{tmp11});
    TNode<Oddball> tmp12;
    USE(tmp12);
    tmp12 = Null_0(state_);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp10}, TNode<HeapObject>{tmp12});
    ca_.Branch(tmp13, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp5, tmp6, tmp10);
  }

  if (block2.is_used()) {
    TNode<Context> tmp14;
    TNode<JSRegExp> tmp15;
    TNode<String> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<HeapObject> tmp20;
    ca_.Bind(&block2, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block1, tmp14, tmp15, tmp16, tmp17, tmp16);
  }

  if (block3.is_used()) {
    TNode<Context> tmp21;
    TNode<JSRegExp> tmp22;
    TNode<String> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Smi> tmp26;
    TNode<HeapObject> tmp27;
    ca_.Bind(&block3, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<JSArray> tmp28;
    USE(tmp28);
    tmp28 = UnsafeCast_JSArray_0(state_, TNode<Context>{tmp21}, TNode<Object>{tmp27});
    TNode<IntPtrT> tmp29 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp29);
    TNode<Number>tmp30 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp28, tmp29});
    TNode<Smi> tmp31;
    USE(tmp31);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp31 = Cast_Smi_0(state_, TNode<Object>{tmp30}, &label0);
    ca_.Goto(&block6, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp30, tmp31);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp30);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp32;
    TNode<JSRegExp> tmp33;
    TNode<String> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<Smi> tmp37;
    TNode<HeapObject> tmp38;
    TNode<JSArray> tmp39;
    TNode<Number> tmp40;
    ca_.Bind(&block7, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block6.is_used()) {
    TNode<Context> tmp41;
    TNode<JSRegExp> tmp42;
    TNode<String> tmp43;
    TNode<JSReceiver> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<Smi> tmp46;
    TNode<HeapObject> tmp47;
    TNode<JSArray> tmp48;
    TNode<Number> tmp49;
    TNode<Smi> tmp50;
    ca_.Bind(&block6, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    tmp51 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp50});
    TNode<IntPtrT> tmp52 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp52);
    TNode<FixedArrayBase>tmp53 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp48, tmp52});
    TNode<FixedArray> tmp54;
    USE(tmp54);
    tmp54 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp41}, TNode<Object>{tmp53});
    TNode<RegExpMatchInfo> tmp55;
    USE(tmp55);
    tmp55 = GetRegExpLastMatchInfo_0(state_, TNode<Context>{tmp41});
    TNode<Smi> tmp56;
    USE(tmp56);
    tmp56 = Method_RegExpMatchInfo_NumberOfCaptures_0(state_, TNode<Context>{tmp41}, TNode<RegExpMatchInfo>{tmp55});
    TNode<Smi> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp56}, TNode<Smi>{tmp57});
    ca_.Branch(tmp58, &block8, &block9, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp50, tmp51, tmp54, tmp56);
  }

  if (block8.is_used()) {
    TNode<Context> tmp59;
    TNode<JSRegExp> tmp60;
    TNode<String> tmp61;
    TNode<JSReceiver> tmp62;
    TNode<IntPtrT> tmp63;
    TNode<Smi> tmp64;
    TNode<HeapObject> tmp65;
    TNode<JSArray> tmp66;
    TNode<Smi> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<FixedArray> tmp69;
    TNode<Smi> tmp70;
    ca_.Bind(&block8, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    RegExpReplaceCallableNoExplicitCaptures_0(state_, TNode<Context>{tmp59}, TNode<FixedArray>{tmp69}, TNode<IntPtrT>{tmp68}, TNode<String>{tmp61}, TNode<JSReceiver>{tmp62});
    ca_.Goto(&block10, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70);
  }

  if (block9.is_used()) {
    TNode<Context> tmp71;
    TNode<JSRegExp> tmp72;
    TNode<String> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<Smi> tmp76;
    TNode<HeapObject> tmp77;
    TNode<JSArray> tmp78;
    TNode<Smi> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<FixedArray> tmp81;
    TNode<Smi> tmp82;
    ca_.Bind(&block9, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
    RegExpReplaceCallableWithExplicitCaptures_0(state_, TNode<Context>{tmp71}, TNode<FixedArray>{tmp81}, TNode<IntPtrT>{tmp80}, TNode<JSReceiver>{tmp74});
    ca_.Goto(&block10, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82);
  }

  if (block10.is_used()) {
    TNode<Context> tmp83;
    TNode<JSRegExp> tmp84;
    TNode<String> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<Smi> tmp88;
    TNode<HeapObject> tmp89;
    TNode<JSArray> tmp90;
    TNode<Smi> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<FixedArray> tmp93;
    TNode<Smi> tmp94;
    ca_.Bind(&block10, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    TNode<String> tmp95;
    tmp95 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringBuilderConcat, tmp83, tmp90, tmp91, tmp85)); 
    USE(tmp95);
    ca_.Goto(&block1, tmp83, tmp84, tmp85, tmp86, tmp95);
  }

  if (block1.is_used()) {
    TNode<Context> tmp96;
    TNode<JSRegExp> tmp97;
    TNode<String> tmp98;
    TNode<JSReceiver> tmp99;
    TNode<String> tmp100;
    ca_.Bind(&block1, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    ca_.Goto(&block11, tmp96, tmp97, tmp98, tmp99, tmp100);
  }

    TNode<Context> tmp101;
    TNode<JSRegExp> tmp102;
    TNode<String> tmp103;
    TNode<JSReceiver> tmp104;
    TNode<String> tmp105;
    ca_.Bind(&block11, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105);
  return TNode<String>{tmp105};
}

TNode<String> RegExpReplaceFastString_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<String> p_replaceString) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, JSRegExp, String, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, JSRegExp, String, Context, RegExpMatchInfo> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi, JSRegExp, JSRegExp, Context> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi, JSRegExp, JSRegExp, Context, JSRegExp> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi, JSRegExp> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT, RegExpMatchInfo, Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String, Smi, BoolT, Smi, JSRegExp, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, String, String> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string, p_replaceString);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    TNode<String> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = kEmptyString_0(state_);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp3});
    TNode<JSRegExp> tmp8;
    USE(tmp8);
    tmp8 = UnsafeCast_FastJSRegExp_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = RegExpBuiltinsAssembler(state_).FastFlagGetterGlobal(TNode<JSRegExp>{tmp8});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8, tmp9);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<JSRegExp> tmp11;
    TNode<String> tmp12;
    TNode<String> tmp13;
    TNode<String> tmp14;
    TNode<Smi> tmp15;
    TNode<BoolT> tmp16;
    TNode<Smi> tmp17;
    TNode<JSRegExp> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = RegExpBuiltinsAssembler(state_).FastFlagGetterUnicode(TNode<JSRegExp>{tmp18});
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp18}, TNode<Smi>{tmp21});
    ca_.Goto(&block3, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp20, tmp17, tmp18, tmp19);
  }

  if (block3.is_used()) {
    TNode<Context> tmp22;
    TNode<JSRegExp> tmp23;
    TNode<String> tmp24;
    TNode<String> tmp25;
    TNode<String> tmp26;
    TNode<Smi> tmp27;
    TNode<BoolT> tmp28;
    TNode<Smi> tmp29;
    TNode<JSRegExp> tmp30;
    TNode<BoolT> tmp31;
    ca_.Bind(&block3, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    ca_.Goto(&block6, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31);
  }

  if (block6.is_used()) {
    TNode<Context> tmp32;
    TNode<JSRegExp> tmp33;
    TNode<String> tmp34;
    TNode<String> tmp35;
    TNode<String> tmp36;
    TNode<Smi> tmp37;
    TNode<BoolT> tmp38;
    TNode<Smi> tmp39;
    TNode<JSRegExp> tmp40;
    TNode<BoolT> tmp41;
    ca_.Bind(&block6, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp42, &block4, &block5, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41);
  }

  if (block4.is_used()) {
    TNode<Context> tmp43;
    TNode<JSRegExp> tmp44;
    TNode<String> tmp45;
    TNode<String> tmp46;
    TNode<String> tmp47;
    TNode<Smi> tmp48;
    TNode<BoolT> tmp49;
    TNode<Smi> tmp50;
    TNode<JSRegExp> tmp51;
    TNode<BoolT> tmp52;
    ca_.Bind(&block4, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<RegExpMatchInfo> tmp53;
    USE(tmp53);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp53 = RegExpPrototypeExecBodyWithoutResultFast_0(state_, TNode<Context>{tmp43}, TNode<JSRegExp>{tmp44}, TNode<String>{tmp45}, &label0);
    ca_.Goto(&block9, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp44, tmp45, tmp43, tmp53);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp44, tmp45, tmp43);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp54;
    TNode<JSRegExp> tmp55;
    TNode<String> tmp56;
    TNode<String> tmp57;
    TNode<String> tmp58;
    TNode<Smi> tmp59;
    TNode<BoolT> tmp60;
    TNode<Smi> tmp61;
    TNode<JSRegExp> tmp62;
    TNode<BoolT> tmp63;
    TNode<JSRegExp> tmp64;
    TNode<String> tmp65;
    TNode<Context> tmp66;
    ca_.Bind(&block10, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    ca_.Goto(&block5, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63);
  }

  if (block9.is_used()) {
    TNode<Context> tmp67;
    TNode<JSRegExp> tmp68;
    TNode<String> tmp69;
    TNode<String> tmp70;
    TNode<String> tmp71;
    TNode<Smi> tmp72;
    TNode<BoolT> tmp73;
    TNode<Smi> tmp74;
    TNode<JSRegExp> tmp75;
    TNode<BoolT> tmp76;
    TNode<JSRegExp> tmp77;
    TNode<String> tmp78;
    TNode<Context> tmp79;
    TNode<RegExpMatchInfo> tmp80;
    ca_.Bind(&block9, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<Smi> tmp81;
    USE(tmp81);
    tmp81 = Method_RegExpMatchInfo_GetStartOfCapture_0(state_, TNode<Context>{tmp67}, TNode<RegExpMatchInfo>{tmp80}, 0);
    TNode<Smi> tmp82;
    USE(tmp82);
    tmp82 = Method_RegExpMatchInfo_GetEndOfCapture_0(state_, TNode<Context>{tmp67}, TNode<RegExpMatchInfo>{tmp80}, 0);
    TNode<String> tmp83;
    tmp83 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kSubString, tmp67, tmp69, tmp72, tmp81));
    USE(tmp83);
    TNode<String> tmp84;
    USE(tmp84);
    tmp84 = StringAdd_0(state_, TNode<Context>{tmp67}, TNode<String>{tmp71}, TNode<String>{tmp83});
    TNode<Smi> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp74}, TNode<Smi>{tmp85});
    ca_.Branch(tmp86, &block11, &block12, tmp67, tmp68, tmp69, tmp70, tmp84, tmp82, tmp73, tmp74, tmp75, tmp76, tmp80, tmp81, tmp82);
  }

  if (block11.is_used()) {
    TNode<Context> tmp87;
    TNode<JSRegExp> tmp88;
    TNode<String> tmp89;
    TNode<String> tmp90;
    TNode<String> tmp91;
    TNode<Smi> tmp92;
    TNode<BoolT> tmp93;
    TNode<Smi> tmp94;
    TNode<JSRegExp> tmp95;
    TNode<BoolT> tmp96;
    TNode<RegExpMatchInfo> tmp97;
    TNode<Smi> tmp98;
    TNode<Smi> tmp99;
    ca_.Bind(&block11, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99);
    TNode<String> tmp100;
    USE(tmp100);
    tmp100 = StringAdd_0(state_, TNode<Context>{tmp87}, TNode<String>{tmp91}, TNode<String>{tmp90});
    ca_.Goto(&block12, tmp87, tmp88, tmp89, tmp90, tmp100, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99);
  }

  if (block12.is_used()) {
    TNode<Context> tmp101;
    TNode<JSRegExp> tmp102;
    TNode<String> tmp103;
    TNode<String> tmp104;
    TNode<String> tmp105;
    TNode<Smi> tmp106;
    TNode<BoolT> tmp107;
    TNode<Smi> tmp108;
    TNode<JSRegExp> tmp109;
    TNode<BoolT> tmp110;
    TNode<RegExpMatchInfo> tmp111;
    TNode<Smi> tmp112;
    TNode<Smi> tmp113;
    ca_.Bind(&block12, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    TNode<BoolT> tmp114;
    USE(tmp114);
    tmp114 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp110});
    ca_.Branch(tmp114, &block13, &block14, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113);
  }

  if (block13.is_used()) {
    TNode<Context> tmp115;
    TNode<JSRegExp> tmp116;
    TNode<String> tmp117;
    TNode<String> tmp118;
    TNode<String> tmp119;
    TNode<Smi> tmp120;
    TNode<BoolT> tmp121;
    TNode<Smi> tmp122;
    TNode<JSRegExp> tmp123;
    TNode<BoolT> tmp124;
    TNode<RegExpMatchInfo> tmp125;
    TNode<Smi> tmp126;
    TNode<Smi> tmp127;
    ca_.Bind(&block13, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    ca_.Goto(&block5, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124);
  }

  if (block14.is_used()) {
    TNode<Context> tmp128;
    TNode<JSRegExp> tmp129;
    TNode<String> tmp130;
    TNode<String> tmp131;
    TNode<String> tmp132;
    TNode<Smi> tmp133;
    TNode<BoolT> tmp134;
    TNode<Smi> tmp135;
    TNode<JSRegExp> tmp136;
    TNode<BoolT> tmp137;
    TNode<RegExpMatchInfo> tmp138;
    TNode<Smi> tmp139;
    TNode<Smi> tmp140;
    ca_.Bind(&block14, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    TNode<BoolT> tmp141;
    USE(tmp141);
    tmp141 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp140}, TNode<Smi>{tmp139});
    ca_.Branch(tmp141, &block15, &block16, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140);
  }

  if (block15.is_used()) {
    TNode<Context> tmp142;
    TNode<JSRegExp> tmp143;
    TNode<String> tmp144;
    TNode<String> tmp145;
    TNode<String> tmp146;
    TNode<Smi> tmp147;
    TNode<BoolT> tmp148;
    TNode<Smi> tmp149;
    TNode<JSRegExp> tmp150;
    TNode<BoolT> tmp151;
    TNode<RegExpMatchInfo> tmp152;
    TNode<Smi> tmp153;
    TNode<Smi> tmp154;
    ca_.Bind(&block15, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154);
    TNode<JSRegExp> tmp155;
    USE(tmp155);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp155 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp142}, TNode<HeapObject>{tmp143}, &label0);
    ca_.Goto(&block19, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp143, tmp143, tmp142, tmp155);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block20, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp143, tmp143, tmp142);
    }
  }

  if (block20.is_used()) {
    TNode<Context> tmp156;
    TNode<JSRegExp> tmp157;
    TNode<String> tmp158;
    TNode<String> tmp159;
    TNode<String> tmp160;
    TNode<Smi> tmp161;
    TNode<BoolT> tmp162;
    TNode<Smi> tmp163;
    TNode<JSRegExp> tmp164;
    TNode<BoolT> tmp165;
    TNode<RegExpMatchInfo> tmp166;
    TNode<Smi> tmp167;
    TNode<Smi> tmp168;
    TNode<JSRegExp> tmp169;
    TNode<JSRegExp> tmp170;
    TNode<Context> tmp171;
    ca_.Bind(&block20, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171);
    TNode<Object> tmp172;
    USE(tmp172);
    tmp172 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp156}, TNode<Object>{tmp157});
    TNode<Number> tmp173;
    USE(tmp173);
    tmp173 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp156}, TNode<Object>{tmp172});
    TNode<Smi> tmp174;
    USE(tmp174);
    tmp174 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexSlow(TNode<String>{tmp158}, TNode<Number>{tmp173}, TNode<BoolT>{tmp162});
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp156}, TNode<Object>{tmp157}, TNode<Object>{tmp174});
    ca_.Goto(&block17, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169);
  }

  if (block19.is_used()) {
    TNode<Context> tmp175;
    TNode<JSRegExp> tmp176;
    TNode<String> tmp177;
    TNode<String> tmp178;
    TNode<String> tmp179;
    TNode<Smi> tmp180;
    TNode<BoolT> tmp181;
    TNode<Smi> tmp182;
    TNode<JSRegExp> tmp183;
    TNode<BoolT> tmp184;
    TNode<RegExpMatchInfo> tmp185;
    TNode<Smi> tmp186;
    TNode<Smi> tmp187;
    TNode<JSRegExp> tmp188;
    TNode<JSRegExp> tmp189;
    TNode<Context> tmp190;
    TNode<JSRegExp> tmp191;
    ca_.Bind(&block19, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191);
    TNode<Smi> tmp192;
    USE(tmp192);
    tmp192 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp191});
    TNode<Smi> tmp193;
    USE(tmp193);
    tmp193 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexFast(TNode<String>{tmp177}, TNode<Smi>{tmp192}, TNode<BoolT>{tmp181});
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp191}, TNode<Smi>{tmp193});
    ca_.Goto(&block17, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188);
  }

  if (block17.is_used()) {
    TNode<Context> tmp194;
    TNode<JSRegExp> tmp195;
    TNode<String> tmp196;
    TNode<String> tmp197;
    TNode<String> tmp198;
    TNode<Smi> tmp199;
    TNode<BoolT> tmp200;
    TNode<Smi> tmp201;
    TNode<JSRegExp> tmp202;
    TNode<BoolT> tmp203;
    TNode<RegExpMatchInfo> tmp204;
    TNode<Smi> tmp205;
    TNode<Smi> tmp206;
    TNode<JSRegExp> tmp207;
    ca_.Bind(&block17, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207);
    ca_.Goto(&block16, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206);
  }

  if (block16.is_used()) {
    TNode<Context> tmp208;
    TNode<JSRegExp> tmp209;
    TNode<String> tmp210;
    TNode<String> tmp211;
    TNode<String> tmp212;
    TNode<Smi> tmp213;
    TNode<BoolT> tmp214;
    TNode<Smi> tmp215;
    TNode<JSRegExp> tmp216;
    TNode<BoolT> tmp217;
    TNode<RegExpMatchInfo> tmp218;
    TNode<Smi> tmp219;
    TNode<Smi> tmp220;
    ca_.Bind(&block16, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220);
    ca_.Goto(&block6, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217);
  }

  if (block5.is_used()) {
    TNode<Context> tmp221;
    TNode<JSRegExp> tmp222;
    TNode<String> tmp223;
    TNode<String> tmp224;
    TNode<String> tmp225;
    TNode<Smi> tmp226;
    TNode<BoolT> tmp227;
    TNode<Smi> tmp228;
    TNode<JSRegExp> tmp229;
    TNode<BoolT> tmp230;
    ca_.Bind(&block5, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    TNode<Smi> tmp231;
    USE(tmp231);
    tmp231 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp223});
    TNode<String> tmp232;
    tmp232 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kSubString, tmp221, tmp223, tmp226, tmp231));
    USE(tmp232);
    TNode<String> tmp233;
    USE(tmp233);
    tmp233 = StringAdd_0(state_, TNode<Context>{tmp221}, TNode<String>{tmp225}, TNode<String>{tmp232});
    ca_.Goto(&block21, tmp221, tmp222, tmp223, tmp224, tmp233);
  }

    TNode<Context> tmp234;
    TNode<JSRegExp> tmp235;
    TNode<String> tmp236;
    TNode<String> tmp237;
    TNode<String> tmp238;
    ca_.Bind(&block21, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238);
  return TNode<String>{tmp238};
}

TF_BUILTIN(RegExpReplace, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSRegExp> parameter1 = UncheckedCast<JSRegExp>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<String> parameter2 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, Context, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, JSReceiver> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, JSReceiver> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, JSReceiver, String> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, JSRegExp, String, JSRegExp, Context> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, JSRegExp, String, JSRegExp, Context, JSRegExp> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, JSRegExp, String, JSRegExp> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, JSRegExp, String, JSRegExp> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object, Object, Object, JSRegExp, String> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_Callable_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block7, tmp0, tmp1, tmp2, tmp3, tmp3, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp0, tmp1, tmp2, tmp3, tmp3, tmp3, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<JSRegExp> tmp6;
    TNode<String> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<FastJSRegExp>(regexp)' failed", "src/builtins/regexp-replace.tq", 182);
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<JSRegExp> tmp10;
    TNode<String> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11, &tmp12);
  }

  if (block8.is_used()) {
    TNode<Context> tmp13;
    TNode<JSRegExp> tmp14;
    TNode<String> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Context> tmp19;
    ca_.Bind(&block8, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<String> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp13}, TNode<Object>{tmp16});
    TNode<JSRegExp> tmp21;
    USE(tmp21);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp21 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp13}, TNode<HeapObject>{tmp14}, &label0);
    ca_.Goto(&block15, tmp13, tmp14, tmp15, tmp16, tmp17, ca_.UncheckedCast<Object>(tmp17), tmp14, tmp20, tmp14, tmp13, tmp21);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp13, tmp14, tmp15, tmp16, tmp17, ca_.UncheckedCast<Object>(tmp17), tmp14, tmp20, tmp14, tmp13);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<JSRegExp> tmp23;
    TNode<String> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Context> tmp28;
    TNode<JSReceiver> tmp29;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = RegExpBuiltinsAssembler(state_).FastFlagGetterGlobal(TNode<JSRegExp>{tmp23});
    ca_.Branch(tmp30, &block9, &block10, tmp22, tmp23, tmp24, tmp25, tmp26, tmp29);
  }

  if (block9.is_used()) {
    TNode<Context> tmp31;
    TNode<JSRegExp> tmp32;
    TNode<String> tmp33;
    TNode<Object> tmp34;
    TNode<Object> tmp35;
    TNode<JSReceiver> tmp36;
    ca_.Bind(&block9, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<String> tmp37;
    USE(tmp37);
    tmp37 = RegExpReplaceFastGlobalCallable_0(state_, TNode<Context>{tmp31}, TNode<JSRegExp>{tmp32}, TNode<String>{tmp33}, TNode<JSReceiver>{tmp36});
    ca_.Goto(&block11, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37);
  }

  if (block10.is_used()) {
    TNode<Context> tmp38;
    TNode<JSRegExp> tmp39;
    TNode<String> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<JSReceiver> tmp43;
    ca_.Bind(&block10, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<String> tmp44;
    tmp44 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringReplaceNonGlobalRegExpWithFunction, tmp38, tmp40, tmp39, tmp43)); 
    USE(tmp44);
    ca_.Goto(&block11, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44);
  }

  if (block11.is_used()) {
    TNode<Context> tmp45;
    TNode<JSRegExp> tmp46;
    TNode<String> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<String> tmp51;
    ca_.Bind(&block11, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    CodeStubAssembler(state_).Return(tmp51);
  }

  if (block16.is_used()) {
    TNode<Context> tmp52;
    TNode<JSRegExp> tmp53;
    TNode<String> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<JSRegExp> tmp58;
    TNode<String> tmp59;
    TNode<JSRegExp> tmp60;
    TNode<Context> tmp61;
    ca_.Bind(&block16, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block14, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59);
  }

  if (block15.is_used()) {
    TNode<Context> tmp62;
    TNode<JSRegExp> tmp63;
    TNode<String> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<JSRegExp> tmp68;
    TNode<String> tmp69;
    TNode<JSRegExp> tmp70;
    TNode<Context> tmp71;
    TNode<JSRegExp> tmp72;
    ca_.Bind(&block15, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<String> tmp73;
    USE(tmp73);
    tmp73 = CodeStubAssembler(state_).SingleCharacterStringConstant("$");
    TNode<Smi> tmp74;
    USE(tmp74);
    tmp74 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp75;
    tmp75 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringIndexOf, tmp62, tmp69, tmp73, tmp74));
    USE(tmp75);
    TNode<Smi> tmp76;
    USE(tmp76);
    tmp76 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    TNode<BoolT> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp75}, TNode<Smi>{tmp76});
    ca_.Branch(tmp77, &block17, &block18, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp72);
  }

  if (block17.is_used()) {
    TNode<Context> tmp78;
    TNode<JSRegExp> tmp79;
    TNode<String> tmp80;
    TNode<Object> tmp81;
    TNode<Object> tmp82;
    TNode<Object> tmp83;
    TNode<JSRegExp> tmp84;
    TNode<String> tmp85;
    TNode<JSRegExp> tmp86;
    ca_.Bind(&block17, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    ca_.Goto(&block14, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block18.is_used()) {
    TNode<Context> tmp87;
    TNode<JSRegExp> tmp88;
    TNode<String> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    TNode<JSRegExp> tmp93;
    TNode<String> tmp94;
    TNode<JSRegExp> tmp95;
    ca_.Bind(&block18, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<String> tmp96;
    USE(tmp96);
    tmp96 = RegExpReplaceFastString_0(state_, TNode<Context>{tmp87}, TNode<JSRegExp>{tmp95}, TNode<String>{tmp89}, TNode<String>{tmp94});
    CodeStubAssembler(state_).Return(tmp96);
  }

  if (block14.is_used()) {
    TNode<Context> tmp97;
    TNode<JSRegExp> tmp98;
    TNode<String> tmp99;
    TNode<Object> tmp100;
    TNode<Object> tmp101;
    TNode<Object> tmp102;
    TNode<JSRegExp> tmp103;
    TNode<String> tmp104;
    ca_.Bind(&block14, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<String> tmp105;
    tmp105 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpReplaceRT, tmp97, tmp103, tmp99, tmp104)); 
    USE(tmp105);
    CodeStubAssembler(state_).Return(tmp105);
  }
}

TF_BUILTIN(RegExpPrototypeReplace, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, JSReceiver, String, JSReceiver, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, JSReceiver, String, JSReceiver, NativeContext, JSRegExp> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp7});
    TNode<JSReceiver> tmp9;
    USE(tmp9);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp9 = Cast_JSReceiver_1(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp8, tmp4, tmp3, tmp9);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp8, tmp4, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<NativeContext> tmp18;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp13}, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@replace");
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp19;
    TNode<RawPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<NativeContext> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<NativeContext> tmp27;
    TNode<JSReceiver> tmp28;
    ca_.Bind(&block3, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<String> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp22}, TNode<Object>{tmp24});
    TNode<JSRegExp> tmp30;
    USE(tmp30);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp30 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp22}, TNode<HeapObject>{tmp28}, &label0);
    ca_.Goto(&block7, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp28, tmp29, tmp28, tmp22, tmp30);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp28, tmp29, tmp28, tmp22);
    }
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<String> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<NativeContext> tmp41;
    ca_.Bind(&block8, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Smi> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kRegExpReplaceCalledOnSlowRegExp);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp34, tmp42);
    TNode<String> tmp44;
    tmp44 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpReplaceRT, tmp34, tmp38, tmp39, tmp37)); 
    USE(tmp44);
    arguments.PopAndReturn(tmp44);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp45;
    TNode<RawPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<NativeContext> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<String> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<NativeContext> tmp55;
    TNode<JSRegExp> tmp56;
    ca_.Bind(&block7, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<String> tmp57;
    tmp57 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kRegExpReplace, tmp48, tmp56, tmp53, tmp51));
    USE(tmp57);
    arguments.PopAndReturn(tmp57);
  }
}

TNode<BoolT> Is_FastJSRegExp_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, JSRegExp, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, JSRegExp, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<JSRegExp> tmp4;
    TNode<JSRegExp> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<JSRegExp> tmp9;
    TNode<JSRegExp> tmp10;
    TNode<Context> tmp11;
    TNode<JSRegExp> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<JSRegExp> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<JSRegExp> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

}  // namespace internal
}  // namespace v8

