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

TNode<BoolT> ElementsKindTestHelper1_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS))))) {
      ca_.Goto(&block2);
    } else {
      ca_.Goto(&block3);
    }
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  if (block1.is_used()) {
    TNode<BoolT> tmp2;
    ca_.Bind(&block1, &tmp2);
    ca_.Goto(&block5, tmp2);
  }

    TNode<BoolT> tmp3;
    ca_.Bind(&block5, &tmp3);
  return TNode<BoolT>{tmp3};
}

bool ElementsKindTestHelper2_0(compiler::CodeAssemblerState* state_, ElementsKind p_kind) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
  return ((CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT8_ELEMENTS)) || (CodeStubAssembler(state_).ElementsKindEqual(p_kind, UINT16_ELEMENTS)));
}

void LabelTestHelper1_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    ca_.Goto(label_Label1);
  }
}

void LabelTestHelper2_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label2, compiler::TypedCodeAssemblerVariable<Smi>* label_Label2_parameter_0) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    *label_Label2_parameter_0 = tmp0;
    ca_.Goto(label_Label2);
  }
}

void LabelTestHelper3_0(compiler::CodeAssemblerState* state_, compiler::CodeAssemblerLabel* label_Label3, compiler::TypedCodeAssemblerVariable<Oddball>* label_Label3_parameter_0, compiler::TypedCodeAssemblerVariable<Smi>* label_Label3_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = Null_0(state_);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    *label_Label3_parameter_1 = tmp1;
    *label_Label3_parameter_0 = tmp0;
    ca_.Goto(label_Label3);
  }
}

void TestConstexpr1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).IsFastElementsKind(PACKED_SMI_ELEMENTS)));
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>(IsFastElementsKind(PACKED_SMI_ELEMENTS))' failed", "test/torque/test-torque.tq", 35);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    ca_.Goto(&block4);
  }

    ca_.Bind(&block4);
}

void TestConstexprIf_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = ElementsKindTestHelper1_0(state_, UINT8_ELEMENTS);
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(UINT8_ELEMENTS)' failed", "test/torque/test-torque.tq", 40);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = ElementsKindTestHelper1_0(state_, UINT16_ELEMENTS);
    ca_.Branch(tmp1, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ElementsKindTestHelper1(UINT16_ELEMENTS)' failed", "test/torque/test-torque.tq", 41);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = ElementsKindTestHelper1_0(state_, UINT32_ELEMENTS);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!ElementsKindTestHelper1(UINT32_ELEMENTS)' failed", "test/torque/test-torque.tq", 42);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestConstexprReturn_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, UINT8_ELEMENTS)));
    ca_.Branch(tmp0, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>(ElementsKindTestHelper2(UINT8_ELEMENTS))' failed", "test/torque/test-torque.tq", 47);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, UINT16_ELEMENTS)));
    ca_.Branch(tmp1, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>(ElementsKindTestHelper2(UINT16_ELEMENTS))' failed", "test/torque/test-torque.tq", 48);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, (ElementsKindTestHelper2_0(state_, UINT32_ELEMENTS)));
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert '!FromConstexpr<bool>(ElementsKindTestHelper2(UINT32_ELEMENTS))' failed", "test/torque/test-torque.tq", 49);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprBoolNot((ElementsKindTestHelper2_0(state_, UINT32_ELEMENTS)))));
    ca_.Branch(tmp4, &block8, &block9);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'FromConstexpr<bool>(!ElementsKindTestHelper2(UINT32_ELEMENTS))' failed", "test/torque/test-torque.tq", 50);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    ca_.Goto(&block10);
  }

    ca_.Bind(&block10);
}

TNode<Oddball> TestGotoLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper1_0(state_, &label0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4);
    }
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = True_0(state_);
    ca_.Goto(&block5, tmp0);
  }

    TNode<Oddball> tmp1;
    ca_.Bind(&block5, &tmp1);
  return TNode<Oddball>{tmp1};
}

TNode<Oddball> TestGotoLabelWithOneParameter_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_0(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper2_0(state_, &label0, &result_0_0);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, result_0_0.value());
    }
  }

  if (block4.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block4, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block5, &block6, tmp0);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block6, &tmp3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 42' failed", "test/torque/test-torque.tq", 69);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp4;
    ca_.Bind(&block5, &tmp4);
    TNode<Oddball> tmp5;
    USE(tmp5);
    tmp5 = True_0(state_);
    ca_.Goto(&block7, tmp5);
  }

    TNode<Oddball> tmp6;
    ca_.Bind(&block7, &tmp6);
  return TNode<Oddball>{tmp6};
}

TNode<Oddball> TestGotoLabelWithTwoParameters_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::TypedCodeAssemblerVariable<Oddball> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<Smi> result_0_1(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    LabelTestHelper3_0(state_, &label0, &result_0_0, &result_0_1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, result_0_0.value(), result_0_1.value());
    }
  }

  if (block4.is_used()) {
    TNode<Oddball> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block4, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp0}, TNode<HeapObject>{tmp2});
    ca_.Branch(tmp3, &block5, &block6, tmp0, tmp1);
  }

  if (block6.is_used()) {
    TNode<Oddball> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block6, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o == Null' failed", "test/torque/test-torque.tq", 80);
  }

  if (block5.is_used()) {
    TNode<Oddball> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block5, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp7}, TNode<Smi>{tmp8});
    ca_.Branch(tmp9, &block7, &block8, tmp6, tmp7);
  }

  if (block8.is_used()) {
    TNode<Oddball> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block8, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smi == 7' failed", "test/torque/test-torque.tq", 81);
  }

  if (block7.is_used()) {
    TNode<Oddball> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block7, &tmp12, &tmp13);
    TNode<Oddball> tmp14;
    USE(tmp14);
    tmp14 = True_0(state_);
    ca_.Goto(&block9, tmp14);
  }

    TNode<Oddball> tmp15;
    ca_.Bind(&block9, &tmp15);
  return TNode<Oddball>{tmp15};
}

TF_BUILTIN(GenericBuiltinTest_JSAny_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    CodeStubAssembler(state_).Return(tmp1);
  }
}

void TestBuiltinSpecialization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2;
    tmp2 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, tmp0, tmp1);
    USE(tmp2);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Null_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    ca_.Bind(&block3, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(c, 0) == Null' failed", "test/torque/test-torque.tq", 96);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    ca_.Bind(&block2, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    tmp8 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_Smi_0, tmp6, tmp7);
    USE(tmp8);
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Null_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block4, &block5, tmp6);
  }

  if (block5.is_used()) {
    TNode<Context> tmp11;
    ca_.Bind(&block5, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<Smi>(c, 1) == Null' failed", "test/torque/test-torque.tq", 97);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    ca_.Bind(&block4, &tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Undefined_0(state_);
    TNode<Object> tmp14;
    tmp14 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, tmp12, tmp13);
    USE(tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Undefined_0(state_);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block6, &block7, tmp12);
  }

  if (block7.is_used()) {
    TNode<Context> tmp17;
    ca_.Bind(&block7, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 98);
  }

  if (block6.is_used()) {
    TNode<Context> tmp18;
    ca_.Bind(&block6, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Undefined_0(state_);
    TNode<Object> tmp20;
    tmp20 = CodeStubAssembler(state_).CallBuiltin(Builtins::kGenericBuiltinTest_JSAny_0, tmp18, tmp19);
    USE(tmp20);
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = Undefined_0(state_);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.Branch(tmp22, &block8, &block9, tmp18);
  }

  if (block9.is_used()) {
    TNode<Context> tmp23;
    ca_.Bind(&block9, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericBuiltinTest<JSAny>(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 99);
  }

  if (block8.is_used()) {
    TNode<Context> tmp24;
    ca_.Bind(&block8, &tmp24);
    ca_.Goto(&block10, tmp24);
  }

    TNode<Context> tmp25;
    ca_.Bind(&block10, &tmp25);
}

void LabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag, compiler::CodeAssemblerLabel* label_Label4, compiler::CodeAssemblerLabel* label_Label5) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    if ((p_flag)) {
      ca_.Goto(&block3);
    } else {
      ca_.Goto(&block4);
    }
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    ca_.Goto(label_Label4);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(label_Label5);
  }
}

TNode<BoolT> CallLabelTestHelper4_0(compiler::CodeAssemblerState* state_, bool p_flag) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    LabelTestHelper4_0(state_, p_flag, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7);
    }
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp0);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp1);
  }

  if (block1.is_used()) {
    TNode<BoolT> tmp2;
    ca_.Bind(&block1, &tmp2);
    ca_.Goto(&block8, tmp2);
  }

    TNode<BoolT> tmp3;
    ca_.Bind(&block8, &tmp3);
  return TNode<BoolT>{tmp3};
}

TNode<Oddball> TestPartiallyUnusedLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Oddball> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = CallLabelTestHelper4_0(state_, true);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CallLabelTestHelper4_0(state_, false);
    ca_.Branch(tmp0, &block4, &block5, tmp0, tmp1, tmp0);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp2;
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block4, &tmp2, &tmp3, &tmp4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp3});
    ca_.Goto(&block6, tmp2, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    TNode<BoolT> tmp6;
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp6, tmp7, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp10;
    TNode<BoolT> tmp11;
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13);
    ca_.Branch(tmp13, &block2, &block3, tmp10, tmp11);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    ca_.Bind(&block2, &tmp14, &tmp15);
    TNode<Oddball> tmp16;
    USE(tmp16);
    tmp16 = True_0(state_);
    ca_.Goto(&block1, tmp16);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block3, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = False_0(state_);
    ca_.Goto(&block1, tmp19);
  }

  if (block1.is_used()) {
    TNode<Oddball> tmp20;
    ca_.Bind(&block1, &tmp20);
    ca_.Goto(&block8, tmp20);
  }

    TNode<Oddball> tmp21;
    ca_.Bind(&block8, &tmp21);
  return TNode<Oddball>{tmp21};
}

TNode<Object> GenericMacroTest_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_param2);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Object>{tmp2};
}

TNode<Object> GenericMacroTestWithLabels_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_param2, compiler::CodeAssemblerLabel* label_Y) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_param2);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block3, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    ca_.Goto(label_Y);
  }

  if (block3.is_used()) {
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block5, tmp4, tmp6);
  }

    TNode<Object> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
  return TNode<Object>{tmp8};
}

void TestMacroSpecialization_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Oddball> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Oddball, Object> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Undefined_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block4, &block5, tmp0);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp5;
    ca_.Bind(&block5, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(0) == Undefined' failed", "test/torque/test-torque.tq", 157);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp6;
    ca_.Bind(&block4, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = GenericMacroTest_Smi_0(state_, TNode<Smi>{tmp7});
    TNode<Oddball> tmp9;
    USE(tmp9);
    tmp9 = Undefined_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp8}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block6, &block7, tmp6);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp11;
    ca_.Bind(&block7, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Smi>(1) == Undefined' failed", "test/torque/test-torque.tq", 158);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp12;
    ca_.Bind(&block6, &tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Null_0(state_);
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp13});
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Null_0(state_);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block8, &block9, tmp12);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp17;
    ca_.Bind(&block9, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(Null) == Null' failed", "test/torque/test-torque.tq", 159);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp18;
    ca_.Bind(&block8, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = False_0(state_);
    TNode<Object> tmp20;
    USE(tmp20);
    tmp20 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp19});
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = False_0(state_);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp20}, TNode<HeapObject>{tmp21});
    ca_.Branch(tmp22, &block10, &block11, tmp18);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block11, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(False) == False' failed", "test/torque/test-torque.tq", 160);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp24;
    ca_.Bind(&block10, &tmp24);
    TNode<Oddball> tmp25;
    USE(tmp25);
    tmp25 = True_0(state_);
    TNode<Object> tmp26;
    USE(tmp26);
    tmp26 = GenericMacroTest_Object_0(state_, TNode<Object>{tmp25});
    TNode<Oddball> tmp27;
    USE(tmp27);
    tmp27 = True_0(state_);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block12, &block13, tmp24);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp29;
    ca_.Bind(&block13, &tmp29);
    CodeStubAssembler(state_).FailAssert("Torque assert 'GenericMacroTest<Object>(True) == True' failed", "test/torque/test-torque.tq", 161);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp30;
    ca_.Bind(&block12, &tmp30);
    TNode<Smi> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp32;
    USE(tmp32);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp32 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp31}, &label0);
    ca_.Goto(&block16, tmp30, tmp32);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp30);
    }
  }

  if (block17.is_used()) {
    TNode<Smi> tmp33;
    ca_.Bind(&block17, &tmp33);
    ca_.Goto(&block3);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp34;
    TNode<Object> tmp35;
    ca_.Bind(&block16, &tmp34, &tmp35);
    TNode<Oddball> tmp36;
    USE(tmp36);
    tmp36 = Undefined_0(state_);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp35}, TNode<HeapObject>{tmp36});
    ca_.Branch(tmp37, &block14, &block15, tmp34);
  }

  if (block15.is_used()) {
    TNode<Smi> tmp38;
    ca_.Bind(&block15, &tmp38);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "test/torque/test-torque.tq", 162);
  }

  if (block14.is_used()) {
    TNode<Smi> tmp39;
    ca_.Bind(&block14, &tmp39);
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp41;
    USE(tmp41);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp41 = GenericMacroTestWithLabels_Smi_0(state_, TNode<Smi>{tmp40}, &label0);
    ca_.Goto(&block20, tmp39, tmp41);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp39);
    }
  }

  if (block21.is_used()) {
    TNode<Smi> tmp42;
    ca_.Bind(&block21, &tmp42);
    ca_.Goto(&block3);
  }

  if (block20.is_used()) {
    TNode<Smi> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block20, &tmp43, &tmp44);
    TNode<Oddball> tmp45;
    USE(tmp45);
    tmp45 = Undefined_0(state_);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp44}, TNode<HeapObject>{tmp45});
    ca_.Branch(tmp46, &block18, &block19, tmp43);
  }

  if (block19.is_used()) {
    TNode<Smi> tmp47;
    ca_.Bind(&block19, &tmp47);
    CodeStubAssembler(state_).FailAssert("Torque assert '(GenericMacroTestWithLabels<Smi>(0) otherwise Fail) == Undefined' failed", "test/torque/test-torque.tq", 163);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp48;
    ca_.Bind(&block18, &tmp48);
    TNode<Oddball> tmp49;
    USE(tmp49);
    tmp49 = False_0(state_);
    TNode<Object> tmp50;
    USE(tmp50);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp50 = GenericMacroTestWithLabels_Object_0(state_, TNode<Object>{tmp49}, &label0);
    ca_.Goto(&block24, tmp48, tmp49, tmp50);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block25, tmp48, tmp49);
    }
  }

  if (block25.is_used()) {
    TNode<Smi> tmp51;
    TNode<Oddball> tmp52;
    ca_.Bind(&block25, &tmp51, &tmp52);
    ca_.Goto(&block22, tmp51);
  }

  if (block24.is_used()) {
    TNode<Smi> tmp53;
    TNode<Oddball> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block24, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block22, tmp53);
  }

  if (block22.is_used()) {
    TNode<Smi> tmp56;
    ca_.Bind(&block22, &tmp56);
    ca_.Goto(&block26);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).Unreachable();
  }

    ca_.Bind(&block26);
}

TF_BUILTIN(TestHelperPlus1, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(TestHelperPlus2, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TNode<Oddball> TestFunctionPointers_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<Smi> tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus1)), tmp0, tmp1)); 
    USE(tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 43);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus1)));
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<BuiltinPtr> tmp6;
    ca_.Bind(&block3, &tmp5, &tmp6);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(context, 42) == 43' failed", "test/torque/test-torque.tq", 184);
  }

  if (block2.is_used()) {
    TNode<Context> tmp7;
    TNode<BuiltinPtr> tmp8;
    ca_.Bind(&block2, &tmp7, &tmp8);
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 42);
    TNode<Smi> tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(10)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus2)), tmp7, tmp9)); 
    USE(tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 44);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block4, &block5, tmp7, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kTestHelperPlus2)));
  }

  if (block5.is_used()) {
    TNode<Context> tmp13;
    TNode<BuiltinPtr> tmp14;
    ca_.Bind(&block5, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr(context, 42) == 44' failed", "test/torque/test-torque.tq", 186);
  }

  if (block4.is_used()) {
    TNode<Context> tmp15;
    TNode<BuiltinPtr> tmp16;
    ca_.Bind(&block4, &tmp15, &tmp16);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = True_0(state_);
    ca_.Goto(&block6, tmp15, tmp17);
  }

    TNode<Context> tmp18;
    TNode<Oddball> tmp19;
    ca_.Bind(&block6, &tmp18, &tmp19);
  return TNode<Oddball>{tmp19};
}

TNode<Oddball> TestVariableRedeclaration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp1, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Context> tmp2;
    ca_.Bind(&block2, &tmp2);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    ca_.Bind(&block3, &tmp4);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block4, tmp4, tmp5);
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<Int32T> tmp7;
    ca_.Bind(&block4, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(42, 0)));
    ca_.Branch(tmp8, &block6, &block7, tmp6, tmp7);
  }

  if (block6.is_used()) {
    TNode<Context> tmp9;
    TNode<Int32T> tmp10;
    ca_.Bind(&block6, &tmp9, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_int31_constexpr_int31_0(state_, 1);
    ca_.Goto(&block8, tmp9, tmp10, tmp11);
  }

  if (block7.is_used()) {
    TNode<Context> tmp12;
    TNode<Int32T> tmp13;
    ca_.Bind(&block7, &tmp12, &tmp13);
    TNode<Int32T> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_int31_constexpr_int31_0(state_, 0);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

  if (block8.is_used()) {
    TNode<Context> tmp15;
    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
    TNode<Oddball> tmp18;
    USE(tmp18);
    tmp18 = True_0(state_);
    ca_.Goto(&block10, tmp15, tmp18);
  }

    TNode<Context> tmp19;
    TNode<Oddball> tmp20;
    ca_.Bind(&block10, &tmp19, &tmp20);
  return TNode<Oddball>{tmp20};
}

TNode<Smi> TestTernaryOperator_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp3, tmp4);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp5;
    ca_.Bind(&block3, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp5, tmp6);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block4, &tmp7, &tmp8);
    ca_.Branch(tmp8, &block6, &block7, tmp7, tmp8);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block6, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp9}, TNode<Smi>{tmp11});
    ca_.Goto(&block8, tmp9, tmp10, tmp12);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block7, &tmp13, &tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_Smi_constexpr_int31_0(state_, 100);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp13}, TNode<Smi>{tmp15});
    ca_.Goto(&block8, tmp13, tmp14, tmp16);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp17;
    TNode<BoolT> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block8, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block10, tmp17, tmp19);
  }

    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block10, &tmp20, &tmp21);
  return TNode<Smi>{tmp21};
}

void TestFunctionPointerToGeneric_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BuiltinPtr, BuiltinPtr> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Object> tmp2 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), tmp0, tmp1); 
    USE(tmp2);
    TNode<Oddball> tmp3;
    USE(tmp3);
    tmp3 = Null_0(state_);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_Smi_0)), ca_.UncheckedCast<BuiltinPtr>(ca_.SmiConstant(Builtins::kGenericBuiltinTest_JSAny_0)));
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<BuiltinPtr> tmp6;
    TNode<BuiltinPtr> tmp7;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(c, 0) == Null' failed", "test/torque/test-torque.tq", 208);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<BuiltinPtr> tmp9;
    TNode<BuiltinPtr> tmp10;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Object> tmp12 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(11)).descriptor(), tmp9, tmp8, tmp11); 
    USE(tmp12);
    TNode<Oddball> tmp13;
    USE(tmp13);
    tmp13 = Null_0(state_);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp12}, TNode<HeapObject>{tmp13});
    ca_.Branch(tmp14, &block4, &block5, tmp8, tmp9, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<BuiltinPtr> tmp16;
    TNode<BuiltinPtr> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr1(c, 1) == Null' failed", "test/torque/test-torque.tq", 209);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<BuiltinPtr> tmp19;
    TNode<BuiltinPtr> tmp20;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20);
    TNode<Oddball> tmp21;
    USE(tmp21);
    tmp21 = Undefined_0(state_);
    TNode<Object> tmp22 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(4)).descriptor(), tmp20, tmp18, tmp21); 
    USE(tmp22);
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = Undefined_0(state_);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp22}, TNode<HeapObject>{tmp23});
    ca_.Branch(tmp24, &block6, &block7, tmp18, tmp19, tmp20);
  }

  if (block7.is_used()) {
    TNode<Context> tmp25;
    TNode<BuiltinPtr> tmp26;
    TNode<BuiltinPtr> tmp27;
    ca_.Bind(&block7, &tmp25, &tmp26, &tmp27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 210);
  }

  if (block6.is_used()) {
    TNode<Context> tmp28;
    TNode<BuiltinPtr> tmp29;
    TNode<BuiltinPtr> tmp30;
    ca_.Bind(&block6, &tmp28, &tmp29, &tmp30);
    TNode<Oddball> tmp31;
    USE(tmp31);
    tmp31 = Undefined_0(state_);
    TNode<Object> tmp32 = CodeStubAssembler(state_).CallBuiltinPointer(Builtins::CallableFor(ca_.isolate(),ExampleBuiltinForTorqueFunctionPointerType(4)).descriptor(), tmp30, tmp28, tmp31); 
    USE(tmp32);
    TNode<Oddball> tmp33;
    USE(tmp33);
    tmp33 = Undefined_0(state_);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp32}, TNode<HeapObject>{tmp33});
    ca_.Branch(tmp34, &block8, &block9, tmp28, tmp29, tmp30);
  }

  if (block9.is_used()) {
    TNode<Context> tmp35;
    TNode<BuiltinPtr> tmp36;
    TNode<BuiltinPtr> tmp37;
    ca_.Bind(&block9, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fptr2(c, Undefined) == Undefined' failed", "test/torque/test-torque.tq", 211);
  }

  if (block8.is_used()) {
    TNode<Context> tmp38;
    TNode<BuiltinPtr> tmp39;
    TNode<BuiltinPtr> tmp40;
    ca_.Bind(&block8, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block10, tmp38);
  }

    TNode<Context> tmp41;
    ca_.Bind(&block10, &tmp41);
}

TNode<BuiltinPtr> TestTypeAlias_0(compiler::CodeAssemblerState* state_, TNode<BuiltinPtr> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BuiltinPtr, BuiltinPtr> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<BuiltinPtr> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<BuiltinPtr> tmp1;
    TNode<BuiltinPtr> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<BuiltinPtr>{tmp2};
}

TNode<Oddball> TestUnsafeCast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Number> p_n) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Oddball> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Number, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_n);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Smi> tmp6;
    tmp6 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kTestHelperPlus1, tmp3, tmp5));
    USE(tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block4, &block5, tmp3, tmp4, tmp5);
  }

  if (block5.is_used()) {
    TNode<Context> tmp9;
    TNode<Number> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block5, &tmp9, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestHelperPlus1(context, m) == 11' failed", "test/torque/test-torque.tq", 225);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    TNode<Number> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14);
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = True_0(state_);
    ca_.Goto(&block1, tmp12, tmp13, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<Number> tmp17;
    ca_.Bind(&block3, &tmp16, &tmp17);
    TNode<Oddball> tmp18;
    USE(tmp18);
    tmp18 = False_0(state_);
    ca_.Goto(&block1, tmp16, tmp17, tmp18);
  }

  if (block1.is_used()) {
    TNode<Context> tmp19;
    TNode<Number> tmp20;
    TNode<Oddball> tmp21;
    ca_.Bind(&block1, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp19, tmp20, tmp21);
  }

    TNode<Context> tmp22;
    TNode<Number> tmp23;
    TNode<Oddball> tmp24;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24);
  return TNode<Oddball>{tmp24};
}

void TestHexLiteral_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = Convert_intptr_constexpr_int31_0(state_, 0xffff);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0x10000);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(0xffff) + 1 == 0x10000' failed", "test/torque/test-torque.tq", 233);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_constexpr_int31_0(state_, -0xffff);
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, -65535);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp5}, TNode<IntPtrT>{tmp6});
    ca_.Branch(tmp7, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Convert<intptr>(-0xffff) == -65535' failed", "test/torque/test-torque.tq", 234);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestLargeIntegerLiterals_0(compiler::CodeAssemblerState* state_, TNode<Context> p_c) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_c);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int32_0(state_, 0x40000000);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int32_0(state_, 0x7fffffff);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Context> tmp3;
    ca_.Bind(&block2, &tmp3);
}

void TestMultilineAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block4, &block5, tmp0, tmp2);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp3;
    TNode<BoolT> tmp4;
    ca_.Bind(&block4, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.Goto(&block6, tmp3, tmp4, tmp6);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block5, &tmp7, &tmp8);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block6, tmp7, tmp8, tmp9);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp10;
    TNode<BoolT> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12);
    ca_.Branch(tmp12, &block2, &block3, tmp10);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp13;
    ca_.Bind(&block3, &tmp13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'someVeryLongVariableNameThatWillCauseLineBreaks > 0 && someVeryLongVariableNameThatWillCauseLineBreaks < 10' failed", "test/torque/test-torque.tq", 246);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp14;
    ca_.Bind(&block2, &tmp14);
    ca_.Goto(&block7);
  }

    ca_.Bind(&block7);
}

void TestNewlineInString_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    CodeStubAssembler(state_).Print("Hello, World!\n");
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

int31_t kConstexprConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 5;
}

TNode<IntPtrT> kIntptrConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
return TNode<IntPtrT>{tmp0};
}

TNode<Smi> kSmiConst_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
return TNode<Smi>{tmp0};
}

void TestModuleConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Int32T> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).Int32Constant(5);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, kConstexprConst_0(state_));
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp0});
    ca_.Branch(tmp2, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kConstexprConst == Int32Constant(5)' failed", "test/torque/test-torque.tq", 262);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = kIntptrConst_0(state_);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_intptr_constexpr_int31_0(state_, 4);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp3}, TNode<IntPtrT>{tmp4});
    ca_.Branch(tmp5, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kIntptrConst == 4' failed", "test/torque/test-torque.tq", 263);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = kSmiConst_0(state_);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'kSmiConst == 3' failed", "test/torque/test-torque.tq", 264);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

void TestLocalConstBindings_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp2}, TNode<Smi>{tmp1});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp3}, TNode<Smi>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp3);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi + 1' failed", "test/torque/test-torque.tq", 273);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block2, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp10});
    ca_.Branch(tmp11, &block4, &block5, tmp9, tmp10, tmp10);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block5, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "test/torque/test-torque.tq", 275);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block4, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp16}, TNode<Smi>{tmp18});
    ca_.Branch(tmp19, &block6, &block7, tmp15, tmp16, tmp17);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == 4' failed", "test/torque/test-torque.tq", 276);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<Smi> tmp25;
    ca_.Bind(&block6, &tmp23, &tmp24, &tmp25);
    TNode<Smi> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp23}, TNode<Smi>{tmp26});
    ca_.Branch(tmp27, &block8, &block9, tmp23);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp28;
    ca_.Bind(&block9, &tmp28);
    CodeStubAssembler(state_).FailAssert("Torque assert 'xSmi == 3' failed", "test/torque/test-torque.tq", 278);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp29;
    ca_.Bind(&block8, &tmp29);
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp30}, TNode<Smi>{tmp29});
    ca_.Branch(tmp31, &block10, &block11, tmp29);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp32;
    ca_.Bind(&block11, &tmp32);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x == xSmi' failed", "test/torque/test-torque.tq", 279);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp33;
    ca_.Bind(&block10, &tmp33);
    ca_.Goto(&block12);
  }

    ca_.Bind(&block12);
}

TNode<Smi> TestStruct1_0(compiler::CodeAssemblerState* state_, TorqueStructTestStructA_0 p_i) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<FixedArray, Smi, Number, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i.indexes, p_i.i, p_i.k);

  if (block0.is_used()) {
    TNode<FixedArray> tmp0;
    TNode<Smi> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp1);
  }

    TNode<FixedArray> tmp3;
    TNode<Smi> tmp4;
    TNode<Number> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5, &tmp6);
  return TNode<Smi>{tmp6};
}

TorqueStructTestStructA_0 TestStruct2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    TNode<Number> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    ca_.Goto(&block2, tmp0, tmp2, tmp3, tmp4);
  }

    TNode<Context> tmp5;
    TNode<FixedArray> tmp6;
    TNode<Smi> tmp7;
    TNode<Number> tmp8;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7, &tmp8);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp6}, TNode<Smi>{tmp7}, TNode<Number>{tmp8}};
}

TorqueStructTestStructA_0 TestStruct3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 13);
    TNode<Number> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    TNode<FixedArray> tmp5;
    USE(tmp5);
    TNode<Smi> tmp6;
    USE(tmp6);
    TNode<Number> tmp7;
    USE(tmp7);
    std::tie(tmp5, tmp6, tmp7) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = TestStruct1_0(state_, TorqueStructTestStructA_0{TNode<FixedArray>{tmp5}, TNode<Smi>{tmp6}, TNode<Number>{tmp7}});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<FixedArray> tmp10;
    USE(tmp10);
    tmp10 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp11;
    USE(tmp11);
    tmp11 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp10});
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_Smi_constexpr_int31_0(state_, 27);
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Number_constexpr_int31_0(state_, 31);
    TNode<FixedArray> tmp14;
    USE(tmp14);
    TNode<Smi> tmp15;
    USE(tmp15);
    TNode<Number> tmp16;
    USE(tmp16);
    std::tie(tmp14, tmp15, tmp16) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block2, tmp0, tmp2, tmp8, tmp8);
  }

    TNode<Context> tmp17;
    TNode<FixedArray> tmp18;
    TNode<Smi> tmp19;
    TNode<Number> tmp20;
    ca_.Bind(&block2, &tmp17, &tmp18, &tmp19, &tmp20);
  return TorqueStructTestStructA_0{TNode<FixedArray>{tmp18}, TNode<Smi>{tmp19}, TNode<Number>{tmp20}};
}

TorqueStructTestStructC_0 TestStruct4_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, Number, FixedArray, Smi, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    std::tie(tmp1, tmp2, tmp3) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    TNode<FixedArray> tmp4;
    USE(tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    TNode<Number> tmp6;
    USE(tmp6);
    std::tie(tmp4, tmp5, tmp6) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6);
  }

    TNode<Context> tmp7;
    TNode<FixedArray> tmp8;
    TNode<Smi> tmp9;
    TNode<Number> tmp10;
    TNode<FixedArray> tmp11;
    TNode<Smi> tmp12;
    TNode<Number> tmp13;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
  return TorqueStructTestStructC_0{TorqueStructTestStructA_0{TNode<FixedArray>{tmp8}, TNode<Smi>{tmp9}, TNode<Number>{tmp10}}, TorqueStructTestStructA_0{TNode<FixedArray>{tmp11}, TNode<Smi>{tmp12}, TNode<Number>{tmp13}}};
}

void CallTestStructInLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    std::tie(tmp1, tmp2, tmp3) = TestStruct2_0(state_, TNode<Context>{tmp0}).Flatten();
    ca_.Goto(&block4, tmp0);
  }

    TNode<Context> tmp4;
    ca_.Bind(&block4, &tmp4);
}

void TestForLoop_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block41(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block40(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block54(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block51(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block56(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block59(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block61(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block62(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block63(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block64(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block60(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block66(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block65(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block69(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block70(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block71(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block72(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block73(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block75(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block74(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block80(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block81(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block82(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block84(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block83(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block76(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block87(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block85(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block86(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block89(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp6}, TNode<Smi>{tmp7});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp7}, TNode<Smi>{tmp9});
    ca_.Goto(&block4, tmp8, tmp10);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block3, &tmp11, &tmp12);
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp11}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block6, &block7, tmp11);
  }

  if (block7.is_used()) {
    TNode<Smi> tmp15;
    ca_.Bind(&block7, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 356);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp16;
    ca_.Bind(&block6, &tmp16);
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block10, tmp17, tmp18);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block10, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp20}, TNode<Smi>{tmp21});
    ca_.Branch(tmp22, &block8, &block9, tmp19, tmp20);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
    TNode<Smi> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp23}, TNode<Smi>{tmp24});
    TNode<Smi> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp24}, TNode<Smi>{tmp26});
    ca_.Goto(&block10, tmp25, tmp27);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp28;
    TNode<Smi> tmp29;
    ca_.Bind(&block9, &tmp28, &tmp29);
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp28}, TNode<Smi>{tmp30});
    ca_.Branch(tmp31, &block12, &block13, tmp28, tmp29);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp32;
    TNode<Smi> tmp33;
    ca_.Bind(&block13, &tmp32, &tmp33);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 361);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp34;
    TNode<Smi> tmp35;
    ca_.Bind(&block12, &tmp34, &tmp35);
    TNode<Smi> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block16, tmp36, tmp37);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp38;
    TNode<Smi> tmp39;
    ca_.Bind(&block16, &tmp38, &tmp39);
    TNode<Smi> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp39}, TNode<Smi>{tmp40});
    ca_.Branch(tmp41, &block14, &block15, tmp38, tmp39);
  }

  if (block14.is_used()) {
    TNode<Smi> tmp42;
    TNode<Smi> tmp43;
    ca_.Bind(&block14, &tmp42, &tmp43);
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp43}, TNode<Smi>{tmp44});
    TNode<Smi> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp42}, TNode<Smi>{tmp43});
    ca_.Goto(&block16, tmp46, tmp45);
  }

  if (block15.is_used()) {
    TNode<Smi> tmp47;
    TNode<Smi> tmp48;
    ca_.Bind(&block15, &tmp47, &tmp48);
    TNode<Smi> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp47}, TNode<Smi>{tmp49});
    ca_.Branch(tmp50, &block17, &block18, tmp47, tmp48);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp51;
    TNode<Smi> tmp52;
    ca_.Bind(&block18, &tmp51, &tmp52);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 366);
  }

  if (block17.is_used()) {
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    ca_.Bind(&block17, &tmp53, &tmp54);
    TNode<Smi> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block21, tmp55, tmp54, tmp56);
  }

  if (block21.is_used()) {
    TNode<Smi> tmp57;
    TNode<Smi> tmp58;
    TNode<Smi> tmp59;
    ca_.Bind(&block21, &tmp57, &tmp58, &tmp59);
    TNode<Smi> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp59}, TNode<Smi>{tmp60});
    ca_.Branch(tmp61, &block23, &block24, tmp57, tmp58, tmp59);
  }

  if (block23.is_used()) {
    TNode<Smi> tmp62;
    TNode<Smi> tmp63;
    TNode<Smi> tmp64;
    ca_.Bind(&block23, &tmp62, &tmp63, &tmp64);
    TNode<Smi> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp62}, TNode<Smi>{tmp65});
    ca_.Branch(tmp66, &block25, &block26, tmp62, tmp63);
  }

  if (block24.is_used()) {
    TNode<Smi> tmp67;
    TNode<Smi> tmp68;
    TNode<Smi> tmp69;
    ca_.Bind(&block24, &tmp67, &tmp68, &tmp69);
    TNode<Smi> tmp70;
    USE(tmp70);
    tmp70 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp67}, TNode<Smi>{tmp69});
    TNode<Smi> tmp71;
    USE(tmp71);
    tmp71 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp72;
    USE(tmp72);
    tmp72 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp69}, TNode<Smi>{tmp71});
    ca_.Goto(&block21, tmp70, tmp68, tmp72);
  }

  if (block26.is_used()) {
    TNode<Smi> tmp73;
    TNode<Smi> tmp74;
    ca_.Bind(&block26, &tmp73, &tmp74);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 374);
  }

  if (block25.is_used()) {
    TNode<Smi> tmp75;
    TNode<Smi> tmp76;
    ca_.Bind(&block25, &tmp75, &tmp76);
    TNode<Smi> tmp77;
    USE(tmp77);
    tmp77 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp78;
    USE(tmp78);
    tmp78 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block29, tmp77, tmp78);
  }

  if (block29.is_used()) {
    TNode<Smi> tmp79;
    TNode<Smi> tmp80;
    ca_.Bind(&block29, &tmp79, &tmp80);
    TNode<Smi> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp80}, TNode<Smi>{tmp81});
    ca_.Branch(tmp82, &block30, &block31, tmp79, tmp80);
  }

  if (block30.is_used()) {
    TNode<Smi> tmp83;
    TNode<Smi> tmp84;
    ca_.Bind(&block30, &tmp83, &tmp84);
    TNode<Smi> tmp85;
    USE(tmp85);
    tmp85 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp83}, TNode<Smi>{tmp85});
    ca_.Branch(tmp86, &block32, &block33, tmp83, tmp84);
  }

  if (block31.is_used()) {
    TNode<Smi> tmp87;
    TNode<Smi> tmp88;
    ca_.Bind(&block31, &tmp87, &tmp88);
    TNode<Smi> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp87}, TNode<Smi>{tmp88});
    TNode<Smi> tmp90;
    USE(tmp90);
    tmp90 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp88}, TNode<Smi>{tmp90});
    ca_.Goto(&block29, tmp89, tmp91);
  }

  if (block33.is_used()) {
    TNode<Smi> tmp92;
    TNode<Smi> tmp93;
    ca_.Bind(&block33, &tmp92, &tmp93);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 10' failed", "test/torque/test-torque.tq", 383);
  }

  if (block32.is_used()) {
    TNode<Smi> tmp94;
    TNode<Smi> tmp95;
    ca_.Bind(&block32, &tmp94, &tmp95);
    TNode<Smi> tmp96;
    USE(tmp96);
    tmp96 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp97;
    USE(tmp97);
    tmp97 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block36, tmp96, tmp95, tmp97);
  }

  if (block36.is_used()) {
    TNode<Smi> tmp98;
    TNode<Smi> tmp99;
    TNode<Smi> tmp100;
    ca_.Bind(&block36, &tmp98, &tmp99, &tmp100);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp102;
    USE(tmp102);
    tmp102 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp100}, TNode<Smi>{tmp101});
    ca_.Branch(tmp102, &block34, &block35, tmp98, tmp99, tmp100);
  }

  if (block34.is_used()) {
    TNode<Smi> tmp103;
    TNode<Smi> tmp104;
    TNode<Smi> tmp105;
    ca_.Bind(&block34, &tmp103, &tmp104, &tmp105);
    TNode<Smi> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp107;
    USE(tmp107);
    tmp107 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp105}, TNode<Smi>{tmp106});
    ca_.Branch(tmp107, &block38, &block39, tmp103, tmp104, tmp105);
  }

  if (block38.is_used()) {
    TNode<Smi> tmp108;
    TNode<Smi> tmp109;
    TNode<Smi> tmp110;
    ca_.Bind(&block38, &tmp108, &tmp109, &tmp110);
    ca_.Goto(&block37, tmp108, tmp109, tmp110);
  }

  if (block39.is_used()) {
    TNode<Smi> tmp111;
    TNode<Smi> tmp112;
    TNode<Smi> tmp113;
    ca_.Bind(&block39, &tmp111, &tmp112, &tmp113);
    TNode<Smi> tmp114;
    USE(tmp114);
    tmp114 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp111}, TNode<Smi>{tmp113});
    ca_.Goto(&block37, tmp114, tmp112, tmp113);
  }

  if (block37.is_used()) {
    TNode<Smi> tmp115;
    TNode<Smi> tmp116;
    TNode<Smi> tmp117;
    ca_.Bind(&block37, &tmp115, &tmp116, &tmp117);
    TNode<Smi> tmp118;
    USE(tmp118);
    tmp118 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp117}, TNode<Smi>{tmp118});
    ca_.Goto(&block36, tmp115, tmp116, tmp119);
  }

  if (block35.is_used()) {
    TNode<Smi> tmp120;
    TNode<Smi> tmp121;
    TNode<Smi> tmp122;
    ca_.Bind(&block35, &tmp120, &tmp121, &tmp122);
    TNode<Smi> tmp123;
    USE(tmp123);
    tmp123 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp120}, TNode<Smi>{tmp123});
    ca_.Branch(tmp124, &block40, &block41, tmp120, tmp121);
  }

  if (block41.is_used()) {
    TNode<Smi> tmp125;
    TNode<Smi> tmp126;
    ca_.Bind(&block41, &tmp125, &tmp126);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 392);
  }

  if (block40.is_used()) {
    TNode<Smi> tmp127;
    TNode<Smi> tmp128;
    ca_.Bind(&block40, &tmp127, &tmp128);
    TNode<Smi> tmp129;
    USE(tmp129);
    tmp129 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp130;
    USE(tmp130);
    tmp130 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block44, tmp129, tmp130);
  }

  if (block44.is_used()) {
    TNode<Smi> tmp131;
    TNode<Smi> tmp132;
    ca_.Bind(&block44, &tmp131, &tmp132);
    TNode<Smi> tmp133;
    USE(tmp133);
    tmp133 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp134;
    USE(tmp134);
    tmp134 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp132}, TNode<Smi>{tmp133});
    ca_.Branch(tmp134, &block42, &block43, tmp131, tmp132);
  }

  if (block42.is_used()) {
    TNode<Smi> tmp135;
    TNode<Smi> tmp136;
    ca_.Bind(&block42, &tmp135, &tmp136);
    TNode<Smi> tmp137;
    USE(tmp137);
    tmp137 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp138;
    USE(tmp138);
    tmp138 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp136}, TNode<Smi>{tmp137});
    ca_.Branch(tmp138, &block46, &block47, tmp135, tmp136);
  }

  if (block46.is_used()) {
    TNode<Smi> tmp139;
    TNode<Smi> tmp140;
    ca_.Bind(&block46, &tmp139, &tmp140);
    ca_.Goto(&block45, tmp139, tmp140);
  }

  if (block47.is_used()) {
    TNode<Smi> tmp141;
    TNode<Smi> tmp142;
    ca_.Bind(&block47, &tmp141, &tmp142);
    TNode<Smi> tmp143;
    USE(tmp143);
    tmp143 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp141}, TNode<Smi>{tmp142});
    ca_.Goto(&block45, tmp143, tmp142);
  }

  if (block45.is_used()) {
    TNode<Smi> tmp144;
    TNode<Smi> tmp145;
    ca_.Bind(&block45, &tmp144, &tmp145);
    TNode<Smi> tmp146;
    USE(tmp146);
    tmp146 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp147;
    USE(tmp147);
    tmp147 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp145}, TNode<Smi>{tmp146});
    ca_.Goto(&block44, tmp144, tmp147);
  }

  if (block43.is_used()) {
    TNode<Smi> tmp148;
    TNode<Smi> tmp149;
    ca_.Bind(&block43, &tmp148, &tmp149);
    TNode<Smi> tmp150;
    USE(tmp150);
    tmp150 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp151;
    USE(tmp151);
    tmp151 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp148}, TNode<Smi>{tmp150});
    ca_.Branch(tmp151, &block48, &block49, tmp148, tmp149);
  }

  if (block49.is_used()) {
    TNode<Smi> tmp152;
    TNode<Smi> tmp153;
    ca_.Bind(&block49, &tmp152, &tmp153);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 400);
  }

  if (block48.is_used()) {
    TNode<Smi> tmp154;
    TNode<Smi> tmp155;
    ca_.Bind(&block48, &tmp154, &tmp155);
    TNode<Smi> tmp156;
    USE(tmp156);
    tmp156 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp157;
    USE(tmp157);
    tmp157 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block52, tmp156, tmp157);
  }

  if (block52.is_used()) {
    TNode<Smi> tmp158;
    TNode<Smi> tmp159;
    ca_.Bind(&block52, &tmp158, &tmp159);
    TNode<Smi> tmp160;
    USE(tmp160);
    tmp160 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp161;
    USE(tmp161);
    tmp161 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp159}, TNode<Smi>{tmp160});
    ca_.Branch(tmp161, &block50, &block51, tmp158, tmp159);
  }

  if (block50.is_used()) {
    TNode<Smi> tmp162;
    TNode<Smi> tmp163;
    ca_.Bind(&block50, &tmp162, &tmp163);
    TNode<Smi> tmp164;
    USE(tmp164);
    tmp164 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp165;
    USE(tmp165);
    tmp165 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp163}, TNode<Smi>{tmp164});
    ca_.Branch(tmp165, &block53, &block54, tmp162, tmp163);
  }

  if (block53.is_used()) {
    TNode<Smi> tmp166;
    TNode<Smi> tmp167;
    ca_.Bind(&block53, &tmp166, &tmp167);
    TNode<Smi> tmp168;
    USE(tmp168);
    tmp168 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp169;
    USE(tmp169);
    tmp169 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp167}, TNode<Smi>{tmp168});
    ca_.Goto(&block52, tmp166, tmp169);
  }

  if (block54.is_used()) {
    TNode<Smi> tmp170;
    TNode<Smi> tmp171;
    ca_.Bind(&block54, &tmp170, &tmp171);
    TNode<Smi> tmp172;
    USE(tmp172);
    tmp172 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp170}, TNode<Smi>{tmp171});
    TNode<Smi> tmp173;
    USE(tmp173);
    tmp173 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp174;
    USE(tmp174);
    tmp174 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp171}, TNode<Smi>{tmp173});
    ca_.Goto(&block52, tmp172, tmp174);
  }

  if (block51.is_used()) {
    TNode<Smi> tmp175;
    TNode<Smi> tmp176;
    ca_.Bind(&block51, &tmp175, &tmp176);
    TNode<Smi> tmp177;
    USE(tmp177);
    tmp177 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp175}, TNode<Smi>{tmp177});
    ca_.Branch(tmp178, &block55, &block56, tmp175, tmp176);
  }

  if (block56.is_used()) {
    TNode<Smi> tmp179;
    TNode<Smi> tmp180;
    ca_.Bind(&block56, &tmp179, &tmp180);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 412);
  }

  if (block55.is_used()) {
    TNode<Smi> tmp181;
    TNode<Smi> tmp182;
    ca_.Bind(&block55, &tmp181, &tmp182);
    TNode<Smi> tmp183;
    USE(tmp183);
    tmp183 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp184;
    USE(tmp184);
    tmp184 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block59, tmp183, tmp182, tmp184);
  }

  if (block59.is_used()) {
    TNode<Smi> tmp185;
    TNode<Smi> tmp186;
    TNode<Smi> tmp187;
    ca_.Bind(&block59, &tmp185, &tmp186, &tmp187);
    TNode<Smi> tmp188;
    USE(tmp188);
    tmp188 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp189;
    USE(tmp189);
    tmp189 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp187}, TNode<Smi>{tmp188});
    ca_.Branch(tmp189, &block61, &block62, tmp185, tmp186, tmp187);
  }

  if (block61.is_used()) {
    TNode<Smi> tmp190;
    TNode<Smi> tmp191;
    TNode<Smi> tmp192;
    ca_.Bind(&block61, &tmp190, &tmp191, &tmp192);
    ca_.Goto(&block60, tmp190, tmp191, tmp192);
  }

  if (block62.is_used()) {
    TNode<Smi> tmp193;
    TNode<Smi> tmp194;
    TNode<Smi> tmp195;
    ca_.Bind(&block62, &tmp193, &tmp194, &tmp195);
    TNode<Smi> tmp196;
    USE(tmp196);
    tmp196 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp197;
    USE(tmp197);
    tmp197 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp195}, TNode<Smi>{tmp196});
    ca_.Branch(tmp197, &block63, &block64, tmp193, tmp194, tmp195);
  }

  if (block63.is_used()) {
    TNode<Smi> tmp198;
    TNode<Smi> tmp199;
    TNode<Smi> tmp200;
    ca_.Bind(&block63, &tmp198, &tmp199, &tmp200);
    TNode<Smi> tmp201;
    USE(tmp201);
    tmp201 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp202;
    USE(tmp202);
    tmp202 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp198}, TNode<Smi>{tmp201});
    ca_.Branch(tmp202, &block65, &block66, tmp198, tmp199);
  }

  if (block64.is_used()) {
    TNode<Smi> tmp203;
    TNode<Smi> tmp204;
    TNode<Smi> tmp205;
    ca_.Bind(&block64, &tmp203, &tmp204, &tmp205);
    TNode<Smi> tmp206;
    USE(tmp206);
    tmp206 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp203}, TNode<Smi>{tmp205});
    ca_.Goto(&block60, tmp206, tmp204, tmp205);
  }

  if (block60.is_used()) {
    TNode<Smi> tmp207;
    TNode<Smi> tmp208;
    TNode<Smi> tmp209;
    ca_.Bind(&block60, &tmp207, &tmp208, &tmp209);
    TNode<Smi> tmp210;
    USE(tmp210);
    tmp210 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp211;
    USE(tmp211);
    tmp211 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp209}, TNode<Smi>{tmp210});
    ca_.Goto(&block59, tmp207, tmp208, tmp211);
  }

  if (block66.is_used()) {
    TNode<Smi> tmp212;
    TNode<Smi> tmp213;
    ca_.Bind(&block66, &tmp212, &tmp213);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 420);
  }

  if (block65.is_used()) {
    TNode<Smi> tmp214;
    TNode<Smi> tmp215;
    ca_.Bind(&block65, &tmp214, &tmp215);
    TNode<Smi> tmp216;
    USE(tmp216);
    tmp216 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp217;
    USE(tmp217);
    tmp217 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block69, tmp216, tmp217);
  }

  if (block69.is_used()) {
    TNode<Smi> tmp218;
    TNode<Smi> tmp219;
    ca_.Bind(&block69, &tmp218, &tmp219);
    TNode<Smi> tmp220;
    USE(tmp220);
    tmp220 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp221;
    USE(tmp221);
    tmp221 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp219}, TNode<Smi>{tmp220});
    ca_.Branch(tmp221, &block70, &block71, tmp218, tmp219);
  }

  if (block70.is_used()) {
    TNode<Smi> tmp222;
    TNode<Smi> tmp223;
    ca_.Bind(&block70, &tmp222, &tmp223);
    TNode<Smi> tmp224;
    USE(tmp224);
    tmp224 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp225;
    USE(tmp225);
    tmp225 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp223}, TNode<Smi>{tmp224});
    ca_.Goto(&block69, tmp222, tmp225);
  }

  if (block71.is_used()) {
    TNode<Smi> tmp226;
    TNode<Smi> tmp227;
    ca_.Bind(&block71, &tmp226, &tmp227);
    TNode<Smi> tmp228;
    USE(tmp228);
    tmp228 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp229;
    USE(tmp229);
    tmp229 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp227}, TNode<Smi>{tmp228});
    ca_.Branch(tmp229, &block72, &block73, tmp226, tmp227);
  }

  if (block72.is_used()) {
    TNode<Smi> tmp230;
    TNode<Smi> tmp231;
    ca_.Bind(&block72, &tmp230, &tmp231);
    TNode<Smi> tmp232;
    USE(tmp232);
    tmp232 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp233;
    USE(tmp233);
    tmp233 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp230}, TNode<Smi>{tmp232});
    ca_.Branch(tmp233, &block74, &block75, tmp230, tmp231);
  }

  if (block73.is_used()) {
    TNode<Smi> tmp234;
    TNode<Smi> tmp235;
    ca_.Bind(&block73, &tmp234, &tmp235);
    TNode<Smi> tmp236;
    USE(tmp236);
    tmp236 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp234}, TNode<Smi>{tmp235});
    TNode<Smi> tmp237;
    USE(tmp237);
    tmp237 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp238;
    USE(tmp238);
    tmp238 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp235}, TNode<Smi>{tmp237});
    ca_.Goto(&block69, tmp236, tmp238);
  }

  if (block75.is_used()) {
    TNode<Smi> tmp239;
    TNode<Smi> tmp240;
    ca_.Bind(&block75, &tmp239, &tmp240);
    CodeStubAssembler(state_).FailAssert("Torque assert 'sum == 7' failed", "test/torque/test-torque.tq", 434);
  }

  if (block74.is_used()) {
    TNode<Smi> tmp241;
    TNode<Smi> tmp242;
    ca_.Bind(&block74, &tmp241, &tmp242);
    TNode<Smi> tmp243;
    USE(tmp243);
    tmp243 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block80, tmp241, tmp243);
  }

  if (block80.is_used()) {
    TNode<Smi> tmp244;
    TNode<Smi> tmp245;
    ca_.Bind(&block80, &tmp244, &tmp245);
    TNode<Smi> tmp246;
    USE(tmp246);
    tmp246 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp247;
    USE(tmp247);
    tmp247 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp245}, TNode<Smi>{tmp246});
    TNode<Smi> tmp248;
    USE(tmp248);
    tmp248 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp249;
    USE(tmp249);
    tmp249 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp247}, TNode<Smi>{tmp248});
    ca_.Branch(tmp249, &block81, &block82, tmp244, tmp247);
  }

  if (block81.is_used()) {
    TNode<Smi> tmp250;
    TNode<Smi> tmp251;
    ca_.Bind(&block81, &tmp250, &tmp251);
    TNode<Smi> tmp252;
    USE(tmp252);
    tmp252 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp253;
    USE(tmp253);
    tmp253 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp251}, TNode<Smi>{tmp252});
    ca_.Branch(tmp253, &block83, &block84, tmp250, tmp251);
  }

  if (block82.is_used()) {
    TNode<Smi> tmp254;
    TNode<Smi> tmp255;
    ca_.Bind(&block82, &tmp254, &tmp255);
    ca_.Goto(&block80, tmp254, tmp255);
  }

  if (block84.is_used()) {
    TNode<Smi> tmp256;
    TNode<Smi> tmp257;
    ca_.Bind(&block84, &tmp256, &tmp257);
    CodeStubAssembler(state_).FailAssert("Torque assert 'j == 10' failed", "test/torque/test-torque.tq", 443);
  }

  if (block83.is_used()) {
    TNode<Smi> tmp258;
    TNode<Smi> tmp259;
    ca_.Bind(&block83, &tmp258, &tmp259);
    ca_.Goto(&block76, tmp258, tmp259);
  }

  if (block76.is_used()) {
    TNode<Smi> tmp260;
    TNode<Smi> tmp261;
    ca_.Bind(&block76, &tmp260, &tmp261);
    TNode<Smi> tmp262;
    USE(tmp262);
    tmp262 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block87, tmp260, tmp261, ca_.Uninitialized<Smi>(), tmp262);
  }

  if (block87.is_used()) {
    TNode<Smi> tmp263;
    TNode<Smi> tmp264;
    TNode<Smi> tmp265;
    TNode<Smi> tmp266;
    ca_.Bind(&block87, &tmp263, &tmp264, &tmp265, &tmp266);
    TNode<Smi> tmp267;
    USE(tmp267);
    tmp267 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp268;
    USE(tmp268);
    tmp268 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp266}, TNode<Smi>{tmp267});
    ca_.Branch(tmp268, &block85, &block86, tmp263, tmp264, tmp265, tmp266);
  }

  if (block85.is_used()) {
    TNode<Smi> tmp269;
    TNode<Smi> tmp270;
    TNode<Smi> tmp271;
    TNode<Smi> tmp272;
    ca_.Bind(&block85, &tmp269, &tmp270, &tmp271, &tmp272);
    TNode<Smi> tmp273;
    USE(tmp273);
    tmp273 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp272}, TNode<Smi>{tmp273});
    ca_.Goto(&block87, tmp269, tmp270, tmp271, tmp274);
  }

  if (block86.is_used()) {
    TNode<Smi> tmp275;
    TNode<Smi> tmp276;
    TNode<Smi> tmp277;
    TNode<Smi> tmp278;
    ca_.Bind(&block86, &tmp275, &tmp276, &tmp277, &tmp278);
    ca_.Goto(&block89);
  }

    ca_.Bind(&block89);
}

