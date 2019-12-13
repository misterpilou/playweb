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

TNode<Smi> TryFastAbstractStringIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_string, TNode<String> p_searchString, TNode<Smi> p_fromIndex, compiler::CodeAssemblerLabel* label_Slow) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, String> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT, BoolT, BoolT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT, UintPtrT, UintPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, UintPtrT, UintPtrT, String, String, UintPtrT, UintPtrT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_string, p_searchString, p_fromIndex);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<String> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<UintPtrT> tmp4;
    USE(tmp4);
    tmp4 = LoadStringLengthAsUintPtr_0(state_, TNode<String>{tmp1});
    TNode<UintPtrT> tmp5;
    USE(tmp5);
    tmp5 = LoadStringLengthAsUintPtr_0(state_, TNode<String>{tmp2});
    TNode<String> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_DirectString_0(state_, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<String> tmp8;
    TNode<String> tmp9;
    TNode<Smi> tmp10;
    TNode<UintPtrT> tmp11;
    TNode<UintPtrT> tmp12;
    TNode<String> tmp13;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp14;
    TNode<String> tmp15;
    TNode<String> tmp16;
    TNode<Smi> tmp17;
    TNode<UintPtrT> tmp18;
    TNode<UintPtrT> tmp19;
    TNode<String> tmp20;
    TNode<String> tmp21;
    ca_.Bind(&block3, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<String> tmp22;
    USE(tmp22);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp22 = Cast_DirectString_0(state_, TNode<HeapObject>{tmp16}, &label0);
    ca_.Goto(&block5, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp21, tmp16, tmp22);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp21, tmp16);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp23;
    TNode<String> tmp24;
    TNode<String> tmp25;
    TNode<Smi> tmp26;
    TNode<UintPtrT> tmp27;
    TNode<UintPtrT> tmp28;
    TNode<String> tmp29;
    TNode<String> tmp30;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp31;
    TNode<String> tmp32;
    TNode<String> tmp33;
    TNode<Smi> tmp34;
    TNode<UintPtrT> tmp35;
    TNode<UintPtrT> tmp36;
    TNode<String> tmp37;
    TNode<String> tmp38;
    TNode<String> tmp39;
    ca_.Bind(&block5, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<IntPtrT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp34});
    TNode<UintPtrT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp40});
    ca_.Goto(&block9, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp39, tmp41, tmp41);
  }

  if (block9.is_used()) {
    TNode<Context> tmp42;
    TNode<String> tmp43;
    TNode<String> tmp44;
    TNode<Smi> tmp45;
    TNode<UintPtrT> tmp46;
    TNode<UintPtrT> tmp47;
    TNode<String> tmp48;
    TNode<String> tmp49;
    TNode<UintPtrT> tmp50;
    TNode<UintPtrT> tmp51;
    ca_.Bind(&block9, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<BoolT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp51}, TNode<UintPtrT>{tmp46});
    ca_.Branch(tmp52, &block7, &block8, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51);
  }

  if (block7.is_used()) {
    TNode<Context> tmp53;
    TNode<String> tmp54;
    TNode<String> tmp55;
    TNode<Smi> tmp56;
    TNode<UintPtrT> tmp57;
    TNode<UintPtrT> tmp58;
    TNode<String> tmp59;
    TNode<String> tmp60;
    TNode<UintPtrT> tmp61;
    TNode<UintPtrT> tmp62;
    ca_.Bind(&block7, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62);
    TNode<UintPtrT> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_uintptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block13, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp62, tmp63);
  }

  if (block13.is_used()) {
    TNode<Context> tmp64;
    TNode<String> tmp65;
    TNode<String> tmp66;
    TNode<Smi> tmp67;
    TNode<UintPtrT> tmp68;
    TNode<UintPtrT> tmp69;
    TNode<String> tmp70;
    TNode<String> tmp71;
    TNode<UintPtrT> tmp72;
    TNode<UintPtrT> tmp73;
    TNode<UintPtrT> tmp74;
    TNode<UintPtrT> tmp75;
    ca_.Bind(&block13, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<BoolT> tmp76;
    USE(tmp76);
    tmp76 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp74}, TNode<UintPtrT>{tmp68});
    ca_.Branch(tmp76, &block14, &block15, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76);
  }

  if (block14.is_used()) {
    TNode<Context> tmp77;
    TNode<String> tmp78;
    TNode<String> tmp79;
    TNode<Smi> tmp80;
    TNode<UintPtrT> tmp81;
    TNode<UintPtrT> tmp82;
    TNode<String> tmp83;
    TNode<String> tmp84;
    TNode<UintPtrT> tmp85;
    TNode<UintPtrT> tmp86;
    TNode<UintPtrT> tmp87;
    TNode<UintPtrT> tmp88;
    TNode<BoolT> tmp89;
    ca_.Bind(&block14, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89);
    TNode<BoolT> tmp90;
    USE(tmp90);
    tmp90 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp88}, TNode<UintPtrT>{tmp82});
    ca_.Goto(&block16, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

  if (block15.is_used()) {
    TNode<Context> tmp91;
    TNode<String> tmp92;
    TNode<String> tmp93;
    TNode<Smi> tmp94;
    TNode<UintPtrT> tmp95;
    TNode<UintPtrT> tmp96;
    TNode<String> tmp97;
    TNode<String> tmp98;
    TNode<UintPtrT> tmp99;
    TNode<UintPtrT> tmp100;
    TNode<UintPtrT> tmp101;
    TNode<UintPtrT> tmp102;
    TNode<BoolT> tmp103;
    ca_.Bind(&block15, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
    TNode<BoolT> tmp104;
    USE(tmp104);
    tmp104 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block16, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104);
  }

  if (block16.is_used()) {
    TNode<Context> tmp105;
    TNode<String> tmp106;
    TNode<String> tmp107;
    TNode<Smi> tmp108;
    TNode<UintPtrT> tmp109;
    TNode<UintPtrT> tmp110;
    TNode<String> tmp111;
    TNode<String> tmp112;
    TNode<UintPtrT> tmp113;
    TNode<UintPtrT> tmp114;
    TNode<UintPtrT> tmp115;
    TNode<UintPtrT> tmp116;
    TNode<BoolT> tmp117;
    TNode<BoolT> tmp118;
    ca_.Bind(&block16, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    ca_.Branch(tmp118, &block17, &block18, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp118);
  }

  if (block17.is_used()) {
    TNode<Context> tmp119;
    TNode<String> tmp120;
    TNode<String> tmp121;
    TNode<Smi> tmp122;
    TNode<UintPtrT> tmp123;
    TNode<UintPtrT> tmp124;
    TNode<String> tmp125;
    TNode<String> tmp126;
    TNode<UintPtrT> tmp127;
    TNode<UintPtrT> tmp128;
    TNode<UintPtrT> tmp129;
    TNode<UintPtrT> tmp130;
    TNode<BoolT> tmp131;
    ca_.Bind(&block17, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
    TNode<Int32T> tmp132;
    USE(tmp132);
    tmp132 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp125}, TNode<UintPtrT>{tmp129});
    TNode<Int32T> tmp133;
    USE(tmp133);
    tmp133 = CodeStubAssembler(state_).StringCharCodeAt(TNode<String>{tmp126}, TNode<UintPtrT>{tmp130});
    TNode<BoolT> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp132}, TNode<Int32T>{tmp133});
    ca_.Goto(&block19, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp134);
  }

  if (block18.is_used()) {
    TNode<Context> tmp135;
    TNode<String> tmp136;
    TNode<String> tmp137;
    TNode<Smi> tmp138;
    TNode<UintPtrT> tmp139;
    TNode<UintPtrT> tmp140;
    TNode<String> tmp141;
    TNode<String> tmp142;
    TNode<UintPtrT> tmp143;
    TNode<UintPtrT> tmp144;
    TNode<UintPtrT> tmp145;
    TNode<UintPtrT> tmp146;
    TNode<BoolT> tmp147;
    ca_.Bind(&block18, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147);
    TNode<BoolT> tmp148;
    USE(tmp148);
    tmp148 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block19, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148);
  }

  if (block19.is_used()) {
    TNode<Context> tmp149;
    TNode<String> tmp150;
    TNode<String> tmp151;
    TNode<Smi> tmp152;
    TNode<UintPtrT> tmp153;
    TNode<UintPtrT> tmp154;
    TNode<String> tmp155;
    TNode<String> tmp156;
    TNode<UintPtrT> tmp157;
    TNode<UintPtrT> tmp158;
    TNode<UintPtrT> tmp159;
    TNode<UintPtrT> tmp160;
    TNode<BoolT> tmp161;
    TNode<BoolT> tmp162;
    ca_.Bind(&block19, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162);
    ca_.Branch(tmp162, &block11, &block12, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160);
  }

  if (block11.is_used()) {
    TNode<Context> tmp163;
    TNode<String> tmp164;
    TNode<String> tmp165;
    TNode<Smi> tmp166;
    TNode<UintPtrT> tmp167;
    TNode<UintPtrT> tmp168;
    TNode<String> tmp169;
    TNode<String> tmp170;
    TNode<UintPtrT> tmp171;
    TNode<UintPtrT> tmp172;
    TNode<UintPtrT> tmp173;
    TNode<UintPtrT> tmp174;
    ca_.Bind(&block11, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174);
    TNode<UintPtrT> tmp175;
    USE(tmp175);
    tmp175 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp176;
    USE(tmp176);
    tmp176 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp173}, TNode<UintPtrT>{tmp175});
    TNode<UintPtrT> tmp177;
    USE(tmp177);
    tmp177 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp174}, TNode<UintPtrT>{tmp177});
    ca_.Goto(&block13, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp176, tmp178);
  }

  if (block12.is_used()) {
    TNode<Context> tmp179;
    TNode<String> tmp180;
    TNode<String> tmp181;
    TNode<Smi> tmp182;
    TNode<UintPtrT> tmp183;
    TNode<UintPtrT> tmp184;
    TNode<String> tmp185;
    TNode<String> tmp186;
    TNode<UintPtrT> tmp187;
    TNode<UintPtrT> tmp188;
    TNode<UintPtrT> tmp189;
    TNode<UintPtrT> tmp190;
    ca_.Bind(&block12, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190);
    TNode<BoolT> tmp191;
    USE(tmp191);
    tmp191 = CodeStubAssembler(state_).WordEqual(TNode<UintPtrT>{tmp190}, TNode<UintPtrT>{tmp184});
    ca_.Branch(tmp191, &block20, &block21, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190);
  }

  if (block20.is_used()) {
    TNode<Context> tmp192;
    TNode<String> tmp193;
    TNode<String> tmp194;
    TNode<Smi> tmp195;
    TNode<UintPtrT> tmp196;
    TNode<UintPtrT> tmp197;
    TNode<String> tmp198;
    TNode<String> tmp199;
    TNode<UintPtrT> tmp200;
    TNode<UintPtrT> tmp201;
    TNode<UintPtrT> tmp202;
    TNode<UintPtrT> tmp203;
    ca_.Bind(&block20, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203);
    TNode<IntPtrT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).Signed(TNode<UintPtrT>{tmp201});
    TNode<Smi> tmp205;
    USE(tmp205);
    tmp205 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp204});
    ca_.Goto(&block2, tmp192, tmp193, tmp194, tmp195, tmp205);
  }

  if (block21.is_used()) {
    TNode<Context> tmp206;
    TNode<String> tmp207;
    TNode<String> tmp208;
    TNode<Smi> tmp209;
    TNode<UintPtrT> tmp210;
    TNode<UintPtrT> tmp211;
    TNode<String> tmp212;
    TNode<String> tmp213;
    TNode<UintPtrT> tmp214;
    TNode<UintPtrT> tmp215;
    TNode<UintPtrT> tmp216;
    TNode<UintPtrT> tmp217;
    ca_.Bind(&block21, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217);
    TNode<UintPtrT> tmp218;
    USE(tmp218);
    tmp218 = FromConstexpr_uintptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp219;
    USE(tmp219);
    tmp219 = CodeStubAssembler(state_).UintPtrAdd(TNode<UintPtrT>{tmp215}, TNode<UintPtrT>{tmp218});
    ca_.Goto(&block9, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp219);
  }

  if (block8.is_used()) {
    TNode<Context> tmp220;
    TNode<String> tmp221;
    TNode<String> tmp222;
    TNode<Smi> tmp223;
    TNode<UintPtrT> tmp224;
    TNode<UintPtrT> tmp225;
    TNode<String> tmp226;
    TNode<String> tmp227;
    TNode<UintPtrT> tmp228;
    TNode<UintPtrT> tmp229;
    ca_.Bind(&block8, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229);
    TNode<Smi> tmp230;
    USE(tmp230);
    tmp230 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block2, tmp220, tmp221, tmp222, tmp223, tmp230);
  }

  if (block2.is_used()) {
    TNode<Context> tmp231;
    TNode<String> tmp232;
    TNode<String> tmp233;
    TNode<Smi> tmp234;
    TNode<Smi> tmp235;
    ca_.Bind(&block2, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235);
    ca_.Goto(&block22, tmp231, tmp232, tmp233, tmp234, tmp235);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_Slow);
  }

    TNode<Context> tmp236;
    TNode<String> tmp237;
    TNode<String> tmp238;
    TNode<Smi> tmp239;
    TNode<Smi> tmp240;
    ca_.Bind(&block22, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240);
  return TNode<Smi>{tmp240};
}

