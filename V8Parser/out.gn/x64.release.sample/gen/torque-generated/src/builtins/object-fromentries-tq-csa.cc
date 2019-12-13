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

TNode<JSObject> ObjectFromEntriesFastCase_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_iterable, compiler::CodeAssemblerLabel* label_IfSlow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArrayBase> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArrayBase, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi, Object, Object, Context> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi, Object, Object, Context, Object, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi, Object, Object, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi, Object, Object, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, JSArray, FixedArray, Smi, JSObject, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSObject> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_iterable);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSArrayWithNoCustomIteration_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
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
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Context> tmp12;
    TNode<JSArray> tmp13;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    TNode<IntPtrT> tmp14 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp14);
    TNode<FixedArrayBase>tmp15 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp13, tmp14});
    TNode<FixedArray> tmp16;
    USE(tmp16);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp16 = Cast_FixedArray_0(state_, TNode<HeapObject>{tmp15}, &label0);
    ca_.Goto(&block7, tmp8, tmp9, tmp10, tmp13, tmp15, tmp16);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp8, tmp9, tmp10, tmp13, tmp15);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<JSArray> tmp20;
    TNode<FixedArrayBase> tmp21;
    ca_.Bind(&block8, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block1);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Object> tmp24;
    TNode<JSArray> tmp25;
    TNode<FixedArrayBase> tmp26;
    TNode<FixedArray> tmp27;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<Smi> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).LoadFastJSArrayLength(TNode<JSArray>{tmp25});
    TNode<JSObject> tmp29;
    USE(tmp29);
    tmp29 = NewJSObject_0(state_, TNode<Context>{tmp22});
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block11, tmp22, tmp23, tmp24, tmp25, tmp27, tmp28, tmp29, tmp30);
  }

  if (block11.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<JSArray> tmp34;
    TNode<FixedArray> tmp35;
    TNode<Smi> tmp36;
    TNode<JSObject> tmp37;
    TNode<Smi> tmp38;
    ca_.Bind(&block11, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp38}, TNode<Smi>{tmp36});
    ca_.Branch(tmp39, &block9, &block10, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38);
  }

  if (block9.is_used()) {
    TNode<Context> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<JSArray> tmp43;
    TNode<FixedArray> tmp44;
    TNode<Smi> tmp45;
    TNode<JSObject> tmp46;
    TNode<Smi> tmp47;
    ca_.Bind(&block9, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Object> tmp48;
    USE(tmp48);
    tmp48 = LoadElementOrUndefined_0(state_, TNode<Context>{tmp40}, TNode<FixedArray>{tmp44}, TNode<Smi>{tmp47});
    TNode<Object> tmp49;
    USE(tmp49);
    TNode<Object> tmp50;
    USE(tmp50);
    compiler::CodeAssemblerLabel label0(&ca_);
    std::tie(tmp49, tmp50) = LoadKeyValuePairNoSideEffects_0(state_, TNode<Context>{tmp40}, TNode<Object>{tmp48}, &label0).Flatten();
    ca_.Goto(&block13, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp48, tmp40, tmp49, tmp50);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp48, tmp40);
    }
  }

  if (block14.is_used()) {
    TNode<Context> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    TNode<JSArray> tmp54;
    TNode<FixedArray> tmp55;
    TNode<Smi> tmp56;
    TNode<JSObject> tmp57;
    TNode<Smi> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<Context> tmp61;
    ca_.Bind(&block14, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    ca_.Goto(&block1);
  }

  if (block13.is_used()) {
    TNode<Context> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<JSArray> tmp65;
    TNode<FixedArray> tmp66;
    TNode<Smi> tmp67;
    TNode<JSObject> tmp68;
    TNode<Smi> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<Context> tmp72;
    TNode<Object> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block13, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<BoolT> tmp75;
    USE(tmp75);
    tmp75 = Is_JSReceiver_JSAny_0(state_, TNode<Context>{tmp62}, TNode<Object>{tmp73});
    ca_.Branch(tmp75, &block15, &block16, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp73, tmp74);
  }

  if (block15.is_used()) {
    TNode<Context> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<JSArray> tmp79;
    TNode<FixedArray> tmp80;
    TNode<Smi> tmp81;
    TNode<JSObject> tmp82;
    TNode<Smi> tmp83;
    TNode<Object> tmp84;
    TNode<Object> tmp85;
    TNode<Object> tmp86;
    ca_.Bind(&block15, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86);
    ca_.Goto(&block1);
  }

  if (block16.is_used()) {
    TNode<Context> tmp87;
    TNode<Object> tmp88;
    TNode<Object> tmp89;
    TNode<JSArray> tmp90;
    TNode<FixedArray> tmp91;
    TNode<Smi> tmp92;
    TNode<JSObject> tmp93;
    TNode<Smi> tmp94;
    TNode<Object> tmp95;
    TNode<Object> tmp96;
    TNode<Object> tmp97;
    ca_.Bind(&block16, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    TNode<Object> tmp98;
    tmp98 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp87, tmp93, tmp96, tmp97);
    USE(tmp98);
    TNode<Smi> tmp99;
    USE(tmp99);
    tmp99 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp100;
    USE(tmp100);
    tmp100 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp94}, TNode<Smi>{tmp99});
    ca_.Goto(&block11, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp100);
  }

  if (block10.is_used()) {
    TNode<Context> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<JSArray> tmp104;
    TNode<FixedArray> tmp105;
    TNode<Smi> tmp106;
    TNode<JSObject> tmp107;
    TNode<Smi> tmp108;
    ca_.Bind(&block10, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    ca_.Goto(&block17, tmp101, tmp102, tmp107);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfSlow);
  }

    TNode<Context> tmp109;
    TNode<Object> tmp110;
    TNode<JSObject> tmp111;
    ca_.Bind(&block17, &tmp109, &tmp110, &tmp111);
  return TNode<JSObject>{tmp111};
}