void TestSubtyping_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0);
  }

    TNode<Smi> tmp1;
    ca_.Bind(&block2, &tmp1);
}

TNode<Int32T> TypeswitchExample_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Context, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, Object, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object, HeapObject, FixedArray> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_x);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{tmp1});
    TNode<FixedArray> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_FixedArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp3, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    TNode<Int32T> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block5, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<Int32T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<Int32T> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp7}, TNode<Int32T>{tmp11});
    ca_.Goto(&block2, tmp5, tmp6, tmp12, tmp8);
  }

  if (block4.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Int32T> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Context> tmp18;
    TNode<FixedArray> tmp19;
    ca_.Bind(&block4, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    TNode<Int32T> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp15}, TNode<Int32T>{tmp20});
    ca_.Goto(&block2, tmp13, tmp14, tmp21, tmp16);
  }

  if (block2.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<Int32T> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block2, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Int32T> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_int32_constexpr_int31_0(state_, 10);
    TNode<Int32T> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).Int32Mul(TNode<Int32T>{tmp24}, TNode<Int32T>{tmp26});
    TNode<Object> tmp28;
    USE(tmp28);
    tmp28 = IncrementIfSmi_NumberOrFixedArray_0(state_, TNode<Object>{tmp23});
    TNode<Smi> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = Cast_Smi_0(state_, TNode<Object>{tmp28}, &label0);
    ca_.Goto(&block8, tmp22, tmp23, tmp27, tmp28, tmp28, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp22, tmp23, tmp27, tmp28, tmp28);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp30;
    TNode<Object> tmp31;
    TNode<Int32T> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block9, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<FixedArray> tmp35;
    USE(tmp35);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp35 = Cast_FixedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp33)}, &label0);
    ca_.Goto(&block12, tmp30, tmp31, tmp32, tmp33, ca_.UncheckedCast<HeapObject>(tmp33), tmp35);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp30, tmp31, tmp32, tmp33, ca_.UncheckedCast<HeapObject>(tmp33));
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    TNode<Int32T> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    TNode<Smi> tmp41;
    ca_.Bind(&block8, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    TNode<Int32T> tmp42;
    USE(tmp42);
    tmp42 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp41});
    TNode<Int32T> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp38}, TNode<Int32T>{tmp42});
    ca_.Goto(&block6, tmp36, tmp37, tmp43, tmp39);
  }

  if (block13.is_used()) {
    TNode<Context> tmp44;
    TNode<Object> tmp45;
    TNode<Int32T> tmp46;
    TNode<Object> tmp47;
    TNode<HeapObject> tmp48;
    ca_.Bind(&block13, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48);
    TNode<Int32T> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<Int32T> tmp50;
    USE(tmp50);
    tmp50 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp46}, TNode<Int32T>{tmp49});
    ca_.Goto(&block10, tmp44, tmp45, tmp50, tmp47);
  }

  if (block12.is_used()) {
    TNode<Context> tmp51;
    TNode<Object> tmp52;
    TNode<Int32T> tmp53;
    TNode<Object> tmp54;
    TNode<HeapObject> tmp55;
    TNode<FixedArray> tmp56;
    ca_.Bind(&block12, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56);
    TNode<IntPtrT> tmp57 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp57);
    TNode<Smi>tmp58 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp56, tmp57});
    TNode<Int32T> tmp59;
    USE(tmp59);
    tmp59 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp58});
    TNode<Int32T> tmp60;
    USE(tmp60);
    tmp60 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp53}, TNode<Int32T>{tmp59});
    ca_.Goto(&block10, tmp51, tmp52, tmp60, tmp54);
  }

  if (block10.is_used()) {
    TNode<Context> tmp61;
    TNode<Object> tmp62;
    TNode<Int32T> tmp63;
    TNode<Object> tmp64;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64);
    ca_.Goto(&block6, tmp61, tmp62, tmp63, tmp64);
  }

  if (block6.is_used()) {
    TNode<Context> tmp65;
    TNode<Object> tmp66;
    TNode<Int32T> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block6, &tmp65, &tmp66, &tmp67, &tmp68);
    ca_.Goto(&block14, tmp65, tmp66, tmp67);
  }

    TNode<Context> tmp69;
    TNode<Object> tmp70;
    TNode<Int32T> tmp71;
    ca_.Bind(&block14, &tmp69, &tmp70, &tmp71);
  return TNode<Int32T>{tmp71};
}

void TestTypeswitch_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = TypeswitchExample_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 26);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp2}, TNode<Int32T>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    ca_.Bind(&block3, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Smi>(5)) == 26' failed", "test/torque/test-torque.tq", 500);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    ca_.Bind(&block2, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<FixedArray> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp7});
    TNode<Int32T> tmp9;
    USE(tmp9);
    tmp9 = TypeswitchExample_0(state_, TNode<Context>{tmp6}, TNode<Object>{tmp8});
    TNode<Int32T> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_int32_constexpr_int31_0(state_, 13);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp9}, TNode<Int32T>{tmp10});
    ca_.Branch(tmp11, &block4, &block5, tmp6, tmp8);
  }

  if (block5.is_used()) {
    TNode<Context> tmp12;
    TNode<FixedArray> tmp13;
    ca_.Bind(&block5, &tmp12, &tmp13);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(a) == 13' failed", "test/torque/test-torque.tq", 502);
  }

  if (block4.is_used()) {
    TNode<Context> tmp14;
    TNode<FixedArray> tmp15;
    ca_.Bind(&block4, &tmp14, &tmp15);
    TNode<Number> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_Number_constexpr_float64_0(state_, 0.5);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = TypeswitchExample_0(state_, TNode<Context>{tmp14}, TNode<Object>{tmp16});
    TNode<Int32T> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_int32_constexpr_int31_0(state_, 27);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp17}, TNode<Int32T>{tmp18});
    ca_.Branch(tmp19, &block6, &block7, tmp14, tmp15);
  }

  if (block7.is_used()) {
    TNode<Context> tmp20;
    TNode<FixedArray> tmp21;
    ca_.Bind(&block7, &tmp20, &tmp21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TypeswitchExample(FromConstexpr<Number>(0.5)) == 27' failed", "test/torque/test-torque.tq", 503);
  }

  if (block6.is_used()) {
    TNode<Context> tmp22;
    TNode<FixedArray> tmp23;
    ca_.Bind(&block6, &tmp22, &tmp23);
    ca_.Goto(&block8, tmp22);
  }

    TNode<Context> tmp24;
    ca_.Bind(&block8, &tmp24);
}

void TestTypeswitchAsanLsanFailure_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject, JSTypedArray> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject, JSReceiver> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_obj);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_Smi_0(state_, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<JSTypedArray> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = Cast_JSTypedArray_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp5)}, &label0);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5), tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp3, tmp4, tmp5, ca_.UncheckedCast<HeapObject>(tmp5));
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block4, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block2, tmp8, tmp9, tmp10);
  }

  if (block9.is_used()) {
    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<JSReceiver> tmp17;
    USE(tmp17);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp17 = Cast_JSReceiver_0(state_, TNode<HeapObject>{ca_.UncheckedCast<HeapObject>(tmp15)}, &label0);
    ca_.Goto(&block12, tmp13, tmp14, tmp15, ca_.UncheckedCast<HeapObject>(tmp15), tmp17);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block13, tmp13, tmp14, tmp15, ca_.UncheckedCast<HeapObject>(tmp15));
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<HeapObject> tmp21;
    TNode<JSTypedArray> tmp22;
    ca_.Bind(&block8, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22);
    ca_.Goto(&block6, tmp18, tmp19, tmp20);
  }

  if (block13.is_used()) {
    TNode<Context> tmp23;
    TNode<Object> tmp24;
    TNode<Object> tmp25;
    TNode<HeapObject> tmp26;
    ca_.Bind(&block13, &tmp23, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block10, tmp23, tmp24, tmp25);
  }

  if (block12.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<HeapObject> tmp30;
    TNode<JSReceiver> tmp31;
    ca_.Bind(&block12, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    ca_.Goto(&block10, tmp27, tmp28, tmp29);
  }

  if (block10.is_used()) {
    TNode<Context> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block10, &tmp32, &tmp33, &tmp34);
    ca_.Goto(&block6, tmp32, tmp33, tmp34);
  }

  if (block6.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    ca_.Bind(&block6, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block2, tmp35, tmp36, tmp37);
  }

  if (block2.is_used()) {
    TNode<Context> tmp38;
    TNode<Object> tmp39;
    TNode<Object> tmp40;
    ca_.Bind(&block2, &tmp38, &tmp39, &tmp40);
    ca_.Goto(&block14, tmp38, tmp39);
  }

    TNode<Context> tmp41;
    TNode<Object> tmp42;
    ca_.Bind(&block14, &tmp41, &tmp42);
}

void TestGenericOverload_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = ExampleGenericOverload_Smi_0(state_, TNode<Smi>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp2}, TNode<Smi>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<Smi> tmp6;
    TNode<Object> tmp7;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'ExampleGenericOverload<Smi>(xSmi) == 6' failed", "test/torque/test-torque.tq", 531);
  }

  if (block2.is_used()) {
    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block2, &tmp8, &tmp9, &tmp10);
    TNode<Object> tmp11;
    USE(tmp11);
    tmp11 = ExampleGenericOverload_Object_0(state_, TNode<Object>{tmp10});
    TNode<Smi> tmp12;
    USE(tmp12);
    tmp12 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp8}, TNode<Object>{tmp11});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    ca_.Branch(tmp14, &block4, &block5, tmp8, tmp9, tmp10);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Smi> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(ExampleGenericOverload<Object>(xObject)) == 5' failed", "test/torque/test-torque.tq", 532);
  }

  if (block4.is_used()) {
    TNode<Context> tmp18;
    TNode<Smi> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20);
    ca_.Goto(&block6, tmp18);
  }

    TNode<Context> tmp21;
    ca_.Bind(&block6, &tmp21);
}

void TestEquality_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Float64T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp1});
    TNode<Float64T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp3});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = IsNumberNotEqual_0(state_, TNode<Number>{tmp2}, TNode<Number>{tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp5);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<BoolT> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert '!notEqual' failed", "test/torque/test-torque.tq", 539);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block2, &tmp9, &tmp10);
    TNode<Float64T> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp11});
    TNode<Float64T> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_float64_constexpr_float64_0(state_, 0.5);
    TNode<HeapNumber> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).AllocateHeapNumberWithValue(TNode<Float64T>{tmp13});
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = IsNumberEqual_0(state_, TNode<Number>{tmp12}, TNode<Number>{tmp14});
    ca_.Branch(tmp15, &block4, &block5, tmp9, tmp10, tmp15);
  }

  if (block5.is_used()) {
    TNode<Context> tmp16;
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    ca_.Bind(&block5, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).FailAssert("Torque assert 'equal' failed", "test/torque/test-torque.tq", 542);
  }

  if (block4.is_used()) {
    TNode<Context> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    ca_.Bind(&block4, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp19);
  }

    TNode<Context> tmp22;
    ca_.Bind(&block6, &tmp22);
}

TNode<BoolT> TestOrAnd_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y, p_z);

  if (block0.is_used()) {
    TNode<BoolT> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Branch(tmp0, &block6, &block7, tmp0, tmp1, tmp2, tmp0);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    TNode<BoolT> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, tmp6, tmp7);
  }

  if (block7.is_used()) {
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    TNode<BoolT> tmp10;
    TNode<BoolT> tmp11;
    ca_.Bind(&block7, &tmp8, &tmp9, &tmp10, &tmp11);
    ca_.Branch(tmp9, &block9, &block10, tmp8, tmp9, tmp10, tmp11, tmp9);
  }

  if (block9.is_used()) {
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block9, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp14);
  }

  if (block10.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    TNode<BoolT> tmp21;
    ca_.Bind(&block10, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block11, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22);
  }

  if (block11.is_used()) {
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    TNode<BoolT> tmp25;
    TNode<BoolT> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    ca_.Bind(&block11, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    ca_.Goto(&block8, tmp23, tmp24, tmp25, tmp26, tmp28);
  }

  if (block8.is_used()) {
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    TNode<BoolT> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block8, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    ca_.Branch(tmp33, &block2, &block3, tmp29, tmp30, tmp31);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp34;
    TNode<BoolT> tmp35;
    TNode<BoolT> tmp36;
    ca_.Bind(&block2, &tmp34, &tmp35, &tmp36);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp34, tmp35, tmp36, tmp37);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp38;
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    ca_.Bind(&block3, &tmp38, &tmp39, &tmp40);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp38, tmp39, tmp40, tmp41);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp42;
    TNode<BoolT> tmp43;
    TNode<BoolT> tmp44;
    TNode<BoolT> tmp45;
    ca_.Bind(&block4, &tmp42, &tmp43, &tmp44, &tmp45);
    ca_.Goto(&block12, tmp42, tmp43, tmp44, tmp45);
  }

    TNode<BoolT> tmp46;
    TNode<BoolT> tmp47;
    TNode<BoolT> tmp48;
    TNode<BoolT> tmp49;
    ca_.Bind(&block12, &tmp46, &tmp47, &tmp48, &tmp49);
  return TNode<BoolT>{tmp49};
}

TNode<BoolT> TestAndOr_0(compiler::CodeAssemblerState* state_, TNode<BoolT> p_x, TNode<BoolT> p_y, TNode<BoolT> p_z) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<BoolT, BoolT, BoolT, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_y, p_z);

  if (block0.is_used()) {
    TNode<BoolT> tmp0;
    TNode<BoolT> tmp1;
    TNode<BoolT> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    ca_.Branch(tmp0, &block6, &block7, tmp0, tmp1, tmp2, tmp0);
  }

  if (block6.is_used()) {
    TNode<BoolT> tmp3;
    TNode<BoolT> tmp4;
    TNode<BoolT> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block6, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block8, tmp3, tmp4, tmp5, tmp6, tmp4);
  }

  if (block7.is_used()) {
    TNode<BoolT> tmp7;
    TNode<BoolT> tmp8;
    TNode<BoolT> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block8, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block8.is_used()) {
    TNode<BoolT> tmp12;
    TNode<BoolT> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Branch(tmp16, &block9, &block10, tmp12, tmp13, tmp14, tmp16);
  }

  if (block9.is_used()) {
    TNode<BoolT> tmp17;
    TNode<BoolT> tmp18;
    TNode<BoolT> tmp19;
    TNode<BoolT> tmp20;
    ca_.Bind(&block9, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block11, tmp17, tmp18, tmp19, tmp20, tmp21);
  }

  if (block10.is_used()) {
    TNode<BoolT> tmp22;
    TNode<BoolT> tmp23;
    TNode<BoolT> tmp24;
    TNode<BoolT> tmp25;
    ca_.Bind(&block10, &tmp22, &tmp23, &tmp24, &tmp25);
    ca_.Goto(&block11, tmp22, tmp23, tmp24, tmp25, tmp24);
  }

  if (block11.is_used()) {
    TNode<BoolT> tmp26;
    TNode<BoolT> tmp27;
    TNode<BoolT> tmp28;
    TNode<BoolT> tmp29;
    TNode<BoolT> tmp30;
    ca_.Bind(&block11, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    ca_.Branch(tmp30, &block2, &block3, tmp26, tmp27, tmp28);
  }

  if (block2.is_used()) {
    TNode<BoolT> tmp31;
    TNode<BoolT> tmp32;
    TNode<BoolT> tmp33;
    ca_.Bind(&block2, &tmp31, &tmp32, &tmp33);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block4, tmp31, tmp32, tmp33, tmp34);
  }

  if (block3.is_used()) {
    TNode<BoolT> tmp35;
    TNode<BoolT> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block3, &tmp35, &tmp36, &tmp37);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block4, tmp35, tmp36, tmp37, tmp38);
  }

  if (block4.is_used()) {
    TNode<BoolT> tmp39;
    TNode<BoolT> tmp40;
    TNode<BoolT> tmp41;
    TNode<BoolT> tmp42;
    ca_.Bind(&block4, &tmp39, &tmp40, &tmp41, &tmp42);
    ca_.Goto(&block12, tmp39, tmp40, tmp41, tmp42);
  }

    TNode<BoolT> tmp43;
    TNode<BoolT> tmp44;
    TNode<BoolT> tmp45;
    TNode<BoolT> tmp46;
    ca_.Bind(&block12, &tmp43, &tmp44, &tmp45, &tmp46);
  return TNode<BoolT>{tmp46};
}