TNode<Smi> AbstractStringIndexOf_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<String> p_string, TNode<String> p_searchString, TNode<Smi> p_fromIndex) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, String, String, Smi, Context> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, String, String, Smi, Context, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, IntPtrT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, IntPtrT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, String, String, Smi, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_string, p_searchString, p_fromIndex);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<String> tmp1;
    TNode<String> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp2});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp5});
    ca_.Branch(tmp6, &block4, &block5, tmp0, tmp1, tmp2, tmp3, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<String> tmp8;
    TNode<String> tmp9;
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp10});
    TNode<IntPtrT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp8});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).IntPtrLessThanOrEqual(TNode<IntPtrT>{tmp12}, TNode<IntPtrT>{tmp13});
    ca_.Goto(&block6, tmp7, tmp8, tmp9, tmp10, tmp11, tmp14);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<String> tmp16;
    TNode<String> tmp17;
    TNode<Smi> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20);
  }

  if (block6.is_used()) {
    TNode<Context> tmp21;
    TNode<String> tmp22;
    TNode<String> tmp23;
    TNode<Smi> tmp24;
    TNode<BoolT> tmp25;
    TNode<BoolT> tmp26;
    ca_.Bind(&block6, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Branch(tmp26, &block2, &block3, tmp21, tmp22, tmp23, tmp24);
  }

  if (block2.is_used()) {
    TNode<Context> tmp27;
    TNode<String> tmp28;
    TNode<String> tmp29;
    TNode<Smi> tmp30;
    ca_.Bind(&block2, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Goto(&block1, tmp27, tmp28, tmp29, tmp30, tmp30);
  }

  if (block3.is_used()) {
    TNode<Context> tmp31;
    TNode<String> tmp32;
    TNode<String> tmp33;
    TNode<Smi> tmp34;
    ca_.Bind(&block3, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp33});
    TNode<Smi> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp34}, TNode<Smi>{tmp35});
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp32});
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp36}, TNode<Smi>{tmp37});
    ca_.Branch(tmp38, &block7, &block8, tmp31, tmp32, tmp33, tmp34);
  }

  if (block7.is_used()) {
    TNode<Context> tmp39;
    TNode<String> tmp40;
    TNode<String> tmp41;
    TNode<Smi> tmp42;
    ca_.Bind(&block7, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<Smi> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp39, tmp40, tmp41, tmp42, tmp43);
  }

  if (block8.is_used()) {
    TNode<Context> tmp44;
    TNode<String> tmp45;
    TNode<String> tmp46;
    TNode<Smi> tmp47;
    ca_.Bind(&block8, &tmp44, &tmp45, &tmp46, &tmp47);
    TNode<Smi> tmp48;
    USE(tmp48);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp48 = TryFastAbstractStringIndexOf_0(state_, TNode<Context>{tmp44}, TNode<String>{tmp45}, TNode<String>{tmp46}, TNode<Smi>{tmp47}, &label0);
    ca_.Goto(&block11, tmp44, tmp45, tmp46, tmp47, tmp45, tmp46, tmp47, tmp44, tmp48);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp44, tmp45, tmp46, tmp47, tmp45, tmp46, tmp47, tmp44);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp49;
    TNode<String> tmp50;
    TNode<String> tmp51;
    TNode<Smi> tmp52;
    TNode<String> tmp53;
    TNode<String> tmp54;
    TNode<Smi> tmp55;
    TNode<Context> tmp56;
    ca_.Bind(&block12, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<IntPtrT> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp52});
    ca_.Goto(&block15, tmp49, tmp50, tmp51, tmp52, tmp57);
  }

  if (block11.is_used()) {
    TNode<Context> tmp58;
    TNode<String> tmp59;
    TNode<String> tmp60;
    TNode<Smi> tmp61;
    TNode<String> tmp62;
    TNode<String> tmp63;
    TNode<Smi> tmp64;
    TNode<Context> tmp65;
    TNode<Smi> tmp66;
    ca_.Bind(&block11, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    ca_.Goto(&block1, tmp58, tmp59, tmp60, tmp61, tmp66);
  }

  if (block15.is_used()) {
    TNode<Context> tmp67;
    TNode<String> tmp68;
    TNode<String> tmp69;
    TNode<Smi> tmp70;
    TNode<IntPtrT> tmp71;
    ca_.Bind(&block15, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    TNode<IntPtrT> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp68});
    TNode<BoolT> tmp73;
    USE(tmp73);
    tmp73 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp71}, TNode<IntPtrT>{tmp72});
    ca_.Branch(tmp73, &block13, &block14, tmp67, tmp68, tmp69, tmp70, tmp71);
  }

  if (block13.is_used()) {
    TNode<Context> tmp74;
    TNode<String> tmp75;
    TNode<String> tmp76;
    TNode<Smi> tmp77;
    TNode<IntPtrT> tmp78;
    ca_.Bind(&block13, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<Smi> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp78});
    TNode<Number> tmp80;
    USE(tmp80);
    tmp80 = Convert_Number_Smi_0(state_, TNode<Smi>{tmp79});
    TNode<Oddball> tmp81;
    tmp81 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringCompareSequence, tmp74, tmp75, tmp76, tmp80)); 
    USE(tmp81);
    TNode<Oddball> tmp82;
    USE(tmp82);
    tmp82 = True_0(state_);
    TNode<BoolT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp81}, TNode<HeapObject>{tmp82});
    ca_.Branch(tmp83, &block17, &block18, tmp74, tmp75, tmp76, tmp77, tmp78);
  }

  if (block17.is_used()) {
    TNode<Context> tmp84;
    TNode<String> tmp85;
    TNode<String> tmp86;
    TNode<Smi> tmp87;
    TNode<IntPtrT> tmp88;
    ca_.Bind(&block17, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
    TNode<Smi> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).SmiTag(TNode<IntPtrT>{tmp88});
    ca_.Goto(&block1, tmp84, tmp85, tmp86, tmp87, tmp89);
  }

  if (block18.is_used()) {
    TNode<Context> tmp90;
    TNode<String> tmp91;
    TNode<String> tmp92;
    TNode<Smi> tmp93;
    TNode<IntPtrT> tmp94;
    ca_.Bind(&block18, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    TNode<IntPtrT> tmp95;
    USE(tmp95);
    tmp95 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp96;
    USE(tmp96);
    tmp96 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp94}, TNode<IntPtrT>{tmp95});
    ca_.Goto(&block15, tmp90, tmp91, tmp92, tmp93, tmp96);
  }

  if (block14.is_used()) {
    TNode<Context> tmp97;
    TNode<String> tmp98;
    TNode<String> tmp99;
    TNode<Smi> tmp100;
    TNode<IntPtrT> tmp101;
    ca_.Bind(&block14, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    TNode<Smi> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp97, tmp98, tmp99, tmp100, tmp102);
  }

  if (block1.is_used()) {
    TNode<Context> tmp103;
    TNode<String> tmp104;
    TNode<String> tmp105;
    TNode<Smi> tmp106;
    TNode<Smi> tmp107;
    ca_.Bind(&block1, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107);
    ca_.Goto(&block19, tmp103, tmp104, tmp105, tmp106, tmp107);
  }

    TNode<Context> tmp108;
    TNode<String> tmp109;
    TNode<String> tmp110;
    TNode<Smi> tmp111;
    TNode<Smi> tmp112;
    ca_.Bind(&block19, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112);
  return TNode<Smi>{tmp112};
}

