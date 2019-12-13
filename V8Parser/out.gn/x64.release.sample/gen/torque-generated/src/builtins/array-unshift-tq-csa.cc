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

TNode<Number> GenericArrayUnshift_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TorqueStructArguments p_arguments) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Number, Number, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Number, Number, Oddball> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Number, Number, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi, Number, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, JSReceiver, Number, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_arguments.frame, p_arguments.base, p_arguments.length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = GetLengthProperty_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp4});
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<RawPtrT> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Number> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Number> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp16}, TNode<Number>{tmp17});
    TNode<Number> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Number_constexpr_float64_0(state_, kMaxSafeInteger);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp18}, TNode<Number>{tmp19});
    ca_.Branch(tmp20, &block4, &block5, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
  }

  if (block4.is_used()) {
    TNode<Context> tmp21;
    TNode<Object> tmp22;
    TNode<RawPtrT> tmp23;
    TNode<RawPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<Number> tmp27;
    TNode<Smi> tmp28;
    ca_.Bind(&block4, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp21}, MessageTemplate::kInvalidArrayLength);
  }

  if (block5.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<RawPtrT> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Number> tmp35;
    TNode<Smi> tmp36;
    ca_.Bind(&block5, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    ca_.Goto(&block8, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp35);
  }

  if (block8.is_used()) {
    TNode<Context> tmp37;
    TNode<Object> tmp38;
    TNode<RawPtrT> tmp39;
    TNode<RawPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Number> tmp43;
    TNode<Smi> tmp44;
    TNode<Number> tmp45;
    ca_.Bind(&block8, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<Number> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp45}, TNode<Number>{tmp46});
    ca_.Branch(tmp47, &block6, &block7, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45);
  }

  if (block6.is_used()) {
    TNode<Context> tmp48;
    TNode<Object> tmp49;
    TNode<RawPtrT> tmp50;
    TNode<RawPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<JSReceiver> tmp53;
    TNode<Number> tmp54;
    TNode<Smi> tmp55;
    TNode<Number> tmp56;
    ca_.Bind(&block6, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<Number> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp58;
    USE(tmp58);
    tmp58 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp56}, TNode<Number>{tmp57});
    TNode<Number> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp56}, TNode<Number>{tmp55});
    TNode<Number> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp59}, TNode<Number>{tmp60});
    TNode<Oddball> tmp62;
    tmp62 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kHasProperty, tmp48, tmp53, tmp58));
    USE(tmp62);
    TNode<Oddball> tmp63;
    USE(tmp63);
    tmp63 = True_0(state_);
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp62}, TNode<HeapObject>{tmp63});
    ca_.Branch(tmp64, &block9, &block10, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp58, tmp61, tmp62);
  }

  if (block9.is_used()) {
    TNode<Context> tmp65;
    TNode<Object> tmp66;
    TNode<RawPtrT> tmp67;
    TNode<RawPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<Number> tmp71;
    TNode<Smi> tmp72;
    TNode<Number> tmp73;
    TNode<Number> tmp74;
    TNode<Number> tmp75;
    TNode<Oddball> tmp76;
    ca_.Bind(&block9, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Object> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp65}, TNode<Object>{tmp70}, TNode<Object>{tmp74});
    CodeStubAssembler(state_).CallBuiltin(Builtins::kSetProperty, tmp65, tmp70, tmp75, tmp77);
    ca_.Goto(&block11, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76);
  }

  if (block10.is_used()) {
    TNode<Context> tmp79;
    TNode<Object> tmp80;
    TNode<RawPtrT> tmp81;
    TNode<RawPtrT> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Number> tmp85;
    TNode<Smi> tmp86;
    TNode<Number> tmp87;
    TNode<Number> tmp88;
    TNode<Number> tmp89;
    TNode<Oddball> tmp90;
    ca_.Bind(&block10, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<Smi> tmp91;
    USE(tmp91);
    tmp91 = FromConstexpr_LanguageMode_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    TNode<Oddball> tmp92;
    tmp92 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kDeleteProperty, tmp79, tmp84, tmp89, tmp91));
    USE(tmp92);
    ca_.Goto(&block11, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

  if (block11.is_used()) {
    TNode<Context> tmp93;
    TNode<Object> tmp94;
    TNode<RawPtrT> tmp95;
    TNode<RawPtrT> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<JSReceiver> tmp98;
    TNode<Number> tmp99;
    TNode<Smi> tmp100;
    TNode<Number> tmp101;
    TNode<Number> tmp102;
    TNode<Number> tmp103;
    TNode<Oddball> tmp104;
    ca_.Bind(&block11, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<Number> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp101}, TNode<Number>{tmp105});
    ca_.Goto(&block8, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp106);
  }

  if (block7.is_used()) {
    TNode<Context> tmp107;
    TNode<Object> tmp108;
    TNode<RawPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<Number> tmp113;
    TNode<Smi> tmp114;
    TNode<Number> tmp115;
    ca_.Bind(&block7, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115);
    TNode<Smi> tmp116;
    USE(tmp116);
    tmp116 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block14, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116);
  }

  if (block14.is_used()) {
    TNode<Context> tmp117;
    TNode<Object> tmp118;
    TNode<RawPtrT> tmp119;
    TNode<RawPtrT> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<JSReceiver> tmp122;
    TNode<Number> tmp123;
    TNode<Smi> tmp124;
    TNode<Number> tmp125;
    TNode<Smi> tmp126;
    ca_.Bind(&block14, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126);
    TNode<BoolT> tmp127;
    USE(tmp127);
    tmp127 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp126}, TNode<Smi>{tmp124});
    ca_.Branch(tmp127, &block12, &block13, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126);
  }

  if (block12.is_used()) {
    TNode<Context> tmp128;
    TNode<Object> tmp129;
    TNode<RawPtrT> tmp130;
    TNode<RawPtrT> tmp131;
    TNode<IntPtrT> tmp132;
    TNode<JSReceiver> tmp133;
    TNode<Number> tmp134;
    TNode<Smi> tmp135;
    TNode<Number> tmp136;
    TNode<Smi> tmp137;
    ca_.Bind(&block12, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137);
    TNode<IntPtrT> tmp138;
    USE(tmp138);
    tmp138 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp137});
    TNode<Object> tmp139;
    USE(tmp139);
    tmp139 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp130}, TNode<RawPtrT>{tmp131}, TNode<IntPtrT>{tmp132}}, TNode<IntPtrT>{tmp138});
    CodeStubAssembler(state_).CallBuiltin(Builtins::kSetProperty, tmp128, tmp133, tmp137, tmp139);
    TNode<Smi> tmp141;
    USE(tmp141);
    tmp141 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp142;
    USE(tmp142);
    tmp142 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp137}, TNode<Smi>{tmp141});
    ca_.Goto(&block14, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp142);
  }

  if (block13.is_used()) {
    TNode<Context> tmp143;
    TNode<Object> tmp144;
    TNode<RawPtrT> tmp145;
    TNode<RawPtrT> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<JSReceiver> tmp148;
    TNode<Number> tmp149;
    TNode<Smi> tmp150;
    TNode<Number> tmp151;
    TNode<Smi> tmp152;
    ca_.Bind(&block13, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    ca_.Goto(&block3, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150);
  }

  if (block3.is_used()) {
    TNode<Context> tmp153;
    TNode<Object> tmp154;
    TNode<RawPtrT> tmp155;
    TNode<RawPtrT> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<JSReceiver> tmp158;
    TNode<Number> tmp159;
    TNode<Smi> tmp160;
    ca_.Bind(&block3, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160);
    TNode<Number> tmp161;
    USE(tmp161);
    tmp161 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp159}, TNode<Number>{tmp160});
    TNode<String> tmp162;
    USE(tmp162);
    tmp162 = kLengthString_0(state_);
    CodeStubAssembler(state_).CallBuiltin(Builtins::kSetProperty, tmp153, tmp158, tmp162, tmp161);
    ca_.Goto(&block15, tmp153, tmp154, tmp155, tmp156, tmp157, tmp161);
  }

    TNode<Context> tmp164;
    TNode<Object> tmp165;
    TNode<RawPtrT> tmp166;
    TNode<RawPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<Number> tmp169;
    ca_.Bind(&block15, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169);
  return TNode<Number>{tmp169};
}

