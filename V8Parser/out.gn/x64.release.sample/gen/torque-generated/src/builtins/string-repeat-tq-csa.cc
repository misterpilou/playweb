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

const char* kBuiltinName_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return "String.prototype.repeat";
}

TF_BUILTIN(StringRepeat, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<String> parameter1 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<Smi> parameter2 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, Smi, String, String, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<Smi> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<String> tmp3;
    USE(tmp3);
    tmp3 = kEmptyString_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp2});
    ca_.Goto(&block11, tmp0, tmp1, tmp2, tmp3, tmp1, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<String> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'count >= 0' failed", "src/builtins/string-repeat.tq", 10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<String> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
  }

  if (block8.is_used()) {
    TNode<Context> tmp11;
    TNode<String> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block8, &tmp11, &tmp12, &tmp13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'string != kEmptyString' failed", "src/builtins/string-repeat.tq", 11);
  }

  if (block7.is_used()) {
    TNode<Context> tmp14;
    TNode<String> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block7, &tmp14, &tmp15, &tmp16);
  }

  if (block11.is_used()) {
    TNode<Context> tmp17;
    TNode<String> tmp18;
    TNode<Smi> tmp19;
    TNode<String> tmp20;
    TNode<String> tmp21;
    TNode<IntPtrT> tmp22;
    ca_.Bind(&block11, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp23, &block9, &block10, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22);
  }

  if (block9.is_used()) {
    TNode<Context> tmp24;
    TNode<String> tmp25;
    TNode<Smi> tmp26;
    TNode<String> tmp27;
    TNode<String> tmp28;
    TNode<IntPtrT> tmp29;
    ca_.Bind(&block9, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp29}, TNode<IntPtrT>{tmp30});
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp31}, TNode<IntPtrT>{tmp32});
    ca_.Branch(tmp33, &block12, &block13, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29);
  }

  if (block12.is_used()) {
    TNode<Context> tmp34;
    TNode<String> tmp35;
    TNode<Smi> tmp36;
    TNode<String> tmp37;
    TNode<String> tmp38;
    TNode<IntPtrT> tmp39;
    ca_.Bind(&block12, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<String> tmp40;
    USE(tmp40);
    tmp40 = StringAdd_0(state_, TNode<Context>{tmp34}, TNode<String>{tmp37}, TNode<String>{tmp38});
    ca_.Goto(&block13, tmp34, tmp35, tmp36, tmp40, tmp38, tmp39);
  }

  if (block13.is_used()) {
    TNode<Context> tmp41;
    TNode<String> tmp42;
    TNode<Smi> tmp43;
    TNode<String> tmp44;
    TNode<String> tmp45;
    TNode<IntPtrT> tmp46;
    ca_.Bind(&block13, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46);
    TNode<IntPtrT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).WordSar(TNode<IntPtrT>{tmp46}, TNode<IntPtrT>{tmp47});
    TNode<IntPtrT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp48}, TNode<IntPtrT>{tmp49});
    ca_.Branch(tmp50, &block14, &block15, tmp41, tmp42, tmp43, tmp44, tmp45, tmp48);
  }

  if (block14.is_used()) {
    TNode<Context> tmp51;
    TNode<String> tmp52;
    TNode<Smi> tmp53;
    TNode<String> tmp54;
    TNode<String> tmp55;
    TNode<IntPtrT> tmp56;
    ca_.Bind(&block14, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    ca_.Goto(&block10, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56);
  }

  if (block15.is_used()) {
    TNode<Context> tmp57;
    TNode<String> tmp58;
    TNode<Smi> tmp59;
    TNode<String> tmp60;
    TNode<String> tmp61;
    TNode<IntPtrT> tmp62;
    ca_.Bind(&block15, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<String> tmp63;
    USE(tmp63);
    tmp63 = StringAdd_0(state_, TNode<Context>{tmp57}, TNode<String>{tmp61}, TNode<String>{tmp61});
    ca_.Goto(&block11, tmp57, tmp58, tmp59, tmp60, tmp63, tmp62);
  }

  if (block10.is_used()) {
    TNode<Context> tmp64;
    TNode<String> tmp65;
    TNode<Smi> tmp66;
    TNode<String> tmp67;
    TNode<String> tmp68;
    TNode<IntPtrT> tmp69;
    ca_.Bind(&block10, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    CodeStubAssembler(state_).Return(tmp67);
  }
}

TF_BUILTIN(StringPrototypeRepeat, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kCount));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Number, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi, BoolT, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T, BoolT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T, BoolT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T, BoolT, BoolT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String, Number, HeapNumber, Float64T> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, String> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<String> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_String_constexpr_string_0(state_, kBuiltinName_0(state_));
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp3});
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp2}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    TNode<Smi> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_Smi_0(state_, TNode<Object>{tmp5}, &label0);
    ca_.Goto(&block9, tmp0, tmp1, tmp2, tmp4, tmp5, tmp5, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp0, tmp1, tmp2, tmp4, tmp5, tmp5);
    }
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<String> tmp10;
    TNode<Number> tmp11;
    TNode<Number> tmp12;
    ca_.Bind(&block10, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<Float64T> tmp13;
    USE(tmp13);
    tmp13 = LoadHeapNumberValue_0(state_, TNode<HeapNumber>{ca_.UncheckedCast<HeapNumber>(tmp11)});
    TNode<Float64T> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_float64_constexpr_float64_0(state_, V8_INFINITY);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).Float64Equal(TNode<Float64T>{tmp13}, TNode<Float64T>{tmp14});
    ca_.Branch(tmp15, &block26, &block27, tmp7, tmp8, tmp9, tmp10, tmp11, ca_.UncheckedCast<HeapNumber>(tmp11), tmp13, tmp15);
  }

  if (block9.is_used()) {
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<String> tmp19;
    TNode<Number> tmp20;
    TNode<Number> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block9, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    TNode<Smi> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp22}, TNode<Smi>{tmp23});
    ca_.Branch(tmp24, &block11, &block12, tmp16, tmp17, tmp18, tmp19, tmp20, tmp22);
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<String> tmp28;
    TNode<Number> tmp29;
    TNode<Smi> tmp30;
    ca_.Bind(&block11, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block4, tmp25, tmp26, tmp27, tmp28);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<String> tmp34;
    TNode<Number> tmp35;
    TNode<Smi> tmp36;
    ca_.Bind(&block12, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp36}, TNode<Smi>{tmp37});
    ca_.Branch(tmp38, &block15, &block16, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp38);
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Object> tmp41;
    TNode<String> tmp42;
    TNode<Number> tmp43;
    TNode<Smi> tmp44;
    TNode<BoolT> tmp45;
    ca_.Bind(&block15, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block17, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<String> tmp50;
    TNode<Number> tmp51;
    TNode<Smi> tmp52;
    TNode<BoolT> tmp53;
    ca_.Bind(&block16, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<Uint32T> tmp54;
    USE(tmp54);
    tmp54 = CodeStubAssembler(state_).LoadStringLengthAsWord32(TNode<String>{tmp50});
    TNode<Uint32T> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp54}, TNode<Uint32T>{tmp55});
    ca_.Goto(&block17, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp56);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<String> tmp60;
    TNode<Number> tmp61;
    TNode<Smi> tmp62;
    TNode<BoolT> tmp63;
    TNode<BoolT> tmp64;
    ca_.Bind(&block17, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Branch(tmp64, &block13, &block14, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62);
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<String> tmp68;
    TNode<Number> tmp69;
    TNode<Smi> tmp70;
    ca_.Bind(&block13, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    ca_.Goto(&block6, tmp65, tmp66, tmp67, tmp68);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp71;
    TNode<Object> tmp72;
    TNode<Object> tmp73;
    TNode<String> tmp74;
    TNode<Number> tmp75;
    TNode<Smi> tmp76;
    ca_.Bind(&block14, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76);
    TNode<Smi> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_Smi_constexpr_int31_0(state_, String::kMaxLength);
    TNode<BoolT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp76}, TNode<Smi>{tmp77});
    ca_.Branch(tmp78, &block18, &block19, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    TNode<String> tmp82;
    TNode<Number> tmp83;
    TNode<Smi> tmp84;
    ca_.Bind(&block18, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    ca_.Goto(&block2, tmp79, tmp80, tmp81, tmp82);
  }

  if (block19.is_used()) {
    TNode<NativeContext> tmp85;
    TNode<Object> tmp86;
    TNode<Object> tmp87;
    TNode<String> tmp88;
    TNode<Number> tmp89;
    TNode<Smi> tmp90;
    ca_.Bind(&block19, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    TNode<String> tmp91;
    tmp91 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringRepeat, tmp85, tmp88, tmp90));
    USE(tmp91);
    CodeStubAssembler(state_).Return(tmp91);
  }

  if (block23.is_used()) {
    TNode<NativeContext> tmp92;
    TNode<Object> tmp93;
    TNode<Object> tmp94;
    TNode<String> tmp95;
    TNode<Number> tmp96;
    TNode<HeapNumber> tmp97;
    ca_.Bind(&block23, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(heapNum)' failed", "src/builtins/string-repeat.tq", 54);
  }

  if (block22.is_used()) {
    TNode<NativeContext> tmp98;
    TNode<Object> tmp99;
    TNode<Object> tmp100;
    TNode<String> tmp101;
    TNode<Number> tmp102;
    TNode<HeapNumber> tmp103;
    ca_.Bind(&block22, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
  }

  if (block26.is_used()) {
    TNode<NativeContext> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<String> tmp107;
    TNode<Number> tmp108;
    TNode<HeapNumber> tmp109;
    TNode<Float64T> tmp110;
    TNode<BoolT> tmp111;
    ca_.Bind(&block26, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111);
    TNode<BoolT> tmp112;
    USE(tmp112);
    tmp112 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block28, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112);
  }

  if (block27.is_used()) {
    TNode<NativeContext> tmp113;
    TNode<Object> tmp114;
    TNode<Object> tmp115;
    TNode<String> tmp116;
    TNode<Number> tmp117;
    TNode<HeapNumber> tmp118;
    TNode<Float64T> tmp119;
    TNode<BoolT> tmp120;
    ca_.Bind(&block27, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120);
    TNode<Float64T> tmp121;
    USE(tmp121);
    tmp121 = FromConstexpr_float64_constexpr_int31_0(state_, 0.0);
    TNode<BoolT> tmp122;
    USE(tmp122);
    tmp122 = CodeStubAssembler(state_).Float64LessThan(TNode<Float64T>{tmp119}, TNode<Float64T>{tmp121});
    ca_.Goto(&block28, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp122);
  }

  if (block28.is_used()) {
    TNode<NativeContext> tmp123;
    TNode<Object> tmp124;
    TNode<Object> tmp125;
    TNode<String> tmp126;
    TNode<Number> tmp127;
    TNode<HeapNumber> tmp128;
    TNode<Float64T> tmp129;
    TNode<BoolT> tmp130;
    TNode<BoolT> tmp131;
    ca_.Bind(&block28, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
    ca_.Branch(tmp131, &block24, &block25, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129);
  }

  if (block24.is_used()) {
    TNode<NativeContext> tmp132;
    TNode<Object> tmp133;
    TNode<Object> tmp134;
    TNode<String> tmp135;
    TNode<Number> tmp136;
    TNode<HeapNumber> tmp137;
    TNode<Float64T> tmp138;
    ca_.Bind(&block24, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    ca_.Goto(&block4, tmp132, tmp133, tmp134, tmp135);
  }

  if (block25.is_used()) {
    TNode<NativeContext> tmp139;
    TNode<Object> tmp140;
    TNode<Object> tmp141;
    TNode<String> tmp142;
    TNode<Number> tmp143;
    TNode<HeapNumber> tmp144;
    TNode<Float64T> tmp145;
    ca_.Bind(&block25, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145);
    TNode<Uint32T> tmp146;
    USE(tmp146);
    tmp146 = CodeStubAssembler(state_).LoadStringLengthAsWord32(TNode<String>{tmp142});
    TNode<Uint32T> tmp147;
    USE(tmp147);
    tmp147 = FromConstexpr_uint32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp148;
    USE(tmp148);
    tmp148 = CodeStubAssembler(state_).Word32Equal(TNode<Uint32T>{tmp146}, TNode<Uint32T>{tmp147});
    ca_.Branch(tmp148, &block29, &block30, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145);
  }

  if (block29.is_used()) {
    TNode<NativeContext> tmp149;
    TNode<Object> tmp150;
    TNode<Object> tmp151;
    TNode<String> tmp152;
    TNode<Number> tmp153;
    TNode<HeapNumber> tmp154;
    TNode<Float64T> tmp155;
    ca_.Bind(&block29, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155);
    ca_.Goto(&block6, tmp149, tmp150, tmp151, tmp152);
  }

  if (block30.is_used()) {
    TNode<NativeContext> tmp156;
    TNode<Object> tmp157;
    TNode<Object> tmp158;
    TNode<String> tmp159;
    TNode<Number> tmp160;
    TNode<HeapNumber> tmp161;
    TNode<Float64T> tmp162;
    ca_.Bind(&block30, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162);
    ca_.Goto(&block2, tmp156, tmp157, tmp158, tmp159);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp163;
    TNode<Object> tmp164;
    TNode<Object> tmp165;
    TNode<String> tmp166;
    ca_.Bind(&block6, &tmp163, &tmp164, &tmp165, &tmp166);
    TNode<String> tmp167;
    USE(tmp167);
    tmp167 = kEmptyString_0(state_);
    CodeStubAssembler(state_).Return(tmp167);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp168;
    TNode<Object> tmp169;
    TNode<Object> tmp170;
    TNode<String> tmp171;
    ca_.Bind(&block4, &tmp168, &tmp169, &tmp170, &tmp171);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp168}, MessageTemplate::kInvalidCountValue, TNode<Object>{tmp170});
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp172;
    TNode<Object> tmp173;
    TNode<Object> tmp174;
    TNode<String> tmp175;
    ca_.Bind(&block2, &tmp172, &tmp173, &tmp174, &tmp175);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidStringLength, tmp172);
    CodeStubAssembler(state_).Unreachable();
  }
}

}  // namespace internal
}  // namespace v8