void ThrowIfNotGlobal_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_searchValue) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT, Object, Object, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_searchValue);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSRegExp_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, ca_.Uninitialized<BoolT>(), tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, ca_.Uninitialized<BoolT>(), tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<BoolT> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Context> tmp8;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_JSAny_constexpr_string_0(state_, "flags");
    TNode<Object> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp3}, TNode<Object>{tmp4}, TNode<Object>{tmp9});
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = RequireObjectCoercible_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp10}, "String.prototype.replaceAll");
    TNode<String> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp10});
    TNode<String> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).StringConstant("g");
    TNode<Smi> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp15;
    tmp15 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringIndexOf, tmp3, tmp12, tmp13, tmp14));
    USE(tmp15);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp15}, TNode<Smi>{tmp16});
    ca_.Goto(&block2, tmp3, tmp4, tmp17, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<BoolT> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Context> tmp23;
    TNode<JSRegExp> tmp24;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = RegExpBuiltinsAssembler(state_).FastFlagGetterGlobal(TNode<JSRegExp>{tmp24});
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp25});
    ca_.Goto(&block2, tmp18, tmp19, tmp26, tmp21);
  }

  if (block2.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<BoolT> tmp29;
    TNode<Object> tmp30;
    ca_.Bind(&block2, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Branch(tmp29, &block6, &block7, tmp27, tmp28, tmp29);
  }

  if (block6.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block6, &tmp31, &tmp32, &tmp33);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp31}, MessageTemplate::kRegExpGlobalInvokedOnNonGlobal, "String.prototype.replaceAll");
  }

  if (block7.is_used()) {
    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<BoolT> tmp36;
    ca_.Bind(&block7, &tmp34, &tmp35, &tmp36);
    ca_.Goto(&block8, tmp34, tmp35);
  }

    TNode<Context> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block8, &tmp37, &tmp38);
}