void TestLogicalOperators_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block15(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block17(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block25(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block27(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block29(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = TestAndOr_0(state_, TNode<BoolT>{tmp0}, TNode<BoolT>{tmp1}, TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3);
  }

  if (block3.is_used()) {
    ca_.Bind(&block3);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, true)' failed", "test/torque/test-torque.tq", 557);
  }

  if (block2.is_used()) {
    ca_.Bind(&block2);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = TestAndOr_0(state_, TNode<BoolT>{tmp4}, TNode<BoolT>{tmp5}, TNode<BoolT>{tmp6});
    ca_.Branch(tmp7, &block4, &block5);
  }

  if (block5.is_used()) {
    ca_.Bind(&block5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, true, false)' failed", "test/torque/test-torque.tq", 558);
  }

  if (block4.is_used()) {
    ca_.Bind(&block4);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = TestAndOr_0(state_, TNode<BoolT>{tmp8}, TNode<BoolT>{tmp9}, TNode<BoolT>{tmp10});
    ca_.Branch(tmp11, &block6, &block7);
  }

  if (block7.is_used()) {
    ca_.Bind(&block7);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(true, false, true)' failed", "test/torque/test-torque.tq", 559);
  }

  if (block6.is_used()) {
    ca_.Bind(&block6);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = TestAndOr_0(state_, TNode<BoolT>{tmp12}, TNode<BoolT>{tmp13}, TNode<BoolT>{tmp14});
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp15});
    ca_.Branch(tmp16, &block8, &block9);
  }

  if (block9.is_used()) {
    ca_.Bind(&block9);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(true, false, false)' failed", "test/torque/test-torque.tq", 560);
  }

  if (block8.is_used()) {
    ca_.Bind(&block8);
    TNode<BoolT> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = TestAndOr_0(state_, TNode<BoolT>{tmp17}, TNode<BoolT>{tmp18}, TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block10, &block11);
  }

  if (block11.is_used()) {
    ca_.Bind(&block11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, true, true)' failed", "test/torque/test-torque.tq", 561);
  }

  if (block10.is_used()) {
    ca_.Bind(&block10);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp23;
    USE(tmp23);
    tmp23 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = TestAndOr_0(state_, TNode<BoolT>{tmp21}, TNode<BoolT>{tmp22}, TNode<BoolT>{tmp23});
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp24});
    ca_.Branch(tmp25, &block12, &block13);
  }

  if (block13.is_used()) {
    ca_.Bind(&block13);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, true, false)' failed", "test/torque/test-torque.tq", 562);
  }

  if (block12.is_used()) {
    ca_.Bind(&block12);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = TestAndOr_0(state_, TNode<BoolT>{tmp26}, TNode<BoolT>{tmp27}, TNode<BoolT>{tmp28});
    ca_.Branch(tmp29, &block14, &block15);
  }

  if (block15.is_used()) {
    ca_.Bind(&block15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestAndOr(false, false, true)' failed", "test/torque/test-torque.tq", 563);
  }

  if (block14.is_used()) {
    ca_.Bind(&block14);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = TestAndOr_0(state_, TNode<BoolT>{tmp30}, TNode<BoolT>{tmp31}, TNode<BoolT>{tmp32});
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp33});
    ca_.Branch(tmp34, &block16, &block17);
  }

  if (block17.is_used()) {
    ca_.Bind(&block17);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestAndOr(false, false, false)' failed", "test/torque/test-torque.tq", 564);
  }

  if (block16.is_used()) {
    ca_.Bind(&block16);
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = TestOrAnd_0(state_, TNode<BoolT>{tmp35}, TNode<BoolT>{tmp36}, TNode<BoolT>{tmp37});
    ca_.Branch(tmp38, &block18, &block19);
  }

  if (block19.is_used()) {
    ca_.Bind(&block19);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, true)' failed", "test/torque/test-torque.tq", 565);
  }

  if (block18.is_used()) {
    ca_.Bind(&block18);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = TestOrAnd_0(state_, TNode<BoolT>{tmp39}, TNode<BoolT>{tmp40}, TNode<BoolT>{tmp41});
    ca_.Branch(tmp42, &block20, &block21);
  }

  if (block21.is_used()) {
    ca_.Bind(&block21);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, true, false)' failed", "test/torque/test-torque.tq", 566);
  }

  if (block20.is_used()) {
    ca_.Bind(&block20);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = TestOrAnd_0(state_, TNode<BoolT>{tmp43}, TNode<BoolT>{tmp44}, TNode<BoolT>{tmp45});
    ca_.Branch(tmp46, &block22, &block23);
  }

  if (block23.is_used()) {
    ca_.Bind(&block23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, true)' failed", "test/torque/test-torque.tq", 567);
  }

  if (block22.is_used()) {
    ca_.Bind(&block22);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp48;
    USE(tmp48);
    tmp48 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp49;
    USE(tmp49);
    tmp49 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp50;
    USE(tmp50);
    tmp50 = TestOrAnd_0(state_, TNode<BoolT>{tmp47}, TNode<BoolT>{tmp48}, TNode<BoolT>{tmp49});
    ca_.Branch(tmp50, &block24, &block25);
  }

  if (block25.is_used()) {
    ca_.Bind(&block25);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(true, false, false)' failed", "test/torque/test-torque.tq", 568);
  }

  if (block24.is_used()) {
    ca_.Bind(&block24);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp52;
    USE(tmp52);
    tmp52 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = TestOrAnd_0(state_, TNode<BoolT>{tmp51}, TNode<BoolT>{tmp52}, TNode<BoolT>{tmp53});
    ca_.Branch(tmp54, &block26, &block27);
  }

  if (block27.is_used()) {
    ca_.Bind(&block27);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TestOrAnd(false, true, true)' failed", "test/torque/test-torque.tq", 569);
  }

  if (block26.is_used()) {
    ca_.Bind(&block26);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp57;
    USE(tmp57);
    tmp57 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = TestOrAnd_0(state_, TNode<BoolT>{tmp55}, TNode<BoolT>{tmp56}, TNode<BoolT>{tmp57});
    TNode<BoolT> tmp59;
    USE(tmp59);
    tmp59 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp58});
    ca_.Branch(tmp59, &block28, &block29);
  }

  if (block29.is_used()) {
    ca_.Bind(&block29);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, true, false)' failed", "test/torque/test-torque.tq", 570);
  }

  if (block28.is_used()) {
    ca_.Bind(&block28);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp61;
    USE(tmp61);
    tmp61 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    TNode<BoolT> tmp63;
    USE(tmp63);
    tmp63 = TestOrAnd_0(state_, TNode<BoolT>{tmp60}, TNode<BoolT>{tmp61}, TNode<BoolT>{tmp62});
    TNode<BoolT> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp63});
    ca_.Branch(tmp64, &block30, &block31);
  }

  if (block31.is_used()) {
    ca_.Bind(&block31);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, true)' failed", "test/torque/test-torque.tq", 571);
  }

  if (block30.is_used()) {
    ca_.Bind(&block30);
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = TestOrAnd_0(state_, TNode<BoolT>{tmp65}, TNode<BoolT>{tmp66}, TNode<BoolT>{tmp67});
    TNode<BoolT> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp68});
    ca_.Branch(tmp69, &block32, &block33);
  }

  if (block33.is_used()) {
    ca_.Bind(&block33);
    CodeStubAssembler(state_).FailAssert("Torque assert '!TestOrAnd(false, false, false)' failed", "test/torque/test-torque.tq", 572);
  }

  if (block32.is_used()) {
    ca_.Bind(&block32);
    ca_.Goto(&block34);
  }

    ca_.Bind(&block34);
}

TNode<Smi> TestCall_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_i, compiler::CodeAssemblerLabel* label_A) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_i);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Branch(tmp2, &block3, &block4, tmp0);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp3;
    ca_.Bind(&block3, &tmp3);
    ca_.Goto(&block5, tmp3, tmp3);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp4;
    ca_.Bind(&block4, &tmp4);
    ca_.Goto(label_A);
  }

    TNode<Smi> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block5, &tmp5, &tmp6);
  return TNode<Smi>{tmp6};
}

void TestOtherwiseWithCode1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = TestCall_0(state_, TNode<Smi>{tmp2}, &label0);
    ca_.Goto(&block6, tmp0, tmp1, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp0, tmp1);
    }
  }

  if (block7.is_used()) {
    TNode<Smi> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block7, &tmp4, &tmp5);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp5}, TNode<Smi>{tmp6});
    ca_.Goto(&block2, tmp7, tmp7);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10);
    ca_.Goto(&block2, tmp8, tmp9);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block2, &tmp11, &tmp12);
    ca_.Goto(&block12);
  }

  if (block11.is_used()) {
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block11, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'v == 2' failed", "test/torque/test-torque.tq", 591);
  }

  if (block10.is_used()) {
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block10, &tmp15, &tmp16);
  }

    ca_.Bind(&block12);
}

void TestOtherwiseWithCode2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = TestCall_0(state_, TNode<Smi>{tmp7}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp7, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block9, &tmp9, &tmp10, &tmp11);
    ca_.Goto(&block3, tmp9, tmp10);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp12;
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    TNode<Smi> tmp15;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<Smi> tmp16;
    USE(tmp16);
    tmp16 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp12}, TNode<Smi>{tmp16});
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp13}, TNode<Smi>{tmp18});
    ca_.Goto(&block4, tmp17, tmp19);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block3, &tmp20, &tmp21);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp22;
    ca_.Bind(&block13, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 's == 5' failed", "test/torque/test-torque.tq", 601);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block12, &tmp23);
  }

    ca_.Bind(&block14);
}

void TestOtherwiseWithCode3_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi, Smi, Smi, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp2;
    TNode<Smi> tmp3;
    ca_.Bind(&block4, &tmp2, &tmp3);
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp3}, TNode<Smi>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp8 = TestCall_0(state_, TNode<Smi>{tmp7}, &label0);
    ca_.Goto(&block8, tmp6, tmp7, tmp6, tmp7, tmp8);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp6, tmp7, tmp6, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    TNode<Smi> tmp12;
    ca_.Bind(&block9, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block3, tmp9, tmp10);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp13;
    TNode<Smi> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block8, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp15}, TNode<Smi>{tmp17});
    TNode<Smi> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp14}, TNode<Smi>{tmp19});
    ca_.Goto(&block4, tmp18, tmp20);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block3, &tmp21, &tmp22);
    ca_.Goto(&block14);
  }

  if (block13.is_used()) {
    TNode<Smi> tmp23;
    ca_.Bind(&block13, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 's == 10' failed", "test/torque/test-torque.tq", 610);
  }

  if (block12.is_used()) {
    TNode<Smi> tmp24;
    ca_.Bind(&block12, &tmp24);
  }

    ca_.Bind(&block14);
}

void TestForwardLabel_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    ca_.Goto(&block10);
  }

  if (block9.is_used()) {
    TNode<Smi> tmp1;
    ca_.Bind(&block9, &tmp1);
    CodeStubAssembler(state_).FailAssert("Torque assert 'b == 5' failed", "test/torque/test-torque.tq", 622);
  }

  if (block8.is_used()) {
    TNode<Smi> tmp2;
    ca_.Bind(&block8, &tmp2);
  }

    ca_.Bind(&block10);
}

void TestQualifiedAccess_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Is_JSArray_Smi_0(state_, TNode<Context>{tmp0}, TNode<Smi>{tmp1});
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp2});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block3, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert '!Is<JSArray>(s)' failed", "test/torque/test-torque.tq", 629);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Smi> tmp7;
    ca_.Bind(&block2, &tmp6, &tmp7);
    ca_.Goto(&block4, tmp6);
  }

    TNode<Context> tmp8;
    ca_.Bind(&block4, &tmp8);
}

TNode<Smi> TestCatch1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block4, tmp0, tmp1, tmp0, catch2_exception_object);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block5, tmp3, tmp7);
  }

    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

void TestCatch2Wrapper_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch2_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    TestCatch2Wrapper_0(state_, TNode<Context>{tmp0});
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block4, tmp0, tmp1, tmp0, catch2_exception_object);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block5, tmp3, tmp7);
  }

    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    ca_.Bind(&block5, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

void TestCatch3WrapperWithLabel_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, compiler::CodeAssemblerLabel* label__Abort) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp0}, MessageTemplate::kInvalidArrayLength);
  }
}

TNode<Smi> TestCatch3_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context, Object> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block8(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerExceptionHandlerLabel catch2__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch2__label);
    TestCatch3WrapperWithLabel_0(state_, TNode<Context>{tmp0}, &label0);
    }
    if (catch2__label.is_used()) {
      compiler::CodeAssemblerLabel catch2_skip(&ca_);
      TNode<Object> catch2_exception_object;
      ca_.Bind(&catch2__label, &catch2_exception_object);
      ca_.Goto(&block7, tmp0, tmp1, tmp0, catch2_exception_object);
    }
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block7, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block3, tmp3, tmp4, tmp6);
  }

  if (block6.is_used()) {
    TNode<Context> tmp7;
    TNode<Smi> tmp8;
    TNode<Context> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
    TNode<Smi> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerExceptionHandlerLabel catch11__label(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    { compiler::CodeAssemblerScopedExceptionHandler s(&ca_, &catch11__label);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    }
    if (catch11__label.is_used()) {
      compiler::CodeAssemblerLabel catch11_skip(&ca_);
      ca_.Goto(&catch11_skip);
      TNode<Object> catch11_exception_object;
      ca_.Bind(&catch11__label, &catch11_exception_object);
      ca_.Goto(&block8, tmp7, tmp8, catch11_exception_object);
      ca_.Bind(&catch11_skip);
    }
    ca_.Goto(&block1, tmp7, tmp10);
  }

  if (block8.is_used()) {
    TNode<Context> tmp12;
    TNode<Smi> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block3, tmp12, tmp13, tmp14);
  }

  if (block3.is_used()) {
    TNode<Context> tmp15;
    TNode<Smi> tmp16;
    TNode<Object> tmp17;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17);
    TNode<Smi> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    ca_.Goto(&block1, tmp15, tmp18);
  }

  if (block1.is_used()) {
    TNode<Context> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block1, &tmp19, &tmp20);
    ca_.Goto(&block9, tmp19, tmp20);
  }

    TNode<Context> tmp21;
    TNode<Smi> tmp22;
    ca_.Bind(&block9, &tmp21, &tmp22);
  return TNode<Smi>{tmp22};
}

void TestIterator_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Map> p_map) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, JSReceiver, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, JSReceiver, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, Object, JSReceiver, Object, Map, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map, Object, JSReceiver, Object, Object, JSReceiver, Object, Map, Context, JSReceiver> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Map> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_map);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Map> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = IteratorBuiltinsAssembler(state_).GetIteratorMethod(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    TNode<Object> tmp5;
    USE(tmp5);
    std::tie(tmp4, tmp5) = IteratorBuiltinsAssembler(state_).GetIterator(TNode<Context>{tmp0}, TNode<Object>{tmp1}).Flatten();
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp0}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp4}, TNode<Object>{tmp5}}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp5, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp4, tmp5, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<Map> tmp9;
    TNode<Object> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<Object> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<Object> tmp14;
    TNode<Context> tmp15;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    ca_.Goto(&block3, tmp7, tmp8, tmp9);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<Map> tmp18;
    TNode<Object> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<Object> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Object> tmp23;
    TNode<Context> tmp24;
    TNode<JSReceiver> tmp25;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<JSReceiver> tmp26;
    USE(tmp26);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp26 = IteratorBuiltinsAssembler(state_).IteratorStep(TNode<Context>{tmp16}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp20}, TNode<Object>{tmp21}}, TNode<Map>{tmp18}, &label0);
    ca_.Goto(&block6, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp25, tmp20, tmp21, tmp18, tmp16, tmp26);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block7, tmp16, tmp17, tmp18, tmp19, tmp20, tmp21, tmp25, tmp20, tmp21, tmp18, tmp16);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp27;
    TNode<JSReceiver> tmp28;
    TNode<Map> tmp29;
    TNode<Object> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<Object> tmp35;
    TNode<Map> tmp36;
    TNode<Context> tmp37;
    ca_.Bind(&block7, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block3, tmp27, tmp28, tmp29);
  }

  if (block6.is_used()) {
    TNode<Context> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Map> tmp40;
    TNode<Object> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<JSReceiver> tmp45;
    TNode<Object> tmp46;
    TNode<Map> tmp47;
    TNode<Context> tmp48;
    TNode<JSReceiver> tmp49;
    ca_.Bind(&block6, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Object> tmp50;
    USE(tmp50);
    tmp50 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp38}, TNode<JSReceiver>{tmp39});
    TNode<Object> tmp51;
    USE(tmp51);
    tmp51 = IteratorBuiltinsAssembler(state_).IteratorValue(TNode<Context>{tmp38}, TNode<JSReceiver>{tmp39}, TNode<Map>{tmp40});
    TNode<JSArray> tmp52;
    USE(tmp52);
    tmp52 = IteratorBuiltinsAssembler(state_).IterableToList(TNode<Context>{tmp38}, TNode<Object>{tmp41}, TNode<Object>{tmp41});
    IteratorBuiltinsAssembler(state_).IteratorCloseOnException(TNode<Context>{tmp38}, TorqueStructIteratorRecord{TNode<JSReceiver>{tmp42}, TNode<Object>{tmp43}}, TNode<Object>{tmp50});
  }

  if (block3.is_used()) {
    TNode<Context> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<Map> tmp55;
    ca_.Bind(&block3, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block8, tmp53, tmp54, tmp55);
  }

    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<Map> tmp58;
    ca_.Bind(&block8, &tmp56, &tmp57, &tmp58);
}

void TestFrame1_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context, RawPtrT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, RawPtrT, Smi, RawPtrT, RawPtrT, Context, RawPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<RawPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).LoadFramePointer();
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = LoadContextOrFrameTypeFromFrame_0(state_, TNode<Context>{tmp0}, TNode<RawPtrT>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_FrameType_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp4;
    TNode<RawPtrT> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block5, &tmp4, &tmp5, &tmp6);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<RawPtrT> tmp8;
    TNode<Object> tmp9;
    TNode<Smi> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<RawPtrT> tmp11;
    USE(tmp11);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp11 = Cast_StandardFrame_0(state_, TNode<Context>{tmp7}, TNode<RawPtrT>{tmp8}, &label0);
    ca_.Goto(&block16, tmp7, tmp8, tmp10, tmp8, tmp8, tmp7, tmp11);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block17, tmp7, tmp8, tmp10, tmp8, tmp8, tmp7);
    }
  }

  if (block9.is_used()) {
    TNode<Context> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<Smi> tmp14;
    ca_.Bind(&block9, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'frameType == STUB_FRAME' failed", "test/torque/test-torque.tq", 708);
  }

  if (block8.is_used()) {
    TNode<Context> tmp15;
    TNode<RawPtrT> tmp16;
    TNode<Smi> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  }

  if (block13.is_used()) {
    TNode<Context> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<Smi> tmp20;
    ca_.Bind(&block13, &tmp18, &tmp19, &tmp20);
    CodeStubAssembler(state_).FailAssert("Torque assert 'f.caller == LoadParentFramePointer()' failed", "test/torque/test-torque.tq", 709);
  }

  if (block12.is_used()) {
    TNode<Context> tmp21;
    TNode<RawPtrT> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block12, &tmp21, &tmp22, &tmp23);
  }

  if (block17.is_used()) {
    TNode<Context> tmp24;
    TNode<RawPtrT> tmp25;
    TNode<Smi> tmp26;
    TNode<RawPtrT> tmp27;
    TNode<RawPtrT> tmp28;
    TNode<Context> tmp29;
    ca_.Bind(&block17, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29);
    TNode<RawPtrT> tmp30;
    USE(tmp30);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp30 = Cast_ArgumentsAdaptorFrame_0(state_, TNode<Context>{tmp24}, TNode<RawPtrT>{ca_.UncheckedCast<RawPtrT>(tmp27)}, &label0);
    ca_.Goto(&block20, tmp24, tmp25, tmp26, tmp27, ca_.UncheckedCast<RawPtrT>(tmp27), tmp24, tmp30);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block21, tmp24, tmp25, tmp26, tmp27, ca_.UncheckedCast<RawPtrT>(tmp27), tmp24);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp31;
    TNode<RawPtrT> tmp32;
    TNode<Smi> tmp33;
    TNode<RawPtrT> tmp34;
    TNode<RawPtrT> tmp35;
    TNode<Context> tmp36;
    TNode<RawPtrT> tmp37;
    ca_.Bind(&block16, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block21.is_used()) {
    TNode<Context> tmp38;
    TNode<RawPtrT> tmp39;
    TNode<Smi> tmp40;
    TNode<RawPtrT> tmp41;
    TNode<RawPtrT> tmp42;
    TNode<Context> tmp43;
    ca_.Bind(&block21, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    ca_.Goto(&block22, tmp38);
  }

  if (block20.is_used()) {
    TNode<Context> tmp44;
    TNode<RawPtrT> tmp45;
    TNode<Smi> tmp46;
    TNode<RawPtrT> tmp47;
    TNode<RawPtrT> tmp48;
    TNode<Context> tmp49;
    TNode<RawPtrT> tmp50;
    ca_.Bind(&block20, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp51;
    ca_.Bind(&block22, &tmp51);
}

void TestNew_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSArray> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<JSArray> tmp1;
    USE(tmp1);
    tmp1 = NewJSArray_1(state_, TNode<Context>{tmp0});
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = Method_JSArray_IsEmpty_0(state_, TNode<JSArray>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp3;
    TNode<JSArray> tmp4;
    ca_.Bind(&block3, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'f.IsEmpty()' failed", "test/torque/test-torque.tq", 725);
  }

  if (block2.is_used()) {
    TNode<Context> tmp5;
    TNode<JSArray> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp7);
    TNode<Number> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp6, tmp7}, tmp8);
    ca_.Goto(&block4, tmp5);
  }

    TNode<Context> tmp9;
    ca_.Bind(&block4, &tmp9);
}

void TestStructConstructor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block14(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block16(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Int32T, Int32T, Int32T, Int32T> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    TNode<Int32T> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp3}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp3, tmp1, tmp2, tmp4);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<Int32T> tmp8;
    TNode<Int32T> tmp9;
    TNode<Int32T> tmp10;
    TNode<Int32T> tmp11;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.a == 5' failed", "test/torque/test-torque.tq", 750);
  }

  if (block2.is_used()) {
    TNode<Context> tmp12;
    TNode<Int32T> tmp13;
    TNode<Int32T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    ca_.Bind(&block2, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Int32T> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_int32_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp14}, TNode<Int32T>{tmp17});
    ca_.Branch(tmp18, &block4, &block5, tmp12, tmp13, tmp14, tmp15, tmp16);
  }

  if (block5.is_used()) {
    TNode<Context> tmp19;
    TNode<Int32T> tmp20;
    TNode<Int32T> tmp21;
    TNode<Int32T> tmp22;
    TNode<Int32T> tmp23;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 6' failed", "test/torque/test-torque.tq", 751);
  }

  if (block4.is_used()) {
    TNode<Context> tmp24;
    TNode<Int32T> tmp25;
    TNode<Int32T> tmp26;
    TNode<Int32T> tmp27;
    TNode<Int32T> tmp28;
    ca_.Bind(&block4, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Int32T> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_int32_constexpr_int31_0(state_, 7);
    TNode<BoolT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp27}, TNode<Int32T>{tmp29});
    ca_.Branch(tmp30, &block6, &block7, tmp24, tmp25, tmp26, tmp27, tmp28);
  }

  if (block7.is_used()) {
    TNode<Context> tmp31;
    TNode<Int32T> tmp32;
    TNode<Int32T> tmp33;
    TNode<Int32T> tmp34;
    TNode<Int32T> tmp35;
    ca_.Bind(&block7, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.y == 7' failed", "test/torque/test-torque.tq", 752);
  }

  if (block6.is_used()) {
    TNode<Context> tmp36;
    TNode<Int32T> tmp37;
    TNode<Int32T> tmp38;
    TNode<Int32T> tmp39;
    TNode<Int32T> tmp40;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<Int32T> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_int32_constexpr_int31_0(state_, 8);
    TNode<BoolT> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp40}, TNode<Int32T>{tmp41});
    ca_.Branch(tmp42, &block8, &block9, tmp36, tmp37, tmp38, tmp39, tmp40);
  }

  if (block9.is_used()) {
    TNode<Context> tmp43;
    TNode<Int32T> tmp44;
    TNode<Int32T> tmp45;
    TNode<Int32T> tmp46;
    TNode<Int32T> tmp47;
    ca_.Bind(&block9, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.c == 8' failed", "test/torque/test-torque.tq", 753);
  }

  if (block8.is_used()) {
    TNode<Context> tmp48;
    TNode<Int32T> tmp49;
    TNode<Int32T> tmp50;
    TNode<Int32T> tmp51;
    TNode<Int32T> tmp52;
    ca_.Bind(&block8, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52);
    TNode<Int32T> tmp53;
    USE(tmp53);
    tmp53 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Int32T> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp53}, TNode<Int32T>{tmp54});
    ca_.Branch(tmp55, &block10, &block11, tmp48, tmp49, tmp53, tmp51, tmp52);
  }

  if (block11.is_used()) {
    TNode<Context> tmp56;
    TNode<Int32T> tmp57;
    TNode<Int32T> tmp58;
    TNode<Int32T> tmp59;
    TNode<Int32T> tmp60;
    ca_.Bind(&block11, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 1' failed", "test/torque/test-torque.tq", 755);
  }

  if (block10.is_used()) {
    TNode<Context> tmp61;
    TNode<Int32T> tmp62;
    TNode<Int32T> tmp63;
    TNode<Int32T> tmp64;
    TNode<Int32T> tmp65;
    ca_.Bind(&block10, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    TNode<Int32T> tmp66;
    USE(tmp66);
    tmp66 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<Int32T> tmp67;
    USE(tmp67);
    tmp67 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp66}, TNode<Int32T>{tmp67});
    ca_.Branch(tmp68, &block13, &block14, tmp61, tmp62, tmp66, tmp64, tmp65);
  }

  if (block14.is_used()) {
    TNode<Context> tmp69;
    TNode<Int32T> tmp70;
    TNode<Int32T> tmp71;
    TNode<Int32T> tmp72;
    TNode<Int32T> tmp73;
    ca_.Bind(&block14, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.x == 2' failed", "test/torque/test-torque.tq", 757);
  }

  if (block13.is_used()) {
    TNode<Context> tmp74;
    TNode<Int32T> tmp75;
    TNode<Int32T> tmp76;
    TNode<Int32T> tmp77;
    TNode<Int32T> tmp78;
    ca_.Bind(&block13, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<Int32T> tmp79;
    USE(tmp79);
    tmp79 = FromConstexpr_int32_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp80;
    USE(tmp80);
    tmp80 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp76}, TNode<Int32T>{tmp79});
    ca_.Branch(tmp80, &block15, &block16, tmp74, tmp75, tmp76, tmp77, tmp78);
  }

  if (block16.is_used()) {
    TNode<Context> tmp81;
    TNode<Int32T> tmp82;
    TNode<Int32T> tmp83;
    TNode<Int32T> tmp84;
    TNode<Int32T> tmp85;
    ca_.Bind(&block16, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.b.GetX() == 2' failed", "test/torque/test-torque.tq", 758);
  }

  if (block15.is_used()) {
    TNode<Context> tmp86;
    TNode<Int32T> tmp87;
    TNode<Int32T> tmp88;
    TNode<Int32T> tmp89;
    TNode<Int32T> tmp90;
    ca_.Bind(&block15, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block18, tmp86);
  }

    TNode<Context> tmp91;
    ca_.Bind(&block18, &tmp91);
}

