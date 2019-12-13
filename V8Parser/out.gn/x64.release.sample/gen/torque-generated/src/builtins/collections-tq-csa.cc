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

TorqueStructKeyValuePair LoadKeyValuePairNoSideEffects_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_MayHaveSideEffects) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase, FixedArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArray, Object, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedArrayBase, FixedDoubleArray> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, Smi, FixedArrayBase, FixedDoubleArray, Object, Object> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSReceiver> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<JSReceiver> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = Cast_JSReceiver_1(state_, TNode<Context>{tmp3}, TNode<Object>{ca_.UncheckedCast<Object>(tmp5)}, &label0);
    ca_.Goto(&block33, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block34, tmp3, tmp4, tmp5, ca_.UncheckedCast<Object>(tmp5), tmp3);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Context> tmp13;
    TNode<JSArray> tmp14;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp14});
    TNode<IntPtrT> tmp16 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp16);
    TNode<FixedArrayBase>tmp17 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp14, tmp16});
    TNode<FixedArray> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp18 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp17}, &label0);
    ca_.Goto(&block9, tmp9, tmp10, tmp11, tmp14, tmp15, tmp17, tmp17, tmp18);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp9, tmp10, tmp11, tmp14, tmp15, tmp17, tmp17);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    TNode<Smi> tmp23;
    TNode<FixedArrayBase> tmp24;
    TNode<FixedArrayBase> tmp25;
    ca_.Bind(&block10, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<FixedDoubleArray> tmp26;
    USE(tmp26);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp26 = Cast_FixedDoubleArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<FixedArrayBase>(tmp24)}, &label0);
    ca_.Goto(&block21, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, ca_.UncheckedCast<FixedArrayBase>(tmp24), tmp26);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block22, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, ca_.UncheckedCast<FixedArrayBase>(tmp24));
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<JSArray> tmp30;
    TNode<Smi> tmp31;
    TNode<FixedArrayBase> tmp32;
    TNode<FixedArrayBase> tmp33;
    TNode<FixedArray> tmp34;
    ca_.Bind(&block9, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp31}, TNode<Smi>{tmp35});
    ca_.Branch(tmp36, &block11, &block12, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp34);
  }

  if (block11.is_used()) {
    TNode<Context> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<JSArray> tmp40;
    TNode<Smi> tmp41;
    TNode<FixedArrayBase> tmp42;
    TNode<FixedArray> tmp43;
    ca_.Bind(&block11, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp45;
    USE(tmp45);
    tmp45 = LoadElementOrUndefined_0(state_, TNode<Context>{tmp37}, TNode<FixedArray>{tmp43}, TNode<Smi>{tmp44});
    ca_.Goto(&block13, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp45);
  }

  if (block12.is_used()) {
    TNode<Context> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<JSArray> tmp49;
    TNode<Smi> tmp50;
    TNode<FixedArrayBase> tmp51;
    TNode<FixedArray> tmp52;
    ca_.Bind(&block12, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<Oddball> tmp53;
    USE(tmp53);
    tmp53 = Undefined_0(state_);
    ca_.Goto(&block13, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53);
  }

  if (block13.is_used()) {
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<JSArray> tmp57;
    TNode<Smi> tmp58;
    TNode<FixedArrayBase> tmp59;
    TNode<FixedArray> tmp60;
    TNode<Object> tmp61;
    ca_.Bind(&block13, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<Smi> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp63;
    USE(tmp63);
    tmp63 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp58}, TNode<Smi>{tmp62});
    ca_.Branch(tmp63, &block15, &block16, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61);
  }

  if (block15.is_used()) {
    TNode<Context> tmp64;
    TNode<Object> tmp65;
    TNode<Object> tmp66;
    TNode<JSArray> tmp67;
    TNode<Smi> tmp68;
    TNode<FixedArrayBase> tmp69;
    TNode<FixedArray> tmp70;
    TNode<Object> tmp71;
    ca_.Bind(&block15, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    TNode<Smi> tmp72;
    USE(tmp72);
    tmp72 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp73;
    USE(tmp73);
    tmp73 = LoadElementOrUndefined_0(state_, TNode<Context>{tmp64}, TNode<FixedArray>{tmp70}, TNode<Smi>{tmp72});
    ca_.Goto(&block17, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp73);
  }

  if (block16.is_used()) {
    TNode<Context> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<JSArray> tmp77;
    TNode<Smi> tmp78;
    TNode<FixedArrayBase> tmp79;
    TNode<FixedArray> tmp80;
    TNode<Object> tmp81;
    ca_.Bind(&block16, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<Oddball> tmp82;
    USE(tmp82);
    tmp82 = Undefined_0(state_);
    ca_.Goto(&block17, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82);
  }

  if (block17.is_used()) {
    TNode<Context> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<JSArray> tmp86;
    TNode<Smi> tmp87;
    TNode<FixedArrayBase> tmp88;
    TNode<FixedArray> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    ca_.Bind(&block17, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    ca_.Goto(&block2, tmp83, tmp84, tmp90, tmp91);
  }

  if (block22.is_used()) {
    TNode<Context> tmp92;
    TNode<Object> tmp93;
    TNode<Object> tmp94;
    TNode<JSArray> tmp95;
    TNode<Smi> tmp96;
    TNode<FixedArrayBase> tmp97;
    TNode<FixedArrayBase> tmp98;
    ca_.Bind(&block22, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block21.is_used()) {
    TNode<Context> tmp99;
    TNode<Object> tmp100;
    TNode<Object> tmp101;
    TNode<JSArray> tmp102;
    TNode<Smi> tmp103;
    TNode<FixedArrayBase> tmp104;
    TNode<FixedArrayBase> tmp105;
    TNode<FixedDoubleArray> tmp106;
    ca_.Bind(&block21, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    TNode<Smi> tmp107;
    USE(tmp107);
    tmp107 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp103}, TNode<Smi>{tmp107});
    ca_.Branch(tmp108, &block23, &block24, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp106);
  }

  if (block23.is_used()) {
    TNode<Context> tmp109;
    TNode<Object> tmp110;
    TNode<Object> tmp111;
    TNode<JSArray> tmp112;
    TNode<Smi> tmp113;
    TNode<FixedArrayBase> tmp114;
    TNode<FixedDoubleArray> tmp115;
    ca_.Bind(&block23, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115);
    TNode<Smi> tmp116;
    USE(tmp116);
    tmp116 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp117;
    USE(tmp117);
    tmp117 = LoadElementOrUndefined_1(state_, TNode<FixedDoubleArray>{tmp115}, TNode<Smi>{tmp116});
    ca_.Goto(&block25, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp117);
  }

  if (block24.is_used()) {
    TNode<Context> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<JSArray> tmp121;
    TNode<Smi> tmp122;
    TNode<FixedArrayBase> tmp123;
    TNode<FixedDoubleArray> tmp124;
    ca_.Bind(&block24, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124);
    TNode<Oddball> tmp125;
    USE(tmp125);
    tmp125 = Undefined_0(state_);
    ca_.Goto(&block25, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125);
  }

  if (block25.is_used()) {
    TNode<Context> tmp126;
    TNode<Object> tmp127;
    TNode<Object> tmp128;
    TNode<JSArray> tmp129;
    TNode<Smi> tmp130;
    TNode<FixedArrayBase> tmp131;
    TNode<FixedDoubleArray> tmp132;
    TNode<Object> tmp133;
    ca_.Bind(&block25, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133);
    TNode<Smi> tmp134;
    USE(tmp134);
    tmp134 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp135;
    USE(tmp135);
    tmp135 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp130}, TNode<Smi>{tmp134});
    ca_.Branch(tmp135, &block27, &block28, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133);
  }

  if (block27.is_used()) {
    TNode<Context> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    TNode<JSArray> tmp139;
    TNode<Smi> tmp140;
    TNode<FixedArrayBase> tmp141;
    TNode<FixedDoubleArray> tmp142;
    TNode<Object> tmp143;
    ca_.Bind(&block27, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
    TNode<Smi> tmp144;
    USE(tmp144);
    tmp144 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp145;
    USE(tmp145);
    tmp145 = LoadElementOrUndefined_1(state_, TNode<FixedDoubleArray>{tmp142}, TNode<Smi>{tmp144});
    ca_.Goto(&block29, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp145);
  }

  if (block28.is_used()) {
    TNode<Context> tmp146;
    TNode<Object> tmp147;
    TNode<Object> tmp148;
    TNode<JSArray> tmp149;
    TNode<Smi> tmp150;
    TNode<FixedArrayBase> tmp151;
    TNode<FixedDoubleArray> tmp152;
    TNode<Object> tmp153;
    ca_.Bind(&block28, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153);
    TNode<Oddball> tmp154;
    USE(tmp154);
    tmp154 = Undefined_0(state_);
    ca_.Goto(&block29, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154);
  }

  if (block29.is_used()) {
    TNode<Context> tmp155;
    TNode<Object> tmp156;
    TNode<Object> tmp157;
    TNode<JSArray> tmp158;
    TNode<Smi> tmp159;
    TNode<FixedArrayBase> tmp160;
    TNode<FixedDoubleArray> tmp161;
    TNode<Object> tmp162;
    TNode<Object> tmp163;
    ca_.Bind(&block29, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163);
    ca_.Goto(&block2, tmp155, tmp156, tmp162, tmp163);
  }

  if (block34.is_used()) {
    TNode<Context> tmp164;
    TNode<Object> tmp165;
    TNode<Object> tmp166;
    TNode<Object> tmp167;
    TNode<Context> tmp168;
    ca_.Bind(&block34, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp164}, MessageTemplate::kIteratorValueNotAnObject, TNode<Object>{ca_.UncheckedCast<Object>(tmp166)});
  }

  if (block33.is_used()) {
    TNode<Context> tmp169;
    TNode<Object> tmp170;
    TNode<Object> tmp171;
    TNode<Object> tmp172;
    TNode<Context> tmp173;
    TNode<JSReceiver> tmp174;
    ca_.Bind(&block33, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    ca_.Goto(label_MayHaveSideEffects);
  }

  if (block2.is_used()) {
    TNode<Context> tmp175;
    TNode<Object> tmp176;
    TNode<Object> tmp177;
    TNode<Object> tmp178;
    ca_.Bind(&block2, &tmp175, &tmp176, &tmp177, &tmp178);
    ca_.Goto(&block35, tmp175, tmp176, tmp177, tmp178);
  }

    TNode<Context> tmp179;
    TNode<Object> tmp180;
    TNode<Object> tmp181;
    TNode<Object> tmp182;
    ca_.Bind(&block35, &tmp179, &tmp180, &tmp181, &tmp182);
  return TorqueStructKeyValuePair{TNode<Object>{tmp181}, TNode<Object>{tmp182}};
}

TorqueStructKeyValuePair LoadKeyValuePair_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    std::tie(tmp2, tmp3) = LoadKeyValuePairNoSideEffects_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0).Flatten();
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = Convert_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp4}, TNode<Object>{tmp5}, TNode<Object>{tmp8});
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = Convert_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp4}, TNode<Object>{tmp5}, TNode<Object>{tmp10});
    ca_.Goto(&block1, tmp4, tmp5, tmp9, tmp11);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block1, tmp12, tmp13, tmp16, tmp17);
  }

  if (block1.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block1, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp18, tmp19, tmp20, tmp21);
  }

    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24, &tmp25);
  return TorqueStructKeyValuePair{TNode<Object>{tmp24}, TNode<Object>{tmp25}};
}

}  // namespace internal
}  // namespace v8