TF_BUILTIN(ObjectFromEntries, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, Object, NativeContext, JSObject> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, BoolT, Object> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, Object> block20(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object, Map, NativeContext, Object> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object, Map, NativeContext> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object, Map, NativeContext, JSReceiver> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, JSReceiver, Map, NativeContext, Object> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object, Object, NativeContext, Object> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, JSReceiver, Object, Object, Object, JSObject, Object, Object, NativeContext, Object> block28(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, JSObject, Map, JSReceiver, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kDeferred);
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
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).IsNullOrUndefined(TNode<Object>{tmp6});
    ca_.Branch(tmp7, &block5, &block6, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp8;
    TNode<RawPtrT> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp11}, MessageTemplate::kNotIterable);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp14;
    TNode<RawPtrT> tmp15;
    TNode<IntPtrT> tmp16;
    TNode<NativeContext> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    ca_.Bind(&block6, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<JSObject> tmp20;
    USE(tmp20);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp20 = ObjectFromEntriesFastCase_0(state_, TNode<Context>{tmp17}, TNode<Object>{tmp19}, &label0);
    ca_.Goto(&block7, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp19, tmp17, tmp20);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp19, tmp17);
    }
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<NativeContext> tmp24;
    TNode<Object> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<NativeContext> tmp28;
    ca_.Bind(&block8, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<JSObject> tmp29;
    USE(tmp29);
    tmp29 = NewJSObject_0(state_, TNode<Context>{tmp24});
    TNode<Map> tmp30;
    USE(tmp30);
    tmp30 = GetIteratorResultMap_0(state_, TNode<Context>{tmp24});
    TNode<JSReceiver> tmp31;
    USE(tmp31);
    TNode<Object> tmp32;
    USE(tmp32);
    std::tie(tmp31, tmp32) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp24}, TNode<Object>{tmp26}).Flatten();
    ca_.Goto(&block19, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp29, tmp30, tmp31, tmp32);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<NativeContext> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<NativeContext> tmp40;
    TNode<JSObject> tmp41;
    ca_.Bind(&block7, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    arguments.PopAndReturn(tmp41);
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp42;
    TNode<RawPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<JSObject> tmp48;
    TNode<Map> tmp49;
    TNode<JSReceiver> tmp50;
    TNode<Object> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    ca_.Bind(&block15, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    ca_.Goto(&block10, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp53);
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp54;
    TNode<RawPtrT> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<JSObject> tmp60;
    TNode<Map> tmp61;
    TNode<JSReceiver> tmp62;
    TNode<Object> tmp63;
    TNode<BoolT> tmp64;
    TNode<Object> tmp65;
    ca_.Bind(&block16, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    ca_.Goto(&block10, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp65);
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp66;
    TNode<RawPtrT> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<NativeContext> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<JSObject> tmp72;
    TNode<Map> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Object> tmp75;
    ca_.Bind(&block14, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    CodeStubAssembler(state_).FailAssert("Torque assert '!IsNullOrUndefined(i.object)' failed", "src/builtins/object-fromentries.tq", 48);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp76;
    TNode<RawPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<NativeContext> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    TNode<JSObject> tmp82;
    TNode<Map> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Object> tmp85;
    ca_.Bind(&block13, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
  }

  if (block19.is_used()) {
    TNode<RawPtrT> tmp86;
    TNode<RawPtrT> tmp87;
    TNode<IntPtrT> tmp88;
    TNode<NativeContext> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<JSObject> tmp92;
    TNode<Map> tmp93;
    TNode<JSReceiver> tmp94;
    TNode<Object> tmp95;
    ca_.Bind(&block19, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95);
    TNode<BoolT> tmp96;
    USE(tmp96);
    compiler::CodeAssemblerExceptionHandlerLabel catch97__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch97__label);
    tmp96 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    }
    if (catch97__label.is_used()) {
      compiler::CodeAssemblerLabel catch97_skip(&ca_);
      ca_.Goto(&catch97_skip);
      TNode<Object> catch97_exception_object;
      ca_.Bind(&catch97__label, &catch97_exception_object);
      ca_.Goto(&block20, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, catch97_exception_object);
      ca_.Bind(&catch97_skip);
    }
    ca_.Branch(tmp96, &block17, &block18, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95);
  }

  if (block20.is_used()) {
    TNode<RawPtrT> tmp98;
    TNode<RawPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<NativeContext> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<JSObject> tmp104;
    TNode<Map> tmp105;
    TNode<JSReceiver> tmp106;
    TNode<Object> tmp107;
    TNode<Object> tmp108;
    ca_.Bind(&block20, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    ca_.Goto(&block10, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<NativeContext> tmp112;
    TNode<Object> tmp113;
    TNode<Object> tmp114;
    TNode<JSObject> tmp115;
    TNode<Map> tmp116;
    TNode<JSReceiver> tmp117;
    TNode<Object> tmp118;
    ca_.Bind(&block17, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    TNode<JSReceiver> tmp119;
    USE(tmp119);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch120__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch120__label);
    tmp119 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp112}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp117}, TNode<Object>{tmp118}}, TNode<Map>{tmp116}, &label0);
    }
    if (catch120__label.is_used()) {
      compiler::CodeAssemblerLabel catch120_skip(&ca_);
      ca_.Goto(&catch120_skip);
      TNode<Object> catch120_exception_object;
      ca_.Bind(&catch120__label, &catch120_exception_object);
      ca_.Goto(&block25, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp117, tmp118, tmp116, tmp112, catch120_exception_object);
      ca_.Bind(&catch120_skip);
    }
    ca_.Goto(&block23, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp117, tmp118, tmp116, tmp112, tmp119);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block24, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp117, tmp118, tmp116, tmp112);
    }
  }

  if (block25.is_used()) {
    TNode<RawPtrT> tmp121;
    TNode<RawPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    TNode<NativeContext> tmp124;
    TNode<Object> tmp125;
    TNode<Object> tmp126;
    TNode<JSObject> tmp127;
    TNode<Map> tmp128;
    TNode<JSReceiver> tmp129;
    TNode<Object> tmp130;
    TNode<JSReceiver> tmp131;
    TNode<Object> tmp132;
    TNode<Map> tmp133;
    TNode<NativeContext> tmp134;
    TNode<Object> tmp135;
    ca_.Bind(&block25, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    ca_.Goto(&block10, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp135);
  }

  if (block24.is_used()) {
    TNode<RawPtrT> tmp136;
    TNode<RawPtrT> tmp137;
    TNode<IntPtrT> tmp138;
    TNode<NativeContext> tmp139;
    TNode<Object> tmp140;
    TNode<Object> tmp141;
    TNode<JSObject> tmp142;
    TNode<Map> tmp143;
    TNode<JSReceiver> tmp144;
    TNode<Object> tmp145;
    TNode<JSReceiver> tmp146;
    TNode<Object> tmp147;
    TNode<Map> tmp148;
    TNode<NativeContext> tmp149;
    ca_.Bind(&block24, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    arguments.PopAndReturn(tmp142);
  }

  if (block23.is_used()) {
    TNode<RawPtrT> tmp150;
    TNode<RawPtrT> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<NativeContext> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<JSObject> tmp156;
    TNode<Map> tmp157;
    TNode<JSReceiver> tmp158;
    TNode<Object> tmp159;
    TNode<JSReceiver> tmp160;
    TNode<Object> tmp161;
    TNode<Map> tmp162;
    TNode<NativeContext> tmp163;
    TNode<JSReceiver> tmp164;
    ca_.Bind(&block23, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164);
    TNode<Object> tmp165;
    USE(tmp165);
    compiler::CodeAssemblerExceptionHandlerLabel catch166__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch166__label);
    tmp165 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp153}, TNode<JSReceiver>{tmp164}, TNode<Map>{tmp157});
    }
    if (catch166__label.is_used()) {
      compiler::CodeAssemblerLabel catch166_skip(&ca_);
      ca_.Goto(&catch166_skip);
      TNode<Object> catch166_exception_object;
      ca_.Bind(&catch166__label, &catch166_exception_object);
      ca_.Goto(&block26, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp164, tmp164, tmp157, tmp153, catch166_exception_object);
      ca_.Bind(&catch166_skip);
    }
    TNode<Object> tmp167;
    USE(tmp167);
    TNode<Object> tmp168;
    USE(tmp168);
    compiler::CodeAssemblerExceptionHandlerLabel catch169__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch169__label);
    std::tie(tmp167, tmp168) = LoadKeyValuePair_0(state_, TNode<Context>{tmp153}, TNode<Object>{tmp165}).Flatten();
    }
    if (catch169__label.is_used()) {
      compiler::CodeAssemblerLabel catch169_skip(&ca_);
      ca_.Goto(&catch169_skip);
      TNode<Object> catch169_exception_object;
      ca_.Bind(&catch169__label, &catch169_exception_object);
      ca_.Goto(&block27, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp164, tmp165, tmp165, tmp153, catch169_exception_object);
      ca_.Bind(&catch169_skip);
    }
    TNode<Object> tmp170;
    compiler::CodeAssemblerExceptionHandlerLabel catch171__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch171__label);
    tmp170 = CodeStubAssembler(state_).CallBuiltin(Builtins::kFastCreateDataProperty, tmp153, tmp156, tmp167, tmp168);
    USE(tmp170);
    }
    if (catch171__label.is_used()) {
      compiler::CodeAssemblerLabel catch171_skip(&ca_);
      ca_.Goto(&catch171_skip);
      TNode<Object> catch171_exception_object;
      ca_.Bind(&catch171__label, &catch171_exception_object);
      ca_.Goto(&block28, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp164, tmp165, tmp167, tmp168, tmp156, tmp167, tmp168, tmp153, catch171_exception_object);
      ca_.Bind(&catch171_skip);
    }
    ca_.Goto(&block19, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159);
  }

  if (block26.is_used()) {
    TNode<RawPtrT> tmp172;
    TNode<RawPtrT> tmp173;
    TNode<IntPtrT> tmp174;
    TNode<NativeContext> tmp175;
    TNode<Object> tmp176;
    TNode<Object> tmp177;
    TNode<JSObject> tmp178;
    TNode<Map> tmp179;
    TNode<JSReceiver> tmp180;
    TNode<Object> tmp181;
    TNode<JSReceiver> tmp182;
    TNode<JSReceiver> tmp183;
    TNode<Map> tmp184;
    TNode<NativeContext> tmp185;
    TNode<Object> tmp186;
    ca_.Bind(&block26, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186);
    ca_.Goto(&block10, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp186);
  }

  if (block27.is_used()) {
    TNode<RawPtrT> tmp187;
    TNode<RawPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<NativeContext> tmp190;
    TNode<Object> tmp191;
    TNode<Object> tmp192;
    TNode<JSObject> tmp193;
    TNode<Map> tmp194;
    TNode<JSReceiver> tmp195;
    TNode<Object> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<Object> tmp198;
    TNode<Object> tmp199;
    TNode<NativeContext> tmp200;
    TNode<Object> tmp201;
    ca_.Bind(&block27, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201);
    ca_.Goto(&block10, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp201);
  }

  if (block28.is_used()) {
    TNode<RawPtrT> tmp202;
    TNode<RawPtrT> tmp203;
    TNode<IntPtrT> tmp204;
    TNode<NativeContext> tmp205;
    TNode<Object> tmp206;
    TNode<Object> tmp207;
    TNode<JSObject> tmp208;
    TNode<Map> tmp209;
    TNode<JSReceiver> tmp210;
    TNode<Object> tmp211;
    TNode<JSReceiver> tmp212;
    TNode<Object> tmp213;
    TNode<Object> tmp214;
    TNode<Object> tmp215;
    TNode<JSObject> tmp216;
    TNode<Object> tmp217;
    TNode<Object> tmp218;
    TNode<NativeContext> tmp219;
    TNode<Object> tmp220;
    ca_.Bind(&block28, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220);
    ca_.Goto(&block10, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp220);
  }

  if (block18.is_used()) {
    TNode<RawPtrT> tmp221;
    TNode<RawPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<NativeContext> tmp224;
    TNode<Object> tmp225;
    TNode<Object> tmp226;
    TNode<JSObject> tmp227;
    TNode<Map> tmp228;
    TNode<JSReceiver> tmp229;
    TNode<Object> tmp230;
    ca_.Bind(&block18, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230);
    arguments.PopAndReturn(tmp227);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp231;
    TNode<RawPtrT> tmp232;
    TNode<IntPtrT> tmp233;
    TNode<NativeContext> tmp234;
    TNode<Object> tmp235;
    TNode<Object> tmp236;
    TNode<JSObject> tmp237;
    TNode<Map> tmp238;
    TNode<JSReceiver> tmp239;
    TNode<Object> tmp240;
    TNode<Object> tmp241;
    ca_.Bind(&block10, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241);
    IteratorBuiltinsAssembler(state_).IteratorCloseOnException(TNode<Context>{tmp234}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp239}, TNode<Object>{tmp240}}, TNode<Object>{tmp241});
  }
}

TNode<JSArray> Cast_FastJSArrayWithNoCustomIteration_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<JSArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FastJSArrayWithNoCustomIteration_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArray> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArray>{tmp22};
}

TNode<BoolT> Is_JSReceiver_JSAny_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSReceiver> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Context> tmp11;
    TNode<JSReceiver> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp8, tmp9, tmp13);
  }

  if (block1.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

}  // namespace internal
}  // namespace v8