TNode<InternalClass> NewInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, InternalClass> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    TNode<Map> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).GetStructMap(INTERNAL_CLASS_TYPE);
    TNode<IntPtrT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).IntPtrConstant(((12)));
    TNode<InternalClass> tmp5;
    USE(tmp5);
    tmp5 = ca_.UncheckedCast<InternalClass>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp4}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp5, CodeStubAssembler(state_).IntPtrConstant(12), TNode<IntPtrT>{tmp4}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp6);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp6}, tmp3);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp7);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp7}, tmp0);
    TNode<IntPtrT> tmp8 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp8);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp5, tmp8}, tmp2);
    ca_.Goto(&block2, tmp0, tmp5);
  }

    TNode<Smi> tmp9;
    TNode<InternalClass> tmp10;
    ca_.Bind(&block2, &tmp9, &tmp10);
  return TNode<InternalClass>{tmp10};
}

void TestInternalClass_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass, InternalClass> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass, InternalClass> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, InternalClass> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<InternalClass> tmp2;
    USE(tmp2);
    tmp2 = NewInternalClass_0(state_, TNode<Smi>{tmp1});
    compiler::CodeAssemblerLabel label0(&ca_);
    Method_InternalClass_Flip_0(state_, TNode<InternalClass>{tmp2}, &label0);
    ca_.Goto(&block4, tmp0, tmp2, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp2, tmp2);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<InternalClass> tmp4;
    TNode<InternalClass> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block4.is_used()) {
    TNode<Context> tmp6;
    TNode<InternalClass> tmp7;
    TNode<InternalClass> tmp8;
    ca_.Bind(&block4, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp9);
    TNode<Smi>tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp9});
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 6);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp12, &block6, &block7, tmp6, tmp7);
  }

  if (block7.is_used()) {
    TNode<Context> tmp13;
    TNode<InternalClass> tmp14;
    ca_.Bind(&block7, &tmp13, &tmp14);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.a == 6' failed", "test/torque/test-torque.tq", 779);
  }

  if (block6.is_used()) {
    TNode<Context> tmp15;
    TNode<InternalClass> tmp16;
    ca_.Bind(&block6, &tmp15, &tmp16);
    TNode<IntPtrT> tmp17 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp17);
    TNode<Number>tmp18 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp16, tmp17});
    TNode<Number> tmp19;
    USE(tmp19);
    tmp19 = FromConstexpr_Number_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = IsNumberEqual_0(state_, TNode<Number>{tmp18}, TNode<Number>{tmp19});
    ca_.Branch(tmp20, &block8, &block9, tmp15, tmp16);
  }

  if (block9.is_used()) {
    TNode<Context> tmp21;
    TNode<InternalClass> tmp22;
    ca_.Bind(&block9, &tmp21, &tmp22);
    CodeStubAssembler(state_).FailAssert("Torque assert 'o.b == 5' failed", "test/torque/test-torque.tq", 780);
  }

  if (block8.is_used()) {
    TNode<Context> tmp23;
    TNode<InternalClass> tmp24;
    ca_.Bind(&block8, &tmp23, &tmp24);
    ca_.Goto(&block10, tmp23);
  }

    TNode<Context> tmp25;
    ca_.Bind(&block10, &tmp25);
}

void TestConstInStructs_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Int32T, Object, Int32T, Object, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Oddball> tmp0;
    USE(tmp0);
    tmp0 = Null_0(state_);
    TNode<Int32T> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    TNode<Int32T> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32Equal(TNode<Int32T>{tmp1}, TNode<Int32T>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp4, tmp3, tmp0, tmp1);
  }

  if (block3.is_used()) {
    TNode<Object> tmp7;
    TNode<Int32T> tmp8;
    TNode<Object> tmp9;
    TNode<Int32T> tmp10;
    TNode<Object> tmp11;
    TNode<Int32T> tmp12;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod1() == 1' failed", "test/torque/test-torque.tq", 801);
  }

  if (block2.is_used()) {
    TNode<Object> tmp13;
    TNode<Int32T> tmp14;
    TNode<Object> tmp15;
    TNode<Int32T> tmp16;
    TNode<Object> tmp17;
    TNode<Int32T> tmp18;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<Oddball> tmp19;
    USE(tmp19);
    tmp19 = Null_0(state_);
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp13}, TNode<HeapObject>{tmp19});
    ca_.Branch(tmp20, &block5, &block6, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block6.is_used()) {
    TNode<Object> tmp21;
    TNode<Int32T> tmp22;
    TNode<Object> tmp23;
    TNode<Int32T> tmp24;
    TNode<Object> tmp25;
    TNode<Int32T> tmp26;
    ca_.Bind(&block6, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
    CodeStubAssembler(state_).FailAssert("Torque assert 'x.TestMethod2() == Null' failed", "test/torque/test-torque.tq", 802);
  }

  if (block5.is_used()) {
    TNode<Object> tmp27;
    TNode<Int32T> tmp28;
    TNode<Object> tmp29;
    TNode<Int32T> tmp30;
    TNode<Object> tmp31;
    TNode<Int32T> tmp32;
    ca_.Bind(&block5, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32);
    ca_.Goto(&block8);
  }

    ca_.Bind(&block8);
}

TNode<Object> TestNewFixedArrayFromSpread_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi, Smi, FixedArray> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi, Smi, FixedArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = kFixedArrayMap_0(state_);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IntPtrConstant(((8)));
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_int32_constexpr_int31_0(state_, kTaggedSize);
    TNode<Int32T> tmp6;
    USE(tmp6);
    tmp6 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp4});
    TNode<Int32T> tmp7;
    USE(tmp7);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp7 = CodeStubAssembler(state_).TryInt32Mul(TNode<Int32T>{tmp6}, TNode<Int32T>{tmp5}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp1, tmp3, tmp3, tmp4, tmp5, tmp6, tmp6, tmp5, tmp7);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp1, tmp3, tmp3, tmp4, tmp5, tmp6, tmp6, tmp5);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    TNode<Map> tmp10;
    TNode<Smi> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<Smi> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    TNode<Int32T> tmp17;
    TNode<Int32T> tmp18;
    ca_.Bind(&block6, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Context> tmp19;
    TNode<Smi> tmp20;
    TNode<Map> tmp21;
    TNode<Smi> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<Smi> tmp25;
    TNode<Int32T> tmp26;
    TNode<Int32T> tmp27;
    TNode<Int32T> tmp28;
    TNode<Int32T> tmp29;
    TNode<Int32T> tmp30;
    ca_.Bind(&block5, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp30});
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp32 = CodeStubAssembler(state_).TryIntPtrAdd(TNode<IntPtrT>{tmp24}, TNode<IntPtrT>{tmp31}, &label0);
    ca_.Goto(&block9, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp30, tmp31, tmp24, tmp31, tmp32);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp30, tmp31, tmp24, tmp31);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp33;
    TNode<Smi> tmp34;
    TNode<Map> tmp35;
    TNode<Smi> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<Smi> tmp39;
    TNode<Int32T> tmp40;
    TNode<Int32T> tmp41;
    TNode<Int32T> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    ca_.Bind(&block10, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block9.is_used()) {
    TNode<Context> tmp46;
    TNode<Smi> tmp47;
    TNode<Map> tmp48;
    TNode<Smi> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<Smi> tmp52;
    TNode<Int32T> tmp53;
    TNode<Int32T> tmp54;
    TNode<Int32T> tmp55;
    TNode<IntPtrT> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block9, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59);
    TNode<FixedArray> tmp60;
    USE(tmp60);
    tmp60 = ca_.UncheckedCast<FixedArray>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp59}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp60, CodeStubAssembler(state_).IntPtrConstant(8), TNode<IntPtrT>{tmp59}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp61 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp61);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp60, tmp61}, tmp48);
    TNode<IntPtrT> tmp62 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp62);
    TNode<Smi> tmp63;
    USE(tmp63);
    tmp63 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp60, tmp62}, tmp63);
    TNode<Smi> tmp64;
    USE(tmp64);
    tmp64 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<Smi> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block16, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp59, tmp60, tmp60, tmp61, tmp60, tmp62, tmp60, tmp64, tmp49, tmp49, tmp65);
  }

  if (block16.is_used()) {
    TNode<Context> tmp66;
    TNode<Smi> tmp67;
    TNode<Map> tmp68;
    TNode<Smi> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<Smi> tmp72;
    TNode<Int32T> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<FixedArray> tmp75;
    TNode<HeapObject> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<FixedArrayBase> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<FixedArray> tmp80;
    TNode<Smi> tmp81;
    TNode<Smi> tmp82;
    TNode<Smi> tmp83;
    TNode<Smi> tmp84;
    ca_.Bind(&block16, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84);
    TNode<BoolT> tmp85;
    USE(tmp85);
    tmp85 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp84}, TNode<Smi>{tmp81});
    ca_.Branch(tmp85, &block14, &block15, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84);
  }

  if (block14.is_used()) {
    TNode<Context> tmp86;
    TNode<Smi> tmp87;
    TNode<Map> tmp88;
    TNode<Smi> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<Smi> tmp92;
    TNode<Int32T> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<FixedArray> tmp95;
    TNode<HeapObject> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<FixedArrayBase> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<FixedArray> tmp100;
    TNode<Smi> tmp101;
    TNode<Smi> tmp102;
    TNode<Smi> tmp103;
    TNode<Smi> tmp104;
    ca_.Bind(&block14, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
    TNode<Smi> tmp105;
    USE(tmp105);
    tmp105 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp106;
    USE(tmp106);
    tmp106 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp104}, TNode<Smi>{tmp105});
    TNode<Smi> tmp107;
    USE(tmp107);
    tmp107 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp103}, TNode<Smi>{tmp107});
    TNode<Smi> tmp109;
    USE(tmp109);
    tmp109 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp103}, TNode<Smi>{tmp109});
    ca_.Branch(tmp110, &block18, &block19, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102, tmp108, tmp106, tmp104, tmp100);
  }

  if (block18.is_used()) {
    TNode<Context> tmp111;
    TNode<Smi> tmp112;
    TNode<Map> tmp113;
    TNode<Smi> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<Smi> tmp117;
    TNode<Int32T> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<FixedArray> tmp120;
    TNode<HeapObject> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<FixedArrayBase> tmp123;
    TNode<IntPtrT> tmp124;
    TNode<FixedArray> tmp125;
    TNode<Smi> tmp126;
    TNode<Smi> tmp127;
    TNode<Smi> tmp128;
    TNode<Smi> tmp129;
    TNode<Smi> tmp130;
    TNode<FixedArray> tmp131;
    ca_.Bind(&block18, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<Context> tmp132;
    TNode<Smi> tmp133;
    TNode<Map> tmp134;
    TNode<Smi> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<Smi> tmp138;
    TNode<Int32T> tmp139;
    TNode<IntPtrT> tmp140;
    TNode<FixedArray> tmp141;
    TNode<HeapObject> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<FixedArrayBase> tmp144;
    TNode<IntPtrT> tmp145;
    TNode<FixedArray> tmp146;
    TNode<Smi> tmp147;
    TNode<Smi> tmp148;
    TNode<Smi> tmp149;
    TNode<Smi> tmp150;
    TNode<Smi> tmp151;
    TNode<FixedArray> tmp152;
    ca_.Bind(&block19, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152);
    TNode<Oddball> tmp153;
    USE(tmp153);
    tmp153 = TheHole_0(state_);
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp152}, TNode<Smi>{tmp151}, TNode<Object>{tmp153});
    ca_.Goto(&block16, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150);
  }

  if (block15.is_used()) {
    TNode<Context> tmp154;
    TNode<Smi> tmp155;
    TNode<Map> tmp156;
    TNode<Smi> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<Smi> tmp160;
    TNode<Int32T> tmp161;
    TNode<IntPtrT> tmp162;
    TNode<FixedArray> tmp163;
    TNode<HeapObject> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<FixedArrayBase> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<FixedArray> tmp168;
    TNode<Smi> tmp169;
    TNode<Smi> tmp170;
    TNode<Smi> tmp171;
    TNode<Smi> tmp172;
    ca_.Bind(&block15, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172);
    ca_.Goto(&block20, tmp154, tmp163);
  }

    TNode<Context> tmp173;
    TNode<Object> tmp174;
    ca_.Bind(&block20, &tmp173, &tmp174);
  return TNode<Object>{tmp174};
}

void TestReferences_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Map> tmp0;
    USE(tmp0);
    tmp0 = CodeStubAssembler(state_).GetStructMap(SMI_PAIR_TYPE);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IntPtrConstant(((12)));
    TNode<SmiPair> tmp2;
    USE(tmp2);
    tmp2 = ca_.UncheckedCast<SmiPair>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp1}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp2, CodeStubAssembler(state_).IntPtrConstant(12), TNode<IntPtrT>{tmp1}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp3);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp3}, tmp0);
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp4}, tmp5);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(SmiPair::kBOffset);
    USE(tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp6}, tmp7);
    TNode<IntPtrT> tmp8 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp8);
    TNode<Smi>tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp8});
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp10}, TNode<Smi>{tmp9});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp8}, tmp11);
    TNode<Smi>tmp12 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp8});
    TNode<Smi> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp12}, TNode<Smi>{tmp13});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp8}, tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(SmiPair::kBOffset);
    USE(tmp15);
    TNode<HeapObject> tmp16;
    USE(tmp16);
    TNode<IntPtrT> tmp17;
    USE(tmp17);
    std::tie(tmp16, tmp17) = Method_SmiPair_GetA_0(state_, TNode<SmiPair>{tmp2}).Flatten();
    Swap_Smi_0(state_, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp2}, TNode<IntPtrT>{tmp15}, TorqueStructUnsafe_0{}}, TorqueStructReference_Smi_0{TNode<HeapObject>{tmp16}, TNode<IntPtrT>{tmp17}, TorqueStructUnsafe_0{}});
    TNode<IntPtrT> tmp18 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp18);
    TNode<Smi>tmp19 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp18});
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp19}, TNode<Smi>{tmp20});
    ca_.Branch(tmp21, &block2, &block3, tmp2, tmp2, tmp8);
  }

  if (block3.is_used()) {
    TNode<SmiPair> tmp22;
    TNode<HeapObject> tmp23;
    TNode<IntPtrT> tmp24;
    ca_.Bind(&block3, &tmp22, &tmp23, &tmp24);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.a == 2' failed", "test/torque/test-torque.tq", 840);
  }

  if (block2.is_used()) {
    TNode<SmiPair> tmp25;
    TNode<HeapObject> tmp26;
    TNode<IntPtrT> tmp27;
    ca_.Bind(&block2, &tmp25, &tmp26, &tmp27);
    TNode<IntPtrT> tmp28 = ca_.IntPtrConstant(SmiPair::kBOffset);
    USE(tmp28);
    TNode<Smi>tmp29 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp25, tmp28});
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 9);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp29}, TNode<Smi>{tmp30});
    ca_.Branch(tmp31, &block4, &block5, tmp25, tmp26, tmp27);
  }

  if (block5.is_used()) {
    TNode<SmiPair> tmp32;
    TNode<HeapObject> tmp33;
    TNode<IntPtrT> tmp34;
    ca_.Bind(&block5, &tmp32, &tmp33, &tmp34);
    CodeStubAssembler(state_).FailAssert("Torque assert 'array.b == 9' failed", "test/torque/test-torque.tq", 841);
  }

  if (block4.is_used()) {
    TNode<SmiPair> tmp35;
    TNode<HeapObject> tmp36;
    TNode<IntPtrT> tmp37;
    ca_.Bind(&block4, &tmp35, &tmp36, &tmp37);
    ca_.Goto(&block6);
  }

    ca_.Bind(&block6);
}