TF_BUILTIN(StringPrototypeReplaceAll, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kSearchValue));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kReplaceValue));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Symbol, NativeContext> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Symbol, NativeContext, JSReceiver> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi, String> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi, String> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi, String> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, String, String, Object, BoolT, Smi, Smi, Smi, String, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = RequireObjectCoercible_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, "String.prototype.replaceAll");
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = Undefined_0(state_);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp5});
    ca_.Branch(tmp6, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp6);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<Oddball> tmp12;
    USE(tmp12);
    tmp12 = Null_0(state_);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp9}, TNode<HeapObject>{tmp12});
    ca_.Goto(&block5, tmp7, tmp8, tmp9, tmp10, tmp11, tmp13);
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block4, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block5, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19);
  }

  if (block5.is_used()) {
    TNode<NativeContext> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Object> tmp23;
    TNode<BoolT> tmp24;
    TNode<BoolT> tmp25;
    ca_.Bind(&block5, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Branch(tmp25, &block1, &block2, tmp20, tmp21, tmp22, tmp23);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block1, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = IsRegExp_0(state_, TNode<Context>{tmp26}, TNode<Object>{tmp28});
    ca_.Branch(tmp30, &block6, &block7, tmp26, tmp27, tmp28, tmp29);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block6, &tmp31, &tmp32, &tmp33, &tmp34);
    ThrowIfNotGlobal_0(state_, TNode<Context>{tmp31}, TNode<Object>{tmp33});
    ca_.Goto(&block7, tmp31, tmp32, tmp33, tmp34);
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block7, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<Symbol> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).ReplaceSymbolConstant();
    TNode<JSReceiver> tmp40;
    USE(tmp40);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp40 = GetMethod_3(state_, TNode<Context>{tmp35}, TNode<Object>{tmp37}, TNode<Symbol>{tmp39}, &label0);
    ca_.Goto(&block10, tmp35, tmp36, tmp37, tmp38, tmp37, tmp39, tmp35, tmp40);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp35, tmp36, tmp37, tmp38, tmp37, tmp39, tmp35);
    }
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<Symbol> tmp46;
    TNode<NativeContext> tmp47;
    ca_.Bind(&block11, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    ca_.Goto(&block2, tmp41, tmp42, tmp43, tmp44);
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Symbol> tmp53;
    TNode<NativeContext> tmp54;
    TNode<JSReceiver> tmp55;
    ca_.Bind(&block10, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<Object> tmp56;
    USE(tmp56);
    tmp56 = CodeStubAssembler(state_).Call(TNode<Context>{tmp48}, TNode<JSReceiver>{tmp55}, TNode<Object>{tmp50}, TNode<Object>{tmp49}, TNode<Object>{tmp51});
    CodeStubAssembler(state_).Return(tmp56);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block2, &tmp57, &tmp58, &tmp59, &tmp60);
    TNode<String> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp57}, TNode<Object>{tmp58});
    TNode<String> tmp62;
    USE(tmp62);
    tmp62 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp57}, TNode<Object>{tmp59});
    TNode<BoolT> tmp63;
    USE(tmp63);
    tmp63 = CodeStubAssembler(state_).TaggedIsCallable(TNode<Object>{tmp60});
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp63});
    ca_.Branch(tmp64, &block12, &block13, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp60, tmp63);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<String> tmp69;
    TNode<String> tmp70;
    TNode<Object> tmp71;
    TNode<BoolT> tmp72;
    ca_.Bind(&block12, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72);
    TNode<String> tmp73;
    USE(tmp73);
    tmp73 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp65}, TNode<Object>{tmp68});
    ca_.Goto(&block13, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp73, tmp72);
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp74;
    TNode<Object> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<String> tmp78;
    TNode<String> tmp79;
    TNode<Object> tmp80;
    TNode<BoolT> tmp81;
    ca_.Bind(&block13, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    TNode<Smi> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp79});
    TNode<Smi> tmp83;
    USE(tmp83);
    tmp83 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).SmiMax(TNode<Smi>{tmp83}, TNode<Smi>{tmp82});
    TNode<Smi> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<String> tmp86;
    USE(tmp86);
    tmp86 = kEmptyString_0(state_);
    TNode<Smi> tmp87;
    USE(tmp87);
    tmp87 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp88;
    USE(tmp88);
    tmp88 = AbstractStringIndexOf_0(state_, TNode<Context>{tmp74}, TNode<String>{tmp78}, TNode<String>{tmp79}, TNode<Smi>{tmp87});
    ca_.Goto(&block16, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp84, tmp85, tmp86, tmp88);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    TNode<String> tmp93;
    TNode<String> tmp94;
    TNode<Object> tmp95;
    TNode<BoolT> tmp96;
    TNode<Smi> tmp97;
    TNode<Smi> tmp98;
    TNode<Smi> tmp99;
    TNode<String> tmp100;
    TNode<Smi> tmp101;
    ca_.Bind(&block16, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    TNode<Smi> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    TNode<BoolT> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp101}, TNode<Smi>{tmp102});
    ca_.Branch(tmp103, &block14, &block15, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp104;
    TNode<Object> tmp105;
    TNode<Object> tmp106;
    TNode<Object> tmp107;
    TNode<String> tmp108;
    TNode<String> tmp109;
    TNode<Object> tmp110;
    TNode<BoolT> tmp111;
    TNode<Smi> tmp112;
    TNode<Smi> tmp113;
    TNode<Smi> tmp114;
    TNode<String> tmp115;
    TNode<Smi> tmp116;
    ca_.Bind(&block14, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    ca_.Branch(tmp111, &block17, &block18, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, ca_.Uninitialized<String>());
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp117;
    TNode<Object> tmp118;
    TNode<Object> tmp119;
    TNode<Object> tmp120;
    TNode<String> tmp121;
    TNode<String> tmp122;
    TNode<Object> tmp123;
    TNode<BoolT> tmp124;
    TNode<Smi> tmp125;
    TNode<Smi> tmp126;
    TNode<Smi> tmp127;
    TNode<String> tmp128;
    TNode<Smi> tmp129;
    TNode<String> tmp130;
    ca_.Bind(&block17, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130);
    TNode<JSReceiver> tmp131;
    USE(tmp131);
    tmp131 = UnsafeCast_Callable_0(state_, TNode<Context>{tmp117}, TNode<Object>{tmp123});
    TNode<Oddball> tmp132;
    USE(tmp132);
    tmp132 = Undefined_0(state_);
    TNode<Object> tmp133;
    USE(tmp133);
    tmp133 = CodeStubAssembler(state_).Call(TNode<Context>{tmp117}, TNode<JSReceiver>{tmp131}, TNode<Object>{tmp132}, TNode<Object>{tmp122}, TNode<Object>{tmp129}, TNode<Object>{tmp121});
    TNode<String> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp117}, TNode<Object>{tmp133});
    ca_.Goto(&block19, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp134);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp135;
    TNode<Object> tmp136;
    TNode<Object> tmp137;
    TNode<Object> tmp138;
    TNode<String> tmp139;
    TNode<String> tmp140;
    TNode<Object> tmp141;
    TNode<BoolT> tmp142;
    TNode<Smi> tmp143;
    TNode<Smi> tmp144;
    TNode<Smi> tmp145;
    TNode<String> tmp146;
    TNode<Smi> tmp147;
    TNode<String> tmp148;
    ca_.Bind(&block18, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148);
    TNode<String> tmp149;
    USE(tmp149);
    tmp149 = UnsafeCast_String_0(state_, TNode<Context>{tmp135}, TNode<Object>{tmp141});
    TNode<Smi> tmp150;
    USE(tmp150);
    tmp150 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp147}, TNode<Smi>{tmp143});
    TNode<String> tmp151;
    USE(tmp151);
    tmp151 = StringBuiltinsAssembler(state_).GetSubstitution(TNode<Context>{tmp135}, TNode<String>{tmp139}, TNode<Smi>{tmp147}, TNode<Smi>{tmp150}, TNode<String>{tmp149});
    ca_.Goto(&block19, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp151);
  }

  if (block19.is_used()) {
    TNode<NativeContext> tmp152;
    TNode<Object> tmp153;
    TNode<Object> tmp154;
    TNode<Object> tmp155;
    TNode<String> tmp156;
    TNode<String> tmp157;
    TNode<Object> tmp158;
    TNode<BoolT> tmp159;
    TNode<Smi> tmp160;
    TNode<Smi> tmp161;
    TNode<Smi> tmp162;
    TNode<String> tmp163;
    TNode<Smi> tmp164;
    TNode<String> tmp165;
    ca_.Bind(&block19, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165);
    TNode<IntPtrT> tmp166;
    USE(tmp166);
    tmp166 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp162});
    TNode<UintPtrT> tmp167;
    USE(tmp167);
    tmp167 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp166});
    TNode<IntPtrT> tmp168;
    USE(tmp168);
    tmp168 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp164});
    TNode<UintPtrT> tmp169;
    USE(tmp169);
    tmp169 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp168});
    TNode<String> tmp170;
    USE(tmp170);
    tmp170 = StringBuiltinsAssembler(state_).SubString(TNode<String>{tmp156}, TNode<UintPtrT>{tmp167}, TNode<UintPtrT>{tmp169});
    TNode<String> tmp171;
    USE(tmp171);
    tmp171 = StringAdd_0(state_, TNode<Context>{tmp152}, TNode<String>{tmp163}, TNode<String>{tmp170});
    TNode<String> tmp172;
    USE(tmp172);
    tmp172 = StringAdd_0(state_, TNode<Context>{tmp152}, TNode<String>{tmp171}, TNode<String>{tmp165});
    TNode<Smi> tmp173;
    USE(tmp173);
    tmp173 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp164}, TNode<Smi>{tmp160});
    TNode<Smi> tmp174;
    USE(tmp174);
    tmp174 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp164}, TNode<Smi>{tmp161});
    TNode<Smi> tmp175;
    USE(tmp175);
    tmp175 = AbstractStringIndexOf_0(state_, TNode<Context>{tmp152}, TNode<String>{tmp156}, TNode<String>{tmp157}, TNode<Smi>{tmp174});
    ca_.Goto(&block16, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp173, tmp172, tmp175);
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp176;
    TNode<Object> tmp177;
    TNode<Object> tmp178;
    TNode<Object> tmp179;
    TNode<String> tmp180;
    TNode<String> tmp181;
    TNode<Object> tmp182;
    TNode<BoolT> tmp183;
    TNode<Smi> tmp184;
    TNode<Smi> tmp185;
    TNode<Smi> tmp186;
    TNode<String> tmp187;
    TNode<Smi> tmp188;
    ca_.Bind(&block15, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188);
    TNode<Smi> tmp189;
    USE(tmp189);
    tmp189 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp180});
    TNode<BoolT> tmp190;
    USE(tmp190);
    tmp190 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp186}, TNode<Smi>{tmp189});
    ca_.Branch(tmp190, &block20, &block21, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188);
  }

  if (block20.is_used()) {
    TNode<NativeContext> tmp191;
    TNode<Object> tmp192;
    TNode<Object> tmp193;
    TNode<Object> tmp194;
    TNode<String> tmp195;
    TNode<String> tmp196;
    TNode<Object> tmp197;
    TNode<BoolT> tmp198;
    TNode<Smi> tmp199;
    TNode<Smi> tmp200;
    TNode<Smi> tmp201;
    TNode<String> tmp202;
    TNode<Smi> tmp203;
    ca_.Bind(&block20, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203);
    TNode<IntPtrT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp201});
    TNode<UintPtrT> tmp205;
    USE(tmp205);
    tmp205 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp204});
    TNode<IntPtrT> tmp206;
    USE(tmp206);
    tmp206 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp195});
    TNode<UintPtrT> tmp207;
    USE(tmp207);
    tmp207 = CodeStubAssembler(state_).Unsigned(TNode<IntPtrT>{tmp206});
    TNode<String> tmp208;
    USE(tmp208);
    tmp208 = StringBuiltinsAssembler(state_).SubString(TNode<String>{tmp195}, TNode<UintPtrT>{tmp205}, TNode<UintPtrT>{tmp207});
    TNode<String> tmp209;
    USE(tmp209);
    tmp209 = StringAdd_0(state_, TNode<Context>{tmp191}, TNode<String>{tmp202}, TNode<String>{tmp208});
    ca_.Goto(&block21, tmp191, tmp192, tmp193, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp209, tmp203);
  }

  if (block21.is_used()) {
    TNode<NativeContext> tmp210;
    TNode<Object> tmp211;
    TNode<Object> tmp212;
    TNode<Object> tmp213;
    TNode<String> tmp214;
    TNode<String> tmp215;
    TNode<Object> tmp216;
    TNode<BoolT> tmp217;
    TNode<Smi> tmp218;
    TNode<Smi> tmp219;
    TNode<Smi> tmp220;
    TNode<String> tmp221;
    TNode<Smi> tmp222;
    ca_.Bind(&block21, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222);
    CodeStubAssembler(state_).Return(tmp221);
  }
}

TNode<Number> Convert_Number_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Smi> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Number>{tmp2};
}

}  // namespace internal
}  // namespace v8