TF_BUILTIN(ArrayPrototypeUnshift, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Object, NativeContext, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSArray, Map> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSArray, Map> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSArray, Map, Map, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSArray, Map, Map, NativeContext> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSArray> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_FastJSArray_1(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp3);
    }
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp6;
    TNode<RawPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    TNode<NativeContext> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<NativeContext> tmp12;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block2, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp13;
    TNode<RawPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<NativeContext> tmp19;
    TNode<JSArray> tmp20;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    EnsureWriteableFastElements_0(state_, TNode<Context>{tmp16}, TNode<JSArray>{tmp20});
    TNode<IntPtrT> tmp21 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp21);
    TNode<Map>tmp22 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp20, tmp21});
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IsExtensibleMap(TNode<Map>{tmp22});
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp23});
    ca_.Branch(tmp24, &block5, &block6, tmp13, tmp14, tmp15, tmp16, tmp17, tmp20, tmp22);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp25;
    TNode<RawPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<NativeContext> tmp28;
    TNode<Object> tmp29;
    TNode<JSArray> tmp30;
    TNode<Map> tmp31;
    ca_.Bind(&block5, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    ca_.Goto(&block2, tmp25, tmp26, tmp27, tmp28, tmp29);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp32;
    TNode<RawPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<JSArray> tmp37;
    TNode<Map> tmp38;
    ca_.Bind(&block6, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    compiler::CodeAssemblerLabel label0(&ca_);
    EnsureArrayLengthWritable_0(state_, TNode<Context>{tmp35}, TNode<Map>{tmp38}, &label0);
    ca_.Goto(&block7, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp38, tmp35);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp38, tmp35);
    }
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp39;
    TNode<RawPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<NativeContext> tmp42;
    TNode<Object> tmp43;
    TNode<JSArray> tmp44;
    TNode<Map> tmp45;
    TNode<Map> tmp46;
    TNode<NativeContext> tmp47;
    ca_.Bind(&block8, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    ca_.Goto(&block2, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp48;
    TNode<RawPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<JSArray> tmp53;
    TNode<Map> tmp54;
    TNode<Map> tmp55;
    TNode<NativeContext> tmp56;
    ca_.Bind(&block7, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<JSFunction> tmp57;
    USE(tmp57);
    tmp57 = LoadTargetFromFrame_0(state_);
    TNode<Oddball> tmp58;
    USE(tmp58);
    tmp58 = Undefined_0(state_);
    TNode<Int32T> tmp59;
    USE(tmp59);
    tmp59 = Convert_int32_intptr_0(state_, TNode<IntPtrT>{tmp50});
   CodeStubAssembler(state_).TailCallBuiltin(Builtins::kArrayUnshift, tmp51, tmp57, tmp58, tmp59);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp60;
    TNode<RawPtrT> tmp61;
    TNode<IntPtrT> tmp62;
    TNode<NativeContext> tmp63;
    TNode<Object> tmp64;
    ca_.Bind(&block2, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    TNode<Number> tmp65;
    USE(tmp65);
    tmp65 = GenericArrayUnshift_0(state_, TNode<Context>{tmp63}, TNode<Object>{tmp64}, TorqueStructArguments{TNode<RawPtrT>{tmp60}, TNode<RawPtrT>{tmp61}, TNode<IntPtrT>{tmp62}});
    arguments.PopAndReturn(tmp65);
  }
}

}  // namespace internal
}  // namespace v8