void TestSlices_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, Int32T> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, Int32T, Int32T> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, IntPtrT, IntPtrT, IntPtrT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, Int32T, Int32T, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi, Smi, FixedArray> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi, Smi, FixedArray> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Map, Smi, IntPtrT, IntPtrT, Smi, Int32T, IntPtrT, FixedArray, HeapObject, IntPtrT, FixedArrayBase, IntPtrT, FixedArray, Smi, Smi, Smi, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray> block21(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT> block37(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT> block45(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block53(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, FixedArray, Smi, HeapObject, IntPtrT, HeapObject, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block55(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<Smi> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Map> tmp1;
    USE(tmp1);
    tmp1 = kFixedArrayMap_0(state_);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).IntPtrConstant(((8)));
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Int32T> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_int32_constexpr_int31_0(state_, kTaggedSize);
    TNode<Int32T> tmp5;
    USE(tmp5);
    tmp5 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp3});
    TNode<Int32T> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = CodeStubAssembler(state_).TryInt32Mul(TNode<Int32T>{tmp5}, TNode<Int32T>{tmp4}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp0, tmp2, tmp2, tmp3, tmp4, tmp5, tmp5, tmp4, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp0, tmp2, tmp2, tmp3, tmp4, tmp5, tmp5, tmp4);
    }
  }

  if (block6.is_used()) {
    TNode<Smi> tmp7;
    TNode<Map> tmp8;
    TNode<Smi> tmp9;
    TNode<IntPtrT> tmp10;
    TNode<IntPtrT> tmp11;
    TNode<Smi> tmp12;
    TNode<Int32T> tmp13;
    TNode<Int32T> tmp14;
    TNode<Int32T> tmp15;
    TNode<Int32T> tmp16;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block5.is_used()) {
    TNode<Smi> tmp17;
    TNode<Map> tmp18;
    TNode<Smi> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<Smi> tmp22;
    TNode<Int32T> tmp23;
    TNode<Int32T> tmp24;
    TNode<Int32T> tmp25;
    TNode<Int32T> tmp26;
    TNode<Int32T> tmp27;
    ca_.Bind(&block5, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    TNode<IntPtrT> tmp28;
    USE(tmp28);
    tmp28 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp27});
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp29 = CodeStubAssembler(state_).TryIntPtrAdd(TNode<IntPtrT>{tmp21}, TNode<IntPtrT>{tmp28}, &label0);
    ca_.Goto(&block9, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp27, tmp28, tmp21, tmp28, tmp29);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp27, tmp28, tmp21, tmp28);
    }
  }

  if (block10.is_used()) {
    TNode<Smi> tmp30;
    TNode<Map> tmp31;
    TNode<Smi> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<IntPtrT> tmp34;
    TNode<Smi> tmp35;
    TNode<Int32T> tmp36;
    TNode<Int32T> tmp37;
    TNode<Int32T> tmp38;
    TNode<IntPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<IntPtrT> tmp41;
    ca_.Bind(&block10, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block9.is_used()) {
    TNode<Smi> tmp42;
    TNode<Map> tmp43;
    TNode<Smi> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<Smi> tmp47;
    TNode<Int32T> tmp48;
    TNode<Int32T> tmp49;
    TNode<Int32T> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    ca_.Bind(&block9, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<FixedArray> tmp55;
    USE(tmp55);
    tmp55 = ca_.UncheckedCast<FixedArray>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp54}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp55, CodeStubAssembler(state_).IntPtrConstant(8), TNode<IntPtrT>{tmp54}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp56 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp56);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp55, tmp56}, tmp43);
    TNode<IntPtrT> tmp57 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp57);
    TNode<Smi> tmp58;
    USE(tmp58);
    tmp58 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp55, tmp57}, tmp58);
    TNode<Smi> tmp59;
    USE(tmp59);
    tmp59 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp60;
    USE(tmp60);
    tmp60 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block16, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48, tmp54, tmp55, tmp55, tmp56, tmp55, tmp57, tmp55, tmp59, tmp44, tmp44, tmp60);
  }

  if (block16.is_used()) {
    TNode<Smi> tmp61;
    TNode<Map> tmp62;
    TNode<Smi> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<Smi> tmp66;
    TNode<Int32T> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<FixedArray> tmp69;
    TNode<HeapObject> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<FixedArrayBase> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<FixedArray> tmp74;
    TNode<Smi> tmp75;
    TNode<Smi> tmp76;
    TNode<Smi> tmp77;
    TNode<Smi> tmp78;
    ca_.Bind(&block16, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78);
    TNode<BoolT> tmp79;
    USE(tmp79);
    tmp79 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp78}, TNode<Smi>{tmp75});
    ca_.Branch(tmp79, &block14, &block15, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78);
  }

  if (block14.is_used()) {
    TNode<Smi> tmp80;
    TNode<Map> tmp81;
    TNode<Smi> tmp82;
    TNode<IntPtrT> tmp83;
    TNode<IntPtrT> tmp84;
    TNode<Smi> tmp85;
    TNode<Int32T> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<FixedArray> tmp88;
    TNode<HeapObject> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<FixedArrayBase> tmp91;
    TNode<IntPtrT> tmp92;
    TNode<FixedArray> tmp93;
    TNode<Smi> tmp94;
    TNode<Smi> tmp95;
    TNode<Smi> tmp96;
    TNode<Smi> tmp97;
    ca_.Bind(&block14, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    TNode<Smi> tmp98;
    USE(tmp98);
    tmp98 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp99;
    USE(tmp99);
    tmp99 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp97}, TNode<Smi>{tmp98});
    TNode<Smi> tmp100;
    USE(tmp100);
    tmp100 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp96}, TNode<Smi>{tmp100});
    TNode<Smi> tmp102;
    USE(tmp102);
    tmp102 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp103;
    USE(tmp103);
    tmp103 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp96}, TNode<Smi>{tmp102});
    ca_.Branch(tmp103, &block18, &block19, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp101, tmp99, tmp97, tmp93);
  }

  if (block18.is_used()) {
    TNode<Smi> tmp104;
    TNode<Map> tmp105;
    TNode<Smi> tmp106;
    TNode<IntPtrT> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<Smi> tmp109;
    TNode<Int32T> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<FixedArray> tmp112;
    TNode<HeapObject> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<FixedArrayBase> tmp115;
    TNode<IntPtrT> tmp116;
    TNode<FixedArray> tmp117;
    TNode<Smi> tmp118;
    TNode<Smi> tmp119;
    TNode<Smi> tmp120;
    TNode<Smi> tmp121;
    TNode<Smi> tmp122;
    TNode<FixedArray> tmp123;
    ca_.Bind(&block18, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block19.is_used()) {
    TNode<Smi> tmp124;
    TNode<Map> tmp125;
    TNode<Smi> tmp126;
    TNode<IntPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<Smi> tmp129;
    TNode<Int32T> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<FixedArray> tmp132;
    TNode<HeapObject> tmp133;
    TNode<IntPtrT> tmp134;
    TNode<FixedArrayBase> tmp135;
    TNode<IntPtrT> tmp136;
    TNode<FixedArray> tmp137;
    TNode<Smi> tmp138;
    TNode<Smi> tmp139;
    TNode<Smi> tmp140;
    TNode<Smi> tmp141;
    TNode<Smi> tmp142;
    TNode<FixedArray> tmp143;
    ca_.Bind(&block19, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
    TNode<Oddball> tmp144;
    USE(tmp144);
    tmp144 = TheHole_0(state_);
    StoreFixedArrayDirect_0(state_, TNode<FixedArray>{tmp143}, TNode<Smi>{tmp142}, TNode<Object>{tmp144});
    ca_.Goto(&block16, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp141);
  }

  if (block15.is_used()) {
    TNode<Smi> tmp145;
    TNode<Map> tmp146;
    TNode<Smi> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<Smi> tmp150;
    TNode<Int32T> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<FixedArray> tmp153;
    TNode<HeapObject> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<FixedArrayBase> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<FixedArray> tmp158;
    TNode<Smi> tmp159;
    TNode<Smi> tmp160;
    TNode<Smi> tmp161;
    TNode<Smi> tmp162;
    ca_.Bind(&block15, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162);
    TNode<IntPtrT> tmp163 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp163);
    TNode<Smi>tmp164 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp153, tmp163});
    TNode<Smi> tmp165;
    USE(tmp165);
    tmp165 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp166;
    USE(tmp166);
    tmp166 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp164}, TNode<Smi>{tmp165});
    ca_.Branch(tmp166, &block20, &block21, tmp145, tmp153);
  }

  if (block21.is_used()) {
    TNode<Smi> tmp167;
    TNode<FixedArray> tmp168;
    ca_.Bind(&block21, &tmp167, &tmp168);
    CodeStubAssembler(state_).FailAssert("Torque assert 'a.length == 3' failed", "test/torque/test-torque.tq", 848);
  }

  if (block20.is_used()) {
    TNode<Smi> tmp169;
    TNode<FixedArray> tmp170;
    ca_.Bind(&block20, &tmp169, &tmp170);
    TNode<Smi> tmp171;
    USE(tmp171);
    tmp171 = Convert_Smi_constexpr_int31_0(state_, 123);
    TNode<IntPtrT> tmp172 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp172);
    TNode<IntPtrT> tmp173 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp173);
    TNode<Smi>tmp174 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp170, tmp173});
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp174});
    TNode<IntPtrT> tmp176;
    USE(tmp176);
    tmp176 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp177;
    USE(tmp177);
    tmp177 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp176});
    TNode<UintPtrT> tmp178;
    USE(tmp178);
    tmp178 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp175});
    TNode<BoolT> tmp179;
    USE(tmp179);
    tmp179 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp177}, TNode<UintPtrT>{tmp178});
    ca_.Branch(tmp179, &block26, &block27, tmp169, tmp170, tmp171, tmp170, tmp172, tmp175, tmp176, tmp170, tmp172, tmp175, tmp176, tmp176);
  }

  if (block26.is_used()) {
    TNode<Smi> tmp180;
    TNode<FixedArray> tmp181;
    TNode<Smi> tmp182;
    TNode<FixedArray> tmp183;
    TNode<IntPtrT> tmp184;
    TNode<IntPtrT> tmp185;
    TNode<IntPtrT> tmp186;
    TNode<HeapObject> tmp187;
    TNode<IntPtrT> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<IntPtrT> tmp191;
    ca_.Bind(&block26, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191);
    TNode<IntPtrT> tmp192;
    USE(tmp192);
    tmp192 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp193;
    USE(tmp193);
    tmp193 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp191}, TNode<IntPtrT>{tmp192});
    TNode<IntPtrT> tmp194;
    USE(tmp194);
    tmp194 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp188}, TNode<IntPtrT>{tmp193});
    TNode<HeapObject> tmp195;
    USE(tmp195);
    TNode<IntPtrT> tmp196;
    USE(tmp196);
    std::tie(tmp195, tmp196) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp187}, TNode<IntPtrT>{tmp194}).Flatten();
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp195, tmp196}, tmp182);
    TNode<IntPtrT> tmp197 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp197);
    TNode<IntPtrT> tmp198 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp198);
    TNode<Smi>tmp199 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp181, tmp198});
    TNode<IntPtrT> tmp200;
    USE(tmp200);
    tmp200 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp199});
    TNode<IntPtrT> tmp201;
    USE(tmp201);
    tmp201 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp202;
    USE(tmp202);
    tmp202 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp201});
    TNode<UintPtrT> tmp203;
    USE(tmp203);
    tmp203 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp200});
    TNode<BoolT> tmp204;
    USE(tmp204);
    tmp204 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp202}, TNode<UintPtrT>{tmp203});
    ca_.Branch(tmp204, &block33, &block34, tmp180, tmp181, tmp182, tmp181, tmp197, tmp200, tmp201, tmp181, tmp197, tmp200, tmp201, tmp201);
  }

  if (block27.is_used()) {
    TNode<Smi> tmp205;
    TNode<FixedArray> tmp206;
    TNode<Smi> tmp207;
    TNode<FixedArray> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    TNode<HeapObject> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<IntPtrT> tmp214;
    TNode<IntPtrT> tmp215;
    TNode<IntPtrT> tmp216;
    ca_.Bind(&block27, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Smi> tmp217;
    TNode<FixedArray> tmp218;
    TNode<Smi> tmp219;
    TNode<FixedArray> tmp220;
    TNode<IntPtrT> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<IntPtrT> tmp223;
    TNode<HeapObject> tmp224;
    TNode<IntPtrT> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<IntPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    ca_.Bind(&block33, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228);
    TNode<IntPtrT> tmp229;
    USE(tmp229);
    tmp229 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp230;
    USE(tmp230);
    tmp230 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp228}, TNode<IntPtrT>{tmp229});
    TNode<IntPtrT> tmp231;
    USE(tmp231);
    tmp231 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp225}, TNode<IntPtrT>{tmp230});
    TNode<HeapObject> tmp232;
    USE(tmp232);
    TNode<IntPtrT> tmp233;
    USE(tmp233);
    std::tie(tmp232, tmp233) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp224}, TNode<IntPtrT>{tmp231}).Flatten();
    TNode<Object>tmp234 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp232, tmp233});
    TNode<BoolT> tmp235;
    USE(tmp235);
    tmp235 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp234}, TNode<MaybeObject>{tmp219});
    ca_.Branch(tmp235, &block36, &block37, tmp217, tmp218, tmp219, tmp232, tmp233);
  }

  if (block34.is_used()) {
    TNode<Smi> tmp236;
    TNode<FixedArray> tmp237;
    TNode<Smi> tmp238;
    TNode<FixedArray> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<IntPtrT> tmp241;
    TNode<IntPtrT> tmp242;
    TNode<HeapObject> tmp243;
    TNode<IntPtrT> tmp244;
    TNode<IntPtrT> tmp245;
    TNode<IntPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    ca_.Bind(&block34, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block37.is_used()) {
    TNode<Smi> tmp248;
    TNode<FixedArray> tmp249;
    TNode<Smi> tmp250;
    TNode<HeapObject> tmp251;
    TNode<IntPtrT> tmp252;
    ca_.Bind(&block37, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRef, oneTwoThree)' failed", "test/torque/test-torque.tq", 853);
  }

  if (block36.is_used()) {
    TNode<Smi> tmp253;
    TNode<FixedArray> tmp254;
    TNode<Smi> tmp255;
    TNode<HeapObject> tmp256;
    TNode<IntPtrT> tmp257;
    ca_.Bind(&block36, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257);
    TNode<IntPtrT> tmp258 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp258);
    TNode<IntPtrT> tmp259 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp259);
    TNode<Smi>tmp260 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp254, tmp259});
    TNode<IntPtrT> tmp261;
    USE(tmp261);
    tmp261 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp260});
    TNode<IntPtrT> tmp262;
    USE(tmp262);
    tmp262 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp263;
    USE(tmp263);
    tmp263 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp262});
    TNode<UintPtrT> tmp264;
    USE(tmp264);
    tmp264 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp261});
    TNode<BoolT> tmp265;
    USE(tmp265);
    tmp265 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp263}, TNode<UintPtrT>{tmp264});
    ca_.Branch(tmp265, &block41, &block42, tmp253, tmp254, tmp255, tmp256, tmp257, tmp254, tmp258, tmp261, tmp254, tmp258, tmp261, tmp262);
  }

  if (block41.is_used()) {
    TNode<Smi> tmp266;
    TNode<FixedArray> tmp267;
    TNode<Smi> tmp268;
    TNode<HeapObject> tmp269;
    TNode<IntPtrT> tmp270;
    TNode<HeapObject> tmp271;
    TNode<IntPtrT> tmp272;
    TNode<IntPtrT> tmp273;
    TNode<HeapObject> tmp274;
    TNode<IntPtrT> tmp275;
    TNode<IntPtrT> tmp276;
    TNode<IntPtrT> tmp277;
    ca_.Bind(&block41, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277);
    TNode<IntPtrT> tmp278;
    USE(tmp278);
    tmp278 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp279;
    USE(tmp279);
    tmp279 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp277}, TNode<IntPtrT>{tmp278});
    TNode<IntPtrT> tmp280;
    USE(tmp280);
    tmp280 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp275}, TNode<IntPtrT>{tmp279});
    TNode<HeapObject> tmp281;
    USE(tmp281);
    TNode<IntPtrT> tmp282;
    USE(tmp282);
    std::tie(tmp281, tmp282) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp274}, TNode<IntPtrT>{tmp280}).Flatten();
    TNode<Object>tmp283 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp281, tmp282});
    TNode<BoolT> tmp284;
    USE(tmp284);
    tmp284 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp283}, TNode<MaybeObject>{tmp268});
    ca_.Branch(tmp284, &block44, &block45, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp281, tmp282);
  }

  if (block42.is_used()) {
    TNode<Smi> tmp285;
    TNode<FixedArray> tmp286;
    TNode<Smi> tmp287;
    TNode<HeapObject> tmp288;
    TNode<IntPtrT> tmp289;
    TNode<HeapObject> tmp290;
    TNode<IntPtrT> tmp291;
    TNode<IntPtrT> tmp292;
    TNode<HeapObject> tmp293;
    TNode<IntPtrT> tmp294;
    TNode<IntPtrT> tmp295;
    TNode<IntPtrT> tmp296;
    ca_.Bind(&block42, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block45.is_used()) {
    TNode<Smi> tmp297;
    TNode<FixedArray> tmp298;
    TNode<Smi> tmp299;
    TNode<HeapObject> tmp300;
    TNode<IntPtrT> tmp301;
    TNode<HeapObject> tmp302;
    TNode<IntPtrT> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<HeapObject> tmp305;
    TNode<IntPtrT> tmp306;
    ca_.Bind(&block45, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(* firstRefAgain, oneTwoThree)' failed", "test/torque/test-torque.tq", 857);
  }

  if (block44.is_used()) {
    TNode<Smi> tmp307;
    TNode<FixedArray> tmp308;
    TNode<Smi> tmp309;
    TNode<HeapObject> tmp310;
    TNode<IntPtrT> tmp311;
    TNode<HeapObject> tmp312;
    TNode<IntPtrT> tmp313;
    TNode<IntPtrT> tmp314;
    TNode<HeapObject> tmp315;
    TNode<IntPtrT> tmp316;
    ca_.Bind(&block44, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316);
    TNode<Smi> tmp317;
    USE(tmp317);
    tmp317 = Convert_Smi_constexpr_int31_0(state_, 321);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp315, tmp316}, tmp317);
    TNode<IntPtrT> tmp318 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp318);
    TNode<IntPtrT> tmp319 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp319);
    TNode<Smi>tmp320 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp308, tmp319});
    TNode<IntPtrT> tmp321;
    USE(tmp321);
    tmp321 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp320});
    TNode<IntPtrT> tmp322;
    USE(tmp322);
    tmp322 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp323;
    USE(tmp323);
    tmp323 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp322});
    TNode<UintPtrT> tmp324;
    USE(tmp324);
    tmp324 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp321});
    TNode<BoolT> tmp325;
    USE(tmp325);
    tmp325 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp323}, TNode<UintPtrT>{tmp324});
    ca_.Branch(tmp325, &block52, &block53, tmp307, tmp308, tmp309, tmp310, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp308, tmp318, tmp321, tmp322, tmp308, tmp318, tmp321, tmp322, tmp322);
  }

  if (block52.is_used()) {
    TNode<Smi> tmp326;
    TNode<FixedArray> tmp327;
    TNode<Smi> tmp328;
    TNode<HeapObject> tmp329;
    TNode<IntPtrT> tmp330;
    TNode<HeapObject> tmp331;
    TNode<IntPtrT> tmp332;
    TNode<IntPtrT> tmp333;
    TNode<HeapObject> tmp334;
    TNode<IntPtrT> tmp335;
    TNode<Smi> tmp336;
    TNode<FixedArray> tmp337;
    TNode<IntPtrT> tmp338;
    TNode<IntPtrT> tmp339;
    TNode<IntPtrT> tmp340;
    TNode<HeapObject> tmp341;
    TNode<IntPtrT> tmp342;
    TNode<IntPtrT> tmp343;
    TNode<IntPtrT> tmp344;
    TNode<IntPtrT> tmp345;
    ca_.Bind(&block52, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345);
    TNode<IntPtrT> tmp346;
    USE(tmp346);
    tmp346 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp347;
    USE(tmp347);
    tmp347 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp345}, TNode<IntPtrT>{tmp346});
    TNode<IntPtrT> tmp348;
    USE(tmp348);
    tmp348 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp342}, TNode<IntPtrT>{tmp347});
    TNode<HeapObject> tmp349;
    USE(tmp349);
    TNode<IntPtrT> tmp350;
    USE(tmp350);
    std::tie(tmp349, tmp350) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp341}, TNode<IntPtrT>{tmp348}).Flatten();
    TNode<Object>tmp351 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp349, tmp350});
    TNode<BoolT> tmp352;
    USE(tmp352);
    tmp352 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp351}, TNode<MaybeObject>{tmp336});
    ca_.Branch(tmp352, &block46, &block47, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335, tmp336);
  }

  if (block53.is_used()) {
    TNode<Smi> tmp353;
    TNode<FixedArray> tmp354;
    TNode<Smi> tmp355;
    TNode<HeapObject> tmp356;
    TNode<IntPtrT> tmp357;
    TNode<HeapObject> tmp358;
    TNode<IntPtrT> tmp359;
    TNode<IntPtrT> tmp360;
    TNode<HeapObject> tmp361;
    TNode<IntPtrT> tmp362;
    TNode<Smi> tmp363;
    TNode<FixedArray> tmp364;
    TNode<IntPtrT> tmp365;
    TNode<IntPtrT> tmp366;
    TNode<IntPtrT> tmp367;
    TNode<HeapObject> tmp368;
    TNode<IntPtrT> tmp369;
    TNode<IntPtrT> tmp370;
    TNode<IntPtrT> tmp371;
    TNode<IntPtrT> tmp372;
    ca_.Bind(&block53, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block47.is_used()) {
    TNode<Smi> tmp373;
    TNode<FixedArray> tmp374;
    TNode<Smi> tmp375;
    TNode<HeapObject> tmp376;
    TNode<IntPtrT> tmp377;
    TNode<HeapObject> tmp378;
    TNode<IntPtrT> tmp379;
    TNode<IntPtrT> tmp380;
    TNode<HeapObject> tmp381;
    TNode<IntPtrT> tmp382;
    TNode<Smi> tmp383;
    ca_.Bind(&block47, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383);
    CodeStubAssembler(state_).FailAssert("Torque assert 'TaggedEqual(a.objects[0], threeTwoOne)' failed", "test/torque/test-torque.tq", 861);
  }

  if (block46.is_used()) {
    TNode<Smi> tmp384;
    TNode<FixedArray> tmp385;
    TNode<Smi> tmp386;
    TNode<HeapObject> tmp387;
    TNode<IntPtrT> tmp388;
    TNode<HeapObject> tmp389;
    TNode<IntPtrT> tmp390;
    TNode<IntPtrT> tmp391;
    TNode<HeapObject> tmp392;
    TNode<IntPtrT> tmp393;
    TNode<Smi> tmp394;
    ca_.Bind(&block46, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391, &tmp392, &tmp393, &tmp394);
    ca_.Goto(&block55);
  }

    ca_.Bind(&block55);
}

TNode<Oddball> TestSliceEnumeration_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block33(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, Smi> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, Smi> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi, HeapObject, IntPtrT, Smi> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block48(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block50(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, Smi> block49(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Oddball> block52(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).AllocateZeroedFixedArray(TNode<IntPtrT>{tmp1});
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp2, tmp3);
  }

  if (block4.is_used()) {
    TNode<Context> tmp4;
    TNode<FixedArray> tmp5;
    TNode<IntPtrT> tmp6;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6);
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp6}, TNode<IntPtrT>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp4, tmp5, tmp6);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<FixedArray> tmp10;
    TNode<IntPtrT> tmp11;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp12);
    TNode<IntPtrT> tmp13 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp13);
    TNode<Smi>tmp14 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp13});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp14});
    TNode<UintPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    TNode<UintPtrT> tmp17;
    USE(tmp17);
    tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp15});
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp16}, TNode<UintPtrT>{tmp17});
    ca_.Branch(tmp18, &block12, &block13, tmp9, tmp10, tmp11, tmp10, tmp12, tmp15, tmp11, tmp11, tmp10, tmp12, tmp15, tmp11, tmp11);
  }

  if (block12.is_used()) {
    TNode<Context> tmp19;
    TNode<FixedArray> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<FixedArray> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<HeapObject> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    ca_.Bind(&block12, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp31}, TNode<IntPtrT>{tmp32});
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp28}, TNode<IntPtrT>{tmp33});
    TNode<HeapObject> tmp35;
    USE(tmp35);
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    std::tie(tmp35, tmp36) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp27}, TNode<IntPtrT>{tmp34}).Flatten();
    TNode<Object>tmp37 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp35, tmp36});
    TNode<Smi> tmp38;
    USE(tmp38);
    tmp38 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp19}, TNode<Object>{tmp37});
    TNode<Smi> tmp39;
    USE(tmp39);
    tmp39 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp38}, TNode<Smi>{tmp39});
    ca_.Branch(tmp40, &block6, &block7, tmp19, tmp20, tmp21);
  }

  if (block13.is_used()) {
    TNode<Context> tmp41;
    TNode<FixedArray> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<FixedArray> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<HeapObject> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    ca_.Bind(&block13, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block7.is_used()) {
    TNode<Context> tmp54;
    TNode<FixedArray> tmp55;
    TNode<IntPtrT> tmp56;
    ca_.Bind(&block7, &tmp54, &tmp55, &tmp56);
    CodeStubAssembler(state_).FailAssert("Torque assert 'UnsafeCast<Smi>(fixedArray.objects[i]) == 0' failed", "test/torque/test-torque.tq", 876);
  }

  if (block6.is_used()) {
    TNode<Context> tmp57;
    TNode<FixedArray> tmp58;
    TNode<IntPtrT> tmp59;
    ca_.Bind(&block6, &tmp57, &tmp58, &tmp59);
    TNode<IntPtrT> tmp60 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp60);
    TNode<IntPtrT> tmp61 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp61);
    TNode<Smi>tmp62 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp58, tmp61});
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp62});
    TNode<UintPtrT> tmp64;
    USE(tmp64);
    tmp64 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp59});
    TNode<UintPtrT> tmp65;
    USE(tmp65);
    tmp65 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp63});
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp64}, TNode<UintPtrT>{tmp65});
    ca_.Branch(tmp66, &block19, &block20, tmp57, tmp58, tmp59, tmp58, tmp60, tmp63, tmp59, tmp59, tmp58, tmp60, tmp63, tmp59, tmp59);
  }

  if (block19.is_used()) {
    TNode<Context> tmp67;
    TNode<FixedArray> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<FixedArray> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<HeapObject> tmp75;
    TNode<IntPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    ca_.Bind(&block19, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    tmp80 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp79}, TNode<IntPtrT>{tmp80});
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp76}, TNode<IntPtrT>{tmp81});
    TNode<HeapObject> tmp83;
    USE(tmp83);
    TNode<IntPtrT> tmp84;
    USE(tmp84);
    std::tie(tmp83, tmp84) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp75}, TNode<IntPtrT>{tmp82}).Flatten();
    TNode<Smi> tmp85;
    USE(tmp85);
    tmp85 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp69});
    TNode<Smi> tmp86;
    USE(tmp86);
    tmp86 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp87;
    USE(tmp87);
    tmp87 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp85}, TNode<Smi>{tmp86});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp83, tmp84}, tmp87);
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp89;
    USE(tmp89);
    tmp89 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp69}, TNode<IntPtrT>{tmp88});
    ca_.Goto(&block4, tmp67, tmp68, tmp89);
  }

  if (block20.is_used()) {
    TNode<Context> tmp90;
    TNode<FixedArray> tmp91;
    TNode<IntPtrT> tmp92;
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
    ca_.Bind(&block20, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<Context> tmp103;
    TNode<FixedArray> tmp104;
    TNode<IntPtrT> tmp105;
    ca_.Bind(&block3, &tmp103, &tmp104, &tmp105);
    TNode<IntPtrT> tmp106 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp106);
    TNode<IntPtrT> tmp107 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp107);
    TNode<Smi>tmp108 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp104, tmp107});
    TNode<IntPtrT> tmp109;
    USE(tmp109);
    tmp109 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp108});
    TNode<IntPtrT> tmp110;
    USE(tmp110);
    tmp110 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    ca_.Goto(&block24, tmp103, tmp104, tmp104, tmp106, tmp109, tmp110);
  }

  if (block24.is_used()) {
    TNode<Context> tmp111;
    TNode<FixedArray> tmp112;
    TNode<FixedArray> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<IntPtrT> tmp116;
    ca_.Bind(&block24, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    TNode<BoolT> tmp117;
    USE(tmp117);
    tmp117 = CodeStubAssembler(state_).IntPtrLessThan(TNode<IntPtrT>{tmp116}, TNode<IntPtrT>{tmp115});
    ca_.Branch(tmp117, &block22, &block23, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116);
  }

  if (block22.is_used()) {
    TNode<Context> tmp118;
    TNode<FixedArray> tmp119;
    TNode<FixedArray> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<IntPtrT> tmp123;
    ca_.Bind(&block22, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123);
    TNode<UintPtrT> tmp124;
    USE(tmp124);
    tmp124 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp123});
    TNode<UintPtrT> tmp125;
    USE(tmp125);
    tmp125 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp122});
    TNode<BoolT> tmp126;
    USE(tmp126);
    tmp126 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp124}, TNode<UintPtrT>{tmp125});
    ca_.Branch(tmp126, &block29, &block30, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp123, tmp123);
  }

  if (block29.is_used()) {
    TNode<Context> tmp127;
    TNode<FixedArray> tmp128;
    TNode<FixedArray> tmp129;
    TNode<IntPtrT> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<IntPtrT> tmp132;
    TNode<IntPtrT> tmp133;
    TNode<IntPtrT> tmp134;
    ca_.Bind(&block29, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134);
    TNode<IntPtrT> tmp135;
    USE(tmp135);
    tmp135 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp136;
    USE(tmp136);
    tmp136 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp134}, TNode<IntPtrT>{tmp135});
    TNode<IntPtrT> tmp137;
    USE(tmp137);
    tmp137 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp130}, TNode<IntPtrT>{tmp136});
    TNode<HeapObject> tmp138;
    USE(tmp138);
    TNode<IntPtrT> tmp139;
    USE(tmp139);
    std::tie(tmp138, tmp139) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp129}, TNode<IntPtrT>{tmp137}).Flatten();
    TNode<Object>tmp140 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp138, tmp139});
    TNode<Smi> tmp141;
    USE(tmp141);
    tmp141 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp127}, TNode<Object>{tmp140});
    TNode<Smi> tmp142;
    USE(tmp142);
    tmp142 = Convert_Smi_intptr_0(state_, TNode<IntPtrT>{tmp132});
    TNode<Smi> tmp143;
    USE(tmp143);
    tmp143 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<Smi> tmp144;
    USE(tmp144);
    tmp144 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp142}, TNode<Smi>{tmp143});
    TNode<BoolT> tmp145;
    USE(tmp145);
    tmp145 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp141}, TNode<Smi>{tmp144});
    ca_.Branch(tmp145, &block32, &block33, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp138, tmp139, tmp141);
  }

  if (block30.is_used()) {
    TNode<Context> tmp146;
    TNode<FixedArray> tmp147;
    TNode<FixedArray> tmp148;
    TNode<IntPtrT> tmp149;
    TNode<IntPtrT> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<IntPtrT> tmp152;
    TNode<IntPtrT> tmp153;
    ca_.Bind(&block30, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block33.is_used()) {
    TNode<Context> tmp154;
    TNode<FixedArray> tmp155;
    TNode<FixedArray> tmp156;
    TNode<IntPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<HeapObject> tmp160;
    TNode<IntPtrT> tmp161;
    TNode<Smi> tmp162;
    ca_.Bind(&block33, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == Convert<Smi>(i) + 3' failed", "test/torque/test-torque.tq", 884);
  }

  if (block32.is_used()) {
    TNode<Context> tmp163;
    TNode<FixedArray> tmp164;
    TNode<FixedArray> tmp165;
    TNode<IntPtrT> tmp166;
    TNode<IntPtrT> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<HeapObject> tmp169;
    TNode<IntPtrT> tmp170;
    TNode<Smi> tmp171;
    ca_.Bind(&block32, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171);
    TNode<Smi> tmp172;
    USE(tmp172);
    tmp172 = FromConstexpr_Smi_constexpr_int31_0(state_, 4);
    TNode<Smi> tmp173;
    USE(tmp173);
    tmp173 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp171}, TNode<Smi>{tmp172});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp169, tmp170}, tmp173);
    TNode<IntPtrT> tmp174;
    USE(tmp174);
    tmp174 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp168}, TNode<IntPtrT>{tmp174});
    ca_.Goto(&block24, tmp163, tmp164, tmp165, tmp166, tmp167, tmp175);
  }

  if (block23.is_used()) {
    TNode<Context> tmp176;
    TNode<FixedArray> tmp177;
    TNode<FixedArray> tmp178;
    TNode<IntPtrT> tmp179;
    TNode<IntPtrT> tmp180;
    TNode<IntPtrT> tmp181;
    ca_.Bind(&block23, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181);
    TNode<IntPtrT> tmp182;
    USE(tmp182);
    tmp182 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp183;
    USE(tmp183);
    tmp183 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp180}, TNode<IntPtrT>{tmp182});
    TNode<IntPtrT> tmp184;
    USE(tmp184);
    tmp184 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp179}, TNode<IntPtrT>{tmp183});
    TNode<Smi> tmp185;
    USE(tmp185);
    tmp185 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block37, tmp176, tmp177, tmp178, tmp179, tmp180, tmp178, tmp179, tmp184, tmp185);
  }

  if (block37.is_used()) {
    TNode<Context> tmp186;
    TNode<FixedArray> tmp187;
    TNode<FixedArray> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<HeapObject> tmp191;
    TNode<IntPtrT> tmp192;
    TNode<IntPtrT> tmp193;
    TNode<Smi> tmp194;
    ca_.Bind(&block37, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194);
    TNode<BoolT> tmp195;
    USE(tmp195);
    tmp195 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Branch(tmp195, &block35, &block36, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191, tmp192, tmp193, tmp194);
  }

  if (block35.is_used()) {
    TNode<Context> tmp196;
    TNode<FixedArray> tmp197;
    TNode<FixedArray> tmp198;
    TNode<IntPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<HeapObject> tmp201;
    TNode<IntPtrT> tmp202;
    TNode<IntPtrT> tmp203;
    TNode<Smi> tmp204;
    ca_.Bind(&block35, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204);
    TNode<BoolT> tmp205;
    USE(tmp205);
    tmp205 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp202}, TNode<IntPtrT>{tmp203});
    ca_.Branch(tmp205, &block41, &block42, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204);
  }

  if (block41.is_used()) {
    TNode<Context> tmp206;
    TNode<FixedArray> tmp207;
    TNode<FixedArray> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<HeapObject> tmp211;
    TNode<IntPtrT> tmp212;
    TNode<IntPtrT> tmp213;
    TNode<Smi> tmp214;
    ca_.Bind(&block41, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214);
    ca_.Goto(&block36, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214);
  }

  if (block42.is_used()) {
    TNode<Context> tmp215;
    TNode<FixedArray> tmp216;
    TNode<FixedArray> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<IntPtrT> tmp219;
    TNode<HeapObject> tmp220;
    TNode<IntPtrT> tmp221;
    TNode<IntPtrT> tmp222;
    TNode<Smi> tmp223;
    ca_.Bind(&block42, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223);
    TNode<HeapObject> tmp224;
    USE(tmp224);
    TNode<IntPtrT> tmp225;
    USE(tmp225);
    std::tie(tmp224, tmp225) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp220}, TNode<IntPtrT>{tmp221}).Flatten();
    TNode<IntPtrT> tmp226;
    USE(tmp226);
    tmp226 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp227;
    USE(tmp227);
    tmp227 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp221}, TNode<IntPtrT>{tmp226});
    TNode<Object>tmp228 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp224, tmp225});
    TNode<Smi> tmp229;
    USE(tmp229);
    tmp229 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp215}, TNode<Object>{tmp228});
    TNode<Smi> tmp230;
    USE(tmp230);
    tmp230 = FromConstexpr_Smi_constexpr_int31_0(state_, 7);
    TNode<Smi> tmp231;
    USE(tmp231);
    tmp231 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp223}, TNode<Smi>{tmp230});
    TNode<BoolT> tmp232;
    USE(tmp232);
    tmp232 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp229}, TNode<Smi>{tmp231});
    ca_.Branch(tmp232, &block45, &block46, tmp215, tmp216, tmp217, tmp218, tmp219, tmp220, tmp227, tmp222, tmp223, tmp224, tmp225, tmp229);
  }

  if (block46.is_used()) {
    TNode<Context> tmp233;
    TNode<FixedArray> tmp234;
    TNode<FixedArray> tmp235;
    TNode<IntPtrT> tmp236;
    TNode<IntPtrT> tmp237;
    TNode<HeapObject> tmp238;
    TNode<IntPtrT> tmp239;
    TNode<IntPtrT> tmp240;
    TNode<Smi> tmp241;
    TNode<HeapObject> tmp242;
    TNode<IntPtrT> tmp243;
    TNode<Smi> tmp244;
    ca_.Bind(&block46, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value == count + 7' failed", "test/torque/test-torque.tq", 893);
  }

  if (block45.is_used()) {
    TNode<Context> tmp245;
    TNode<FixedArray> tmp246;
    TNode<FixedArray> tmp247;
    TNode<IntPtrT> tmp248;
    TNode<IntPtrT> tmp249;
    TNode<HeapObject> tmp250;
    TNode<IntPtrT> tmp251;
    TNode<IntPtrT> tmp252;
    TNode<Smi> tmp253;
    TNode<HeapObject> tmp254;
    TNode<IntPtrT> tmp255;
    TNode<Smi> tmp256;
    ca_.Bind(&block45, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256);
    TNode<Smi> tmp257;
    USE(tmp257);
    tmp257 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp258;
    USE(tmp258);
    tmp258 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp253}, TNode<Smi>{tmp257});
    ca_.Goto(&block37, tmp245, tmp246, tmp247, tmp248, tmp249, tmp250, tmp251, tmp252, tmp258);
  }

  if (block36.is_used()) {
    TNode<Context> tmp259;
    TNode<FixedArray> tmp260;
    TNode<FixedArray> tmp261;
    TNode<IntPtrT> tmp262;
    TNode<IntPtrT> tmp263;
    TNode<HeapObject> tmp264;
    TNode<IntPtrT> tmp265;
    TNode<IntPtrT> tmp266;
    TNode<Smi> tmp267;
    ca_.Bind(&block36, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267);
    TNode<Smi> tmp268;
    USE(tmp268);
    tmp268 = FromConstexpr_Smi_constexpr_int31_0(state_, 3);
    TNode<BoolT> tmp269;
    USE(tmp269);
    tmp269 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp267}, TNode<Smi>{tmp268});
    ca_.Branch(tmp269, &block47, &block48, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267);
  }

  if (block48.is_used()) {
    TNode<Context> tmp270;
    TNode<FixedArray> tmp271;
    TNode<FixedArray> tmp272;
    TNode<IntPtrT> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<HeapObject> tmp275;
    TNode<IntPtrT> tmp276;
    TNode<IntPtrT> tmp277;
    TNode<Smi> tmp278;
    ca_.Bind(&block48, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277, &tmp278);
    CodeStubAssembler(state_).FailAssert("Torque assert 'count == 3' failed", "test/torque/test-torque.tq", 896);
  }

  if (block47.is_used()) {
    TNode<Context> tmp279;
    TNode<FixedArray> tmp280;
    TNode<FixedArray> tmp281;
    TNode<IntPtrT> tmp282;
    TNode<IntPtrT> tmp283;
    TNode<HeapObject> tmp284;
    TNode<IntPtrT> tmp285;
    TNode<IntPtrT> tmp286;
    TNode<Smi> tmp287;
    ca_.Bind(&block47, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287);
    TNode<BoolT> tmp288;
    USE(tmp288);
    tmp288 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp285}, TNode<IntPtrT>{tmp286});
    ca_.Branch(tmp288, &block49, &block50, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287);
  }

  if (block50.is_used()) {
    TNode<Context> tmp289;
    TNode<FixedArray> tmp290;
    TNode<FixedArray> tmp291;
    TNode<IntPtrT> tmp292;
    TNode<IntPtrT> tmp293;
    TNode<HeapObject> tmp294;
    TNode<IntPtrT> tmp295;
    TNode<IntPtrT> tmp296;
    TNode<Smi> tmp297;
    ca_.Bind(&block50, &tmp289, &tmp290, &tmp291, &tmp292, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297);
    CodeStubAssembler(state_).FailAssert("Torque assert 'it.Empty()' failed", "test/torque/test-torque.tq", 897);
  }

  if (block49.is_used()) {
    TNode<Context> tmp298;
    TNode<FixedArray> tmp299;
    TNode<FixedArray> tmp300;
    TNode<IntPtrT> tmp301;
    TNode<IntPtrT> tmp302;
    TNode<HeapObject> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<IntPtrT> tmp305;
    TNode<Smi> tmp306;
    ca_.Bind(&block49, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306);
    TNode<Oddball> tmp307;
    USE(tmp307);
    tmp307 = Undefined_0(state_);
    ca_.Goto(&block52, tmp298, tmp307);
  }

    TNode<Context> tmp308;
    TNode<Oddball> tmp309;
    ca_.Bind(&block52, &tmp308, &tmp309);
  return TNode<Oddball>{tmp309};
}

void TestStaticAssert_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<BoolT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal((CodeStubAssembler(state_).ConstexprInt31Add(1, 2)), 3)));
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp0});
    ca_.Goto(&block2);
  }

    ca_.Bind(&block2);
}

TF_BUILTIN(NewSmiBox, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Map> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).GetStructMap(SMI_BOX_TYPE);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).IntPtrConstant(((12)));
    TNode<SmiBox> tmp4;
    USE(tmp4);
    tmp4 = ca_.UncheckedCast<SmiBox>(CodeStubAssembler(state_).Allocate(TNode<IntPtrT>{tmp3}));
    CodeStubAssembler(state_).InitializeFieldsWithRoot(tmp4, CodeStubAssembler(state_).IntPtrConstant(12), TNode<IntPtrT>{tmp3}, RootIndex::kUndefinedValue);
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp5);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp4, tmp5}, tmp2);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp6);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp4, tmp6}, tmp1);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(SmiBox::kUnrelatedOffset);
    USE(tmp7);
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp4, tmp7}, tmp8);
    CodeStubAssembler(state_).Return(tmp4);
  }
}

void TestLoadEliminationFixed_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, SmiBox, Smi, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 123);
    TNode<SmiBox> tmp2;
    tmp2 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp1));
    USE(tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp3);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3});
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(SmiBox::kUnrelatedOffset);
    USE(tmp5);
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_Smi_constexpr_int31_0(state_, 999);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp5}, tmp6);
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(SmiBox::kUnrelatedOffset);
    USE(tmp7);
    TNode<Smi>tmp8 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp7});
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    ca_.Branch(tmp10, &block2, &block3, tmp0, tmp2, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp11;
    TNode<SmiBox> tmp12;
    TNode<Smi> tmp13;
    ca_.Bind(&block2, &tmp11, &tmp12, &tmp13);
    TNode<IntPtrT> tmp14 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp14);
    TNode<Smi>tmp15 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp14});
    ca_.Goto(&block4, tmp11, tmp12, tmp13, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp16;
    TNode<SmiBox> tmp17;
    TNode<Smi> tmp18;
    ca_.Bind(&block3, &tmp16, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp19);
    TNode<Smi>tmp20 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp17, tmp19});
    ca_.Goto(&block4, tmp16, tmp17, tmp18, tmp20);
  }

  if (block4.is_used()) {
    TNode<Context> tmp21;
    TNode<SmiBox> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    ca_.Bind(&block4, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<BoolT> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp23}, TNode<MaybeObject>{tmp24});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp25});
    TNode<IntPtrT> tmp26 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp26);
    TNode<Smi> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp22, tmp26}, tmp27);
    TNode<IntPtrT> tmp28 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp28);
    TNode<Smi>tmp29 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp22, tmp28});
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 11);
    TNode<BoolT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp29}, TNode<MaybeObject>{tmp30});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp31});
    ca_.Goto(&block6, tmp21);
  }

    TNode<Context> tmp32;
    ca_.Bind(&block6, &tmp32);
}

void TestLoadEliminationVariable_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, SmiBox, Object, Object, Object, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<FixedArray> tmp2;
    USE(tmp2);
    tmp2 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<SmiBox> tmp4;
    tmp4 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp3));
    USE(tmp4);
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp5);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp6);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp7});
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp9);
    TNode<Smi>tmp10 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp10});
    TNode<UintPtrT> tmp12;
    USE(tmp12);
    tmp12 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp11});
    TNode<UintPtrT> tmp13;
    USE(tmp13);
    tmp13 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp8});
    TNode<BoolT> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp12}, TNode<UintPtrT>{tmp13});
    ca_.Branch(tmp14, &block6, &block7, tmp0, tmp2, tmp4, tmp2, tmp5, tmp8, tmp10, tmp10, tmp11, tmp2, tmp5, tmp8, tmp11, tmp11);
  }

  if (block6.is_used()) {
    TNode<Context> tmp15;
    TNode<FixedArray> tmp16;
    TNode<SmiBox> tmp17;
    TNode<FixedArray> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<Smi> tmp21;
    TNode<Smi> tmp22;
    TNode<IntPtrT> tmp23;
    TNode<HeapObject> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<IntPtrT> tmp26;
    TNode<IntPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<IntPtrT> tmp29;
    USE(tmp29);
    tmp29 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
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
    std::tie(tmp32, tmp33) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp24}, TNode<IntPtrT>{tmp31}).Flatten();
    TNode<Object>tmp34 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp32, tmp33});
    TNode<IntPtrT> tmp35 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp35);
    TNode<IntPtrT> tmp36 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp36);
    TNode<Smi>tmp37 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp16, tmp36});
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    tmp38 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp37});
    TNode<IntPtrT> tmp39 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp39);
    TNode<Smi>tmp40 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp17, tmp39});
    TNode<Smi> tmp41;
    USE(tmp41);
    tmp41 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp42;
    USE(tmp42);
    tmp42 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp40}, TNode<Smi>{tmp41});
    TNode<IntPtrT> tmp43;
    USE(tmp43);
    tmp43 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp42});
    TNode<UintPtrT> tmp44;
    USE(tmp44);
    tmp44 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp43});
    TNode<UintPtrT> tmp45;
    USE(tmp45);
    tmp45 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp38});
    TNode<BoolT> tmp46;
    USE(tmp46);
    tmp46 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp44}, TNode<UintPtrT>{tmp45});
    ca_.Branch(tmp46, &block13, &block14, tmp15, tmp16, tmp17, tmp34, tmp16, tmp35, tmp38, tmp42, tmp42, tmp43, tmp16, tmp35, tmp38, tmp43, tmp43);
  }

  if (block7.is_used()) {
    TNode<Context> tmp47;
    TNode<FixedArray> tmp48;
    TNode<SmiBox> tmp49;
    TNode<FixedArray> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<Smi> tmp53;
    TNode<Smi> tmp54;
    TNode<IntPtrT> tmp55;
    TNode<HeapObject> tmp56;
    TNode<IntPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    ca_.Bind(&block7, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block13.is_used()) {
    TNode<Context> tmp61;
    TNode<FixedArray> tmp62;
    TNode<SmiBox> tmp63;
    TNode<Object> tmp64;
    TNode<FixedArray> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<IntPtrT> tmp67;
    TNode<Smi> tmp68;
    TNode<Smi> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<HeapObject> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<IntPtrT> tmp73;
    TNode<IntPtrT> tmp74;
    TNode<IntPtrT> tmp75;
    ca_.Bind(&block13, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<IntPtrT> tmp76;
    USE(tmp76);
    tmp76 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp77;
    USE(tmp77);
    tmp77 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp75}, TNode<IntPtrT>{tmp76});
    TNode<IntPtrT> tmp78;
    USE(tmp78);
    tmp78 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp72}, TNode<IntPtrT>{tmp77});
    TNode<HeapObject> tmp79;
    USE(tmp79);
    TNode<IntPtrT> tmp80;
    USE(tmp80);
    std::tie(tmp79, tmp80) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp71}, TNode<IntPtrT>{tmp78}).Flatten();
    TNode<Object>tmp81 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp79, tmp80});
    TNode<IntPtrT> tmp82 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp82);
    TNode<IntPtrT> tmp83 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp83);
    TNode<Smi>tmp84 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp62, tmp83});
    TNode<IntPtrT> tmp85;
    USE(tmp85);
    tmp85 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp84});
    TNode<IntPtrT> tmp86 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp86);
    TNode<Smi>tmp87 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp63, tmp86});
    TNode<IntPtrT> tmp88;
    USE(tmp88);
    tmp88 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp87});
    TNode<UintPtrT> tmp89;
    USE(tmp89);
    tmp89 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp88});
    TNode<UintPtrT> tmp90;
    USE(tmp90);
    tmp90 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp85});
    TNode<BoolT> tmp91;
    USE(tmp91);
    tmp91 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp89}, TNode<UintPtrT>{tmp90});
    ca_.Branch(tmp91, &block20, &block21, tmp61, tmp62, tmp63, tmp64, tmp81, tmp62, tmp82, tmp85, tmp87, tmp87, tmp88, tmp62, tmp82, tmp85, tmp88, tmp88);
  }

  if (block14.is_used()) {
    TNode<Context> tmp92;
    TNode<FixedArray> tmp93;
    TNode<SmiBox> tmp94;
    TNode<Object> tmp95;
    TNode<FixedArray> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<IntPtrT> tmp98;
    TNode<Smi> tmp99;
    TNode<Smi> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<HeapObject> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<IntPtrT> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    ca_.Bind(&block14, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block20.is_used()) {
    TNode<Context> tmp107;
    TNode<FixedArray> tmp108;
    TNode<SmiBox> tmp109;
    TNode<Object> tmp110;
    TNode<Object> tmp111;
    TNode<FixedArray> tmp112;
    TNode<IntPtrT> tmp113;
    TNode<IntPtrT> tmp114;
    TNode<Smi> tmp115;
    TNode<Smi> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<HeapObject> tmp118;
    TNode<IntPtrT> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<IntPtrT> tmp121;
    TNode<IntPtrT> tmp122;
    ca_.Bind(&block20, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    TNode<IntPtrT> tmp123;
    USE(tmp123);
    tmp123 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp122}, TNode<IntPtrT>{tmp123});
    TNode<IntPtrT> tmp125;
    USE(tmp125);
    tmp125 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp119}, TNode<IntPtrT>{tmp124});
    TNode<HeapObject> tmp126;
    USE(tmp126);
    TNode<IntPtrT> tmp127;
    USE(tmp127);
    std::tie(tmp126, tmp127) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp118}, TNode<IntPtrT>{tmp125}).Flatten();
    TNode<Object>tmp128 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp126, tmp127});
    TNode<IntPtrT> tmp129 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp129);
    TNode<IntPtrT> tmp130 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp130);
    TNode<Smi>tmp131 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp108, tmp130});
    TNode<IntPtrT> tmp132;
    USE(tmp132);
    tmp132 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp131});
    TNode<IntPtrT> tmp133 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp133);
    TNode<Smi>tmp134 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp109, tmp133});
    TNode<Smi> tmp135;
    USE(tmp135);
    tmp135 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp136;
    USE(tmp136);
    tmp136 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp134}, TNode<Smi>{tmp135});
    TNode<IntPtrT> tmp137;
    USE(tmp137);
    tmp137 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp136});
    TNode<UintPtrT> tmp138;
    USE(tmp138);
    tmp138 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp137});
    TNode<UintPtrT> tmp139;
    USE(tmp139);
    tmp139 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp132});
    TNode<BoolT> tmp140;
    USE(tmp140);
    tmp140 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp138}, TNode<UintPtrT>{tmp139});
    ca_.Branch(tmp140, &block27, &block28, tmp107, tmp108, tmp109, tmp110, tmp111, tmp128, tmp108, tmp129, tmp132, tmp136, tmp136, tmp137, tmp108, tmp129, tmp132, tmp137, tmp137);
  }

  if (block21.is_used()) {
    TNode<Context> tmp141;
    TNode<FixedArray> tmp142;
    TNode<SmiBox> tmp143;
    TNode<Object> tmp144;
    TNode<Object> tmp145;
    TNode<FixedArray> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<Smi> tmp149;
    TNode<Smi> tmp150;
    TNode<IntPtrT> tmp151;
    TNode<HeapObject> tmp152;
    TNode<IntPtrT> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<IntPtrT> tmp155;
    TNode<IntPtrT> tmp156;
    ca_.Bind(&block21, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    TNode<Context> tmp157;
    TNode<FixedArray> tmp158;
    TNode<SmiBox> tmp159;
    TNode<Object> tmp160;
    TNode<Object> tmp161;
    TNode<Object> tmp162;
    TNode<FixedArray> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<Smi> tmp166;
    TNode<Smi> tmp167;
    TNode<IntPtrT> tmp168;
    TNode<HeapObject> tmp169;
    TNode<IntPtrT> tmp170;
    TNode<IntPtrT> tmp171;
    TNode<IntPtrT> tmp172;
    TNode<IntPtrT> tmp173;
    ca_.Bind(&block27, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173);
    TNode<IntPtrT> tmp174;
    USE(tmp174);
    tmp174 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp175;
    USE(tmp175);
    tmp175 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp173}, TNode<IntPtrT>{tmp174});
    TNode<IntPtrT> tmp176;
    USE(tmp176);
    tmp176 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp170}, TNode<IntPtrT>{tmp175});
    TNode<HeapObject> tmp177;
    USE(tmp177);
    TNode<IntPtrT> tmp178;
    USE(tmp178);
    std::tie(tmp177, tmp178) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp169}, TNode<IntPtrT>{tmp176}).Flatten();
    TNode<Object>tmp179 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp177, tmp178});
    TNode<BoolT> tmp180;
    USE(tmp180);
    tmp180 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp160}, TNode<MaybeObject>{tmp162});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp180});
    TNode<BoolT> tmp181;
    USE(tmp181);
    tmp181 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp161}, TNode<MaybeObject>{tmp179});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp181});
    ca_.Goto(&block30, tmp157);
  }

  if (block28.is_used()) {
    TNode<Context> tmp182;
    TNode<FixedArray> tmp183;
    TNode<SmiBox> tmp184;
    TNode<Object> tmp185;
    TNode<Object> tmp186;
    TNode<Object> tmp187;
    TNode<FixedArray> tmp188;
    TNode<IntPtrT> tmp189;
    TNode<IntPtrT> tmp190;
    TNode<Smi> tmp191;
    TNode<Smi> tmp192;
    TNode<IntPtrT> tmp193;
    TNode<HeapObject> tmp194;
    TNode<IntPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<IntPtrT> tmp198;
    ca_.Bind(&block28, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198);
    CodeStubAssembler(state_).Unreachable();
  }

    TNode<Context> tmp199;
    ca_.Bind(&block30, &tmp199);
}

TNode<Smi> TestRedundantArrayElementCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi, FixedArray, IntPtrT, IntPtrT, Smi, Smi, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2);
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<FixedArray> tmp4;
    TNode<Smi> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    TNode<IntPtrT> tmp6 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp6);
    TNode<Smi>tmp7 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp4, tmp6});
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp5}, TNode<Smi>{tmp7});
    ca_.Branch(tmp8, &block2, &block3, tmp3, tmp4, tmp5);
  }

  if (block2.is_used()) {
    TNode<Context> tmp9;
    TNode<FixedArray> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11);
    TNode<IntPtrT> tmp12 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp12);
    TNode<IntPtrT> tmp13 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp13);
    TNode<Smi>tmp14 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp10, tmp13});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp14});
    TNode<IntPtrT> tmp16;
    USE(tmp16);
    tmp16 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp11});
    TNode<UintPtrT> tmp17;
    USE(tmp17);
    tmp17 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp16});
    TNode<UintPtrT> tmp18;
    USE(tmp18);
    tmp18 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp15});
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp17}, TNode<UintPtrT>{tmp18});
    ca_.Branch(tmp19, &block12, &block13, tmp9, tmp10, tmp11, tmp10, tmp12, tmp15, tmp11, tmp11, tmp16, tmp10, tmp12, tmp15, tmp16, tmp16);
  }

  if (block12.is_used()) {
    TNode<Context> tmp20;
    TNode<FixedArray> tmp21;
    TNode<Smi> tmp22;
    TNode<FixedArray> tmp23;
    TNode<IntPtrT> tmp24;
    TNode<IntPtrT> tmp25;
    TNode<Smi> tmp26;
    TNode<Smi> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<HeapObject> tmp29;
    TNode<IntPtrT> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    ca_.Bind(&block12, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<IntPtrT> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp35;
    USE(tmp35);
    tmp35 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp33}, TNode<IntPtrT>{tmp34});
    TNode<IntPtrT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp35});
    TNode<HeapObject> tmp37;
    USE(tmp37);
    TNode<IntPtrT> tmp38;
    USE(tmp38);
    std::tie(tmp37, tmp38) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp29}, TNode<IntPtrT>{tmp36}).Flatten();
    TNode<Object>tmp39 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp37, tmp38});
    TNode<Oddball> tmp40;
    USE(tmp40);
    tmp40 = TheHole_0(state_);
    TNode<BoolT> tmp41;
    USE(tmp41);
    tmp41 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp39}, TNode<HeapObject>{tmp40});
    ca_.Branch(tmp41, &block6, &block7, tmp20, tmp21, tmp22);
  }

  if (block13.is_used()) {
    TNode<Context> tmp42;
    TNode<FixedArray> tmp43;
    TNode<Smi> tmp44;
    TNode<FixedArray> tmp45;
    TNode<IntPtrT> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<Smi> tmp48;
    TNode<Smi> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<HeapObject> tmp51;
    TNode<IntPtrT> tmp52;
    TNode<IntPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<IntPtrT> tmp55;
    ca_.Bind(&block13, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block6.is_used()) {
    TNode<Context> tmp56;
    TNode<FixedArray> tmp57;
    TNode<Smi> tmp58;
    ca_.Bind(&block6, &tmp56, &tmp57, &tmp58);
    TNode<IntPtrT> tmp59 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp59);
    TNode<IntPtrT> tmp60 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp60);
    TNode<Smi>tmp61 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp57, tmp60});
    TNode<IntPtrT> tmp62;
    USE(tmp62);
    tmp62 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp61});
    TNode<IntPtrT> tmp63;
    USE(tmp63);
    tmp63 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp58});
    TNode<UintPtrT> tmp64;
    USE(tmp64);
    tmp64 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp63});
    TNode<UintPtrT> tmp65;
    USE(tmp65);
    tmp65 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp62});
    TNode<BoolT> tmp66;
    USE(tmp66);
    tmp66 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp64}, TNode<UintPtrT>{tmp65});
    ca_.Branch(tmp66, &block21, &block22, tmp56, tmp57, tmp58, tmp57, tmp59, tmp62, tmp58, tmp58, tmp63, tmp57, tmp59, tmp62, tmp63, tmp63);
  }

  if (block21.is_used()) {
    TNode<Context> tmp67;
    TNode<FixedArray> tmp68;
    TNode<Smi> tmp69;
    TNode<FixedArray> tmp70;
    TNode<IntPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<Smi> tmp73;
    TNode<Smi> tmp74;
    TNode<IntPtrT> tmp75;
    TNode<HeapObject> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<IntPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    ca_.Bind(&block21, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80);
    TNode<IntPtrT> tmp81;
    USE(tmp81);
    tmp81 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp80}, TNode<IntPtrT>{tmp81});
    TNode<IntPtrT> tmp83;
    USE(tmp83);
    tmp83 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp77}, TNode<IntPtrT>{tmp82});
    TNode<HeapObject> tmp84;
    USE(tmp84);
    TNode<IntPtrT> tmp85;
    USE(tmp85);
    std::tie(tmp84, tmp85) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp76}, TNode<IntPtrT>{tmp83}).Flatten();
    TNode<Object>tmp86 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp84, tmp85});
    TNode<Oddball> tmp87;
    USE(tmp87);
    tmp87 = TheHole_0(state_);
    TNode<BoolT> tmp88;
    USE(tmp88);
    tmp88 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp86}, TNode<HeapObject>{tmp87});
    ca_.Branch(tmp88, &block15, &block16, tmp67, tmp68, tmp69);
  }

  if (block22.is_used()) {
    TNode<Context> tmp89;
    TNode<FixedArray> tmp90;
    TNode<Smi> tmp91;
    TNode<FixedArray> tmp92;
    TNode<IntPtrT> tmp93;
    TNode<IntPtrT> tmp94;
    TNode<Smi> tmp95;
    TNode<Smi> tmp96;
    TNode<IntPtrT> tmp97;
    TNode<HeapObject> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<IntPtrT> tmp100;
    TNode<IntPtrT> tmp101;
    TNode<IntPtrT> tmp102;
    ca_.Bind(&block22, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<Context> tmp103;
    TNode<FixedArray> tmp104;
    TNode<Smi> tmp105;
    ca_.Bind(&block15, &tmp103, &tmp104, &tmp105);
    TNode<Smi> tmp106;
    USE(tmp106);
    tmp106 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp103, tmp106);
  }

  if (block16.is_used()) {
    TNode<Context> tmp107;
    TNode<FixedArray> tmp108;
    TNode<Smi> tmp109;
    ca_.Bind(&block16, &tmp107, &tmp108, &tmp109);
    TNode<BoolT> tmp110;
    USE(tmp110);
    tmp110 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp110});
    ca_.Goto(&block7, tmp107, tmp108, tmp109);
  }

  if (block7.is_used()) {
    TNode<Context> tmp111;
    TNode<FixedArray> tmp112;
    TNode<Smi> tmp113;
    ca_.Bind(&block7, &tmp111, &tmp112, &tmp113);
    TNode<Smi> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp115;
    USE(tmp115);
    tmp115 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp113}, TNode<Smi>{tmp114});
    ca_.Goto(&block4, tmp111, tmp112, tmp115);
  }

  if (block3.is_used()) {
    TNode<Context> tmp116;
    TNode<FixedArray> tmp117;
    TNode<Smi> tmp118;
    ca_.Bind(&block3, &tmp116, &tmp117, &tmp118);
    TNode<Smi> tmp119;
    USE(tmp119);
    tmp119 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp116, tmp119);
  }

  if (block1.is_used()) {
    TNode<Context> tmp120;
    TNode<Smi> tmp121;
    ca_.Bind(&block1, &tmp120, &tmp121);
    ca_.Goto(&block25, tmp120, tmp121);
  }

    TNode<Context> tmp122;
    TNode<Smi> tmp123;
    ca_.Bind(&block25, &tmp122, &tmp123);
  return TNode<Smi>{tmp123};
}

TNode<Smi> TestRedundantSmiCheck_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Object, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Smi, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, FixedArray, Object, Object, Smi, Object, Smi> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<FixedArray> tmp1;
    USE(tmp1);
    tmp1 = kEmptyFixedArray_0(state_);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp2);
    TNode<IntPtrT> tmp3 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp3);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp1, tmp3});
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp4});
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = Convert_intptr_constexpr_int31_0(state_, 1);
    TNode<UintPtrT> tmp7;
    USE(tmp7);
    tmp7 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp6});
    TNode<UintPtrT> tmp8;
    USE(tmp8);
    tmp8 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp5});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp7}, TNode<UintPtrT>{tmp8});
    ca_.Branch(tmp9, &block6, &block7, tmp0, tmp1, tmp1, tmp2, tmp5, tmp6, tmp1, tmp2, tmp5, tmp6, tmp6);
  }

  if (block6.is_used()) {
    TNode<Context> tmp10;
    TNode<FixedArray> tmp11;
    TNode<FixedArray> tmp12;
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    TNode<HeapObject> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    ca_.Bind(&block6, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<IntPtrT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp20}, TNode<IntPtrT>{tmp21});
    TNode<IntPtrT> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp17}, TNode<IntPtrT>{tmp22});
    TNode<HeapObject> tmp24;
    USE(tmp24);
    TNode<IntPtrT> tmp25;
    USE(tmp25);
    std::tie(tmp24, tmp25) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp16}, TNode<IntPtrT>{tmp23}).Flatten();
    TNode<Object>tmp26 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp24, tmp25});
    TNode<Smi> tmp27;
    USE(tmp27);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp27 = Cast_Smi_0(state_, TNode<Object>{tmp26}, &label0);
    ca_.Goto(&block11, tmp10, tmp11, tmp26, tmp26, tmp26, tmp27);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp10, tmp11, tmp26, tmp26, tmp26);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp28;
    TNode<FixedArray> tmp29;
    TNode<FixedArray> tmp30;
    TNode<IntPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<IntPtrT> tmp33;
    TNode<HeapObject> tmp34;
    TNode<IntPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<IntPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    ca_.Bind(&block7, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block12.is_used()) {
    TNode<Context> tmp39;
    TNode<FixedArray> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    ca_.Bind(&block12, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    ca_.Goto(&block1, tmp39, tmp44);
  }

  if (block11.is_used()) {
    TNode<Context> tmp45;
    TNode<FixedArray> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<Smi> tmp50;
    ca_.Bind(&block11, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<Smi> tmp51;
    USE(tmp51);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp51 = Cast_Smi_0(state_, TNode<Object>{tmp47}, &label0);
    ca_.Goto(&block15, tmp45, tmp46, tmp47, tmp48, tmp50, tmp47, tmp51);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp45, tmp46, tmp47, tmp48, tmp50, tmp47);
    }
  }

  if (block16.is_used()) {
    TNode<Context> tmp52;
    TNode<FixedArray> tmp53;
    TNode<Object> tmp54;
    TNode<Object> tmp55;
    TNode<Smi> tmp56;
    TNode<Object> tmp57;
    ca_.Bind(&block16, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    VerifiedUnreachable_0(state_);
  }

  if (block15.is_used()) {
    TNode<Context> tmp58;
    TNode<FixedArray> tmp59;
    TNode<Object> tmp60;
    TNode<Object> tmp61;
    TNode<Smi> tmp62;
    TNode<Object> tmp63;
    TNode<Smi> tmp64;
    ca_.Bind(&block15, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    TNode<Smi> tmp65;
    USE(tmp65);
    tmp65 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    ca_.Goto(&block1, tmp58, tmp65);
  }

  if (block1.is_used()) {
    TNode<Context> tmp66;
    TNode<Smi> tmp67;
    ca_.Bind(&block1, &tmp66, &tmp67);
    ca_.Goto(&block17, tmp66, tmp67);
  }

    TNode<Context> tmp68;
    TNode<Smi> tmp69;
    ca_.Bind(&block17, &tmp68, &tmp69);
  return TNode<Smi>{tmp69};
}

TNode<IntPtrT> TestGenericStruct1_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, IntPtrT, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    TNode<IntPtrT> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_intptr_constexpr_int31_0(state_, 123);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp1});
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp0, tmp0);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block3, &tmp3, &tmp4, &tmp5);
    CodeStubAssembler(state_).FailAssert("Torque assert 'box.value == 123' failed", "test/torque/test-torque.tq", 981);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<IntPtrT> tmp8;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<IntPtrT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp8}, TNode<IntPtrT>{tmp9});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 246);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp10}, TNode<IntPtrT>{tmp11});
    ca_.Branch(tmp12, &block4, &block5, tmp6, tmp7, tmp10);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<IntPtrT> tmp15;
    ca_.Bind(&block5, &tmp13, &tmp14, &tmp15);
    CodeStubAssembler(state_).FailAssert("Torque assert 'boxbox.value.value == 246' failed", "test/torque/test-torque.tq", 983);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp16;
    TNode<IntPtrT> tmp17;
    TNode<IntPtrT> tmp18;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18);
    ca_.Goto(&block6, tmp18);
  }

    TNode<IntPtrT> tmp19;
    ca_.Bind(&block6, &tmp19);
  return TNode<IntPtrT>{tmp19};
}

TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0 TestGenericStruct2_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block3(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

  if (block0.is_used()) {
    ca_.Bind(&block0);
    TNode<IntPtrT> tmp0;
    USE(tmp0);
    tmp0 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<Smi> tmp2;
    USE(tmp2);
    TNode<IntPtrT> tmp3;
    USE(tmp3);
    std::tie(tmp2, tmp3) = TupleSwap_intptr_Smi_0(state_, TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp0}, TNode<Smi>{tmp1}}).Flatten();
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp0}, TNode<IntPtrT>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<IntPtrT> tmp5;
    TNode<Smi> tmp6;
    TNode<Smi> tmp7;
    TNode<IntPtrT> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.fst == smiAndIntptr.snd' failed", "test/torque/test-torque.tq", 1002);
  }

  if (block2.is_used()) {
    TNode<IntPtrT> tmp9;
    TNode<Smi> tmp10;
    TNode<Smi> tmp11;
    TNode<IntPtrT> tmp12;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<BoolT> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp10}, TNode<Smi>{tmp11});
    ca_.Branch(tmp13, &block4, &block5, tmp9, tmp10, tmp11, tmp12);
  }

  if (block5.is_used()) {
    TNode<IntPtrT> tmp14;
    TNode<Smi> tmp15;
    TNode<Smi> tmp16;
    TNode<IntPtrT> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    CodeStubAssembler(state_).FailAssert("Torque assert 'intptrAndSmi.snd == smiAndIntptr.fst' failed", "test/torque/test-torque.tq", 1003);
  }

  if (block4.is_used()) {
    TNode<IntPtrT> tmp18;
    TNode<Smi> tmp19;
    TNode<Smi> tmp20;
    TNode<IntPtrT> tmp21;
    ca_.Bind(&block4, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block6, tmp18, tmp19, tmp20, tmp21);
  }

    TNode<IntPtrT> tmp22;
    TNode<Smi> tmp23;
    TNode<Smi> tmp24;
    TNode<IntPtrT> tmp25;
    ca_.Bind(&block6, &tmp22, &tmp23, &tmp24, &tmp25);
  return TorqueStructTestTuple_TestTuple_intptr_Smi_TestTuple_Smi_intptr_0{TorqueStructTestTuple_intptr_Smi_0{TNode<IntPtrT>{tmp22}, TNode<Smi>{tmp23}}, TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{tmp24}, TNode<IntPtrT>{tmp25}}};
}

TNode<BoolT> BranchAndWriteResult_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_x, TNode<SmiBox> p_box) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, SmiBox, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x, p_box);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    TNode<SmiBox> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 5);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp0}, TNode<Smi>{tmp2});
    ca_.Branch(tmp3, &block4, &block5, tmp0, tmp1, tmp3);
  }

  if (block4.is_used()) {
    TNode<Smi> tmp4;
    TNode<SmiBox> tmp5;
    TNode<BoolT> tmp6;
    ca_.Bind(&block4, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block6, tmp4, tmp5, tmp6, tmp7);
  }

  if (block5.is_used()) {
    TNode<Smi> tmp8;
    TNode<SmiBox> tmp9;
    TNode<BoolT> tmp10;
    ca_.Bind(&block5, &tmp8, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).SmiLessThan(TNode<Smi>{tmp8}, TNode<Smi>{tmp11});
    ca_.Goto(&block6, tmp8, tmp9, tmp10, tmp12);
  }

  if (block6.is_used()) {
    TNode<Smi> tmp13;
    TNode<SmiBox> tmp14;
    TNode<BoolT> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Branch(tmp16, &block2, &block3, tmp13, tmp14);
  }

  if (block2.is_used()) {
    TNode<Smi> tmp17;
    TNode<SmiBox> tmp18;
    ca_.Bind(&block2, &tmp17, &tmp18);
    TNode<IntPtrT> tmp19 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp19);
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp18, tmp19}, tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp17, tmp18, tmp21);
  }

  if (block3.is_used()) {
    TNode<Smi> tmp22;
    TNode<SmiBox> tmp23;
    ca_.Bind(&block3, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp24);
    TNode<Smi> tmp25;
    USE(tmp25);
    tmp25 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp23, tmp24}, tmp25);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp22, tmp23, tmp26);
  }

  if (block1.is_used()) {
    TNode<Smi> tmp27;
    TNode<SmiBox> tmp28;
    TNode<BoolT> tmp29;
    ca_.Bind(&block1, &tmp27, &tmp28, &tmp29);
    ca_.Goto(&block8, tmp27, tmp28, tmp29);
  }

    TNode<Smi> tmp30;
    TNode<SmiBox> tmp31;
    TNode<BoolT> tmp32;
    ca_.Bind(&block8, &tmp30, &tmp31, &tmp32);
  return TNode<BoolT>{tmp32};
}

void TestBranchOnBoolOptimization_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_input) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, SmiBox> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_input);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<SmiBox> tmp3;
    tmp3 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kNewSmiBox, tmp0, tmp2));
    USE(tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = BranchAndWriteResult_0(state_, TNode<Smi>{tmp1}, TNode<SmiBox>{tmp3});
    ca_.Branch(tmp4, &block2, &block3, tmp0, tmp1, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp5;
    TNode<Smi> tmp6;
    TNode<SmiBox> tmp7;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7);
    TNode<IntPtrT> tmp8 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp8);
    TNode<Smi>tmp9 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp7, tmp8});
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp9}, TNode<Smi>{tmp10});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp11});
    ca_.Goto(&block4, tmp5, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp12;
    TNode<Smi> tmp13;
    TNode<SmiBox> tmp14;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14);
    TNode<IntPtrT> tmp15 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp15);
    TNode<Smi>tmp16 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp14, tmp15});
    TNode<Smi> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Smi_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).SmiEqual(TNode<Smi>{tmp16}, TNode<Smi>{tmp17});
    CodeStubAssembler(state_).StaticAssert(TNode<BoolT>{tmp18});
    ca_.Goto(&block4, tmp12, tmp13, tmp14);
  }

  if (block4.is_used()) {
    TNode<Context> tmp19;
    TNode<Smi> tmp20;
    TNode<SmiBox> tmp21;
    ca_.Bind(&block4, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block5, tmp19, tmp20);
  }

    TNode<Context> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block5, &tmp22, &tmp23);
}

TNode<Smi> LoadInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<InternalClass> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreInternalClassA_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<InternalClass> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Number> LoadInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<InternalClass> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Number>{tmp4};
}

void StoreInternalClassB_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_o, TNode<Number> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<InternalClass> tmp3;
    TNode<Number> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

void Method_InternalClass_Flip_0(compiler::CodeAssemblerState* state_, TNode<InternalClass> p_this, compiler::CodeAssemblerLabel* label_NotASmi) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass, Number, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<InternalClass> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<InternalClass> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp1);
    TNode<Number>tmp2 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Smi> tmp3;
    USE(tmp3);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp3 = Cast_Smi_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block3, tmp0, tmp2, tmp3);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp2);
    }
  }

  if (block4.is_used()) {
    TNode<InternalClass> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block4, &tmp4, &tmp5);
    ca_.Goto(label_NotASmi);
  }

  if (block3.is_used()) {
    TNode<InternalClass> tmp6;
    TNode<Number> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8);
    TNode<IntPtrT> tmp9 = ca_.IntPtrConstant(InternalClass::kBOffset);
    USE(tmp9);
    TNode<IntPtrT> tmp10 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp10);
    TNode<Smi>tmp11 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp6, tmp10});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp6, tmp9}, tmp11);
    TNode<IntPtrT> tmp12 = ca_.IntPtrConstant(InternalClass::kAOffset);
    USE(tmp12);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp6, tmp12}, tmp8);
    ca_.Goto(&block5, tmp6);
  }

    TNode<InternalClass> tmp13;
    ca_.Bind(&block5, &tmp13);
}

TNode<Smi> LoadSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiPairA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(SmiPair::kBOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiPairB_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(SmiPair::kBOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiPair> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TorqueStructReference_Smi_0 Method_SmiPair_GetA_0(compiler::CodeAssemblerState* state_, TNode<SmiPair> p_this) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiPair> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiPair, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_this);

  if (block0.is_used()) {
    TNode<SmiPair> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(SmiPair::kAOffset);
    USE(tmp1);
    ca_.Goto(&block2, tmp0, tmp0, tmp1);
  }

    TNode<SmiPair> tmp2;
    TNode<HeapObject> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4);
  return TorqueStructReference_Smi_0{TNode<HeapObject>{tmp3}, TNode<IntPtrT>{tmp4}, TorqueStructUnsafe_0{}};
}

TNode<Smi> LoadSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiBoxValue_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(SmiBox::kValueOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TNode<Smi> LoadSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<IntPtrT> tmp1 = ca_.IntPtrConstant(SmiBox::kUnrelatedOffset);
    USE(tmp1);
    TNode<Smi>tmp2 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

void StoreSmiBoxUnrelated_0(compiler::CodeAssemblerState* state_, TNode<SmiBox> p_o, TNode<Smi> p_v) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<SmiBox, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o, p_v);

  if (block0.is_used()) {
    TNode<SmiBox> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2 = ca_.IntPtrConstant(SmiBox::kUnrelatedOffset);
    USE(tmp2);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp2}, tmp1);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<SmiBox> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
}

TF_BUILTIN(GenericBuiltinTest_Smi_0, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Smi> parameter1 = UncheckedCast<Smi>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Oddball> tmp2;
    USE(tmp2);
    tmp2 = Null_0(state_);
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TNode<Object> GenericMacroTest_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__param);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<Object>{tmp3};
}

TNode<Object> GenericMacroTestWithLabels_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p__param, compiler::CodeAssemblerLabel* label__X) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p__param);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Oddball> tmp1;
    USE(tmp1);
    tmp1 = Undefined_0(state_);
    ca_.Goto(&block3, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block3, &tmp2, &tmp3);
  return TNode<Object>{tmp3};
}

TNode<Object> IncrementIfSmi_NumberOrFixedArray_0(compiler::CodeAssemblerState* state_, TNode<Object> p_x) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object, Object, Smi> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_x);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp1 = Cast_Smi_0(state_, TNode<Object>{tmp0}, &label0);
    ca_.Goto(&block4, tmp0, tmp0, tmp0, tmp1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp0, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp2, &tmp3, &tmp4);
    ca_.Goto(&block1, tmp2, ca_.UncheckedCast<HeapObject>(tmp3));
  }

  if (block4.is_used()) {
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Smi> tmp8;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8);
    TNode<Smi> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp8}, TNode<Smi>{tmp9});
    ca_.Goto(&block1, tmp5, tmp10);
  }

  if (block1.is_used()) {
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block1, &tmp11, &tmp12);
    ca_.Goto(&block6, tmp11, tmp12);
  }

    TNode<Object> tmp13;
    TNode<Object> tmp14;
    ca_.Bind(&block6, &tmp13, &tmp14);
  return TNode<Object>{tmp14};
}

TNode<Smi> ExampleGenericOverload_Smi_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<Smi> tmp1;
    USE(tmp1);
    tmp1 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp0}, TNode<Smi>{tmp1});
    ca_.Goto(&block2, tmp0, tmp2);
  }

    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
  return TNode<Smi>{tmp4};
}

TNode<Object> ExampleGenericOverload_Object_0(compiler::CodeAssemblerState* state_, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Object, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_o);

  if (block0.is_used()) {
    TNode<Object> tmp0;
    ca_.Bind(&block0, &tmp0);
    ca_.Goto(&block2, tmp0, tmp0);
  }

    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block2, &tmp1, &tmp2);
  return TNode<Object>{tmp2};
}

TNode<BoolT> Is_JSArray_Smi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Smi> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Smi, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, Smi, Context, JSArray> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Smi, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSArray_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Smi> tmp4;
    TNode<Smi> tmp5;
    TNode<Context> tmp6;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<BoolT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp7);
  }

  if (block4.is_used()) {
    TNode<Context> tmp8;
    TNode<Smi> tmp9;
    TNode<Smi> tmp10;
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
    TNode<Smi> tmp15;
    TNode<BoolT> tmp16;
    ca_.Bind(&block1, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block6, tmp14, tmp15, tmp16);
  }

    TNode<Context> tmp17;
    TNode<Smi> tmp18;
    TNode<BoolT> tmp19;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19);
  return TNode<BoolT>{tmp19};
}

void Swap_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructReference_Smi_0 p_a, TorqueStructReference_Smi_0 p_b) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<HeapObject, IntPtrT, HeapObject, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_a.object, p_a.offset, p_b.object, p_b.offset);

  if (block0.is_used()) {
    TNode<HeapObject> tmp0;
    TNode<IntPtrT> tmp1;
    TNode<HeapObject> tmp2;
    TNode<IntPtrT> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Smi>tmp4 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp0, tmp1});
    TNode<Smi>tmp5 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp2, tmp3});
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp1}, tmp5);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp2, tmp3}, tmp4);
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3);
  }

    TNode<HeapObject> tmp6;
    TNode<IntPtrT> tmp7;
    TNode<HeapObject> tmp8;
    TNode<IntPtrT> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
}

TorqueStructTestTuple_Smi_intptr_0 TupleSwap_intptr_Smi_0(compiler::CodeAssemblerState* state_, TorqueStructTestTuple_intptr_Smi_0 p_tuple) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<IntPtrT, Smi, Smi, IntPtrT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_tuple.fst, p_tuple.snd);

  if (block0.is_used()) {
    TNode<IntPtrT> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    ca_.Goto(&block2, tmp0, tmp1, tmp1, tmp0);
  }

    TNode<IntPtrT> tmp2;
    TNode<Smi> tmp3;
    TNode<Smi> tmp4;
    TNode<IntPtrT> tmp5;
    ca_.Bind(&block2, &tmp2, &tmp3, &tmp4, &tmp5);
  return TorqueStructTestTuple_Smi_intptr_0{TNode<Smi>{tmp4}, TNode<IntPtrT>{tmp5}};
}

}  // namespace internal
}  // namespace v8

