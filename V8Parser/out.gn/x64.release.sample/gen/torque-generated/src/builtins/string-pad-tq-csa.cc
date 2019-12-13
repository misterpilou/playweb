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

int31_t kStringPadStart_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 0;
}

int31_t kStringPadEnd_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 1;
}

TNode<String> StringPad_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, TorqueStructArguments p_arguments, const char* p_methodName, int31_t p_variant) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number> block7(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, Number, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, Number, Number, Smi> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, Number, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, Number, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Object> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi> block31(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String, Int32T, Int32T, Int32T, Int32T> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String, Int32T, Int32T, Int32T, Int32T> block36(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block40(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block39(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block46(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String, Smi, Number, String, IntPtrT, Smi, Smi, String> block45(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, RawPtrT, RawPtrT, IntPtrT, String> block47(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_arguments.frame, p_arguments.base, p_arguments.length);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<RawPtrT> tmp2;
    TNode<RawPtrT> tmp3;
    TNode<IntPtrT> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_String_constexpr_string_0(state_, p_methodName);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp5});
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp4}, TNode<IntPtrT>{tmp8});
    ca_.Branch(tmp9, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp7);
  }

  if (block2.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<RawPtrT> tmp12;
    TNode<RawPtrT> tmp13;
    TNode<IntPtrT> tmp14;
    TNode<String> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block1, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block3.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<RawPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<String> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block3, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp19}, TNode<RawPtrT>{tmp20}, TNode<IntPtrT>{tmp21}}, TNode<IntPtrT>{tmp24});
    TNode<Number> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp17}, TNode<Object>{tmp25});
    TNode<Smi> tmp27;
    USE(tmp27);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp27 = Cast_Smi_0(state_, TNode<Object>{tmp26}, &label0);
    ca_.Goto(&block10, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp26, tmp26, tmp26, tmp27);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp26, tmp26, tmp26);
    }
  }

  if (block7.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    TNode<RawPtrT> tmp30;
    TNode<RawPtrT> tmp31;
    TNode<IntPtrT> tmp32;
    TNode<String> tmp33;
    TNode<Smi> tmp34;
    TNode<Number> tmp35;
    ca_.Bind(&block7, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsNumberNormalized(maxLength)' failed", "src/builtins/string-pad.tq", 25);
  }

  if (block6.is_used()) {
    TNode<Context> tmp36;
    TNode<Object> tmp37;
    TNode<RawPtrT> tmp38;
    TNode<RawPtrT> tmp39;
    TNode<IntPtrT> tmp40;
    TNode<String> tmp41;
    TNode<Smi> tmp42;
    TNode<Number> tmp43;
    ca_.Bind(&block6, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
  }

  if (block11.is_used()) {
    TNode<Context> tmp44;
    TNode<Object> tmp45;
    TNode<RawPtrT> tmp46;
    TNode<RawPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<String> tmp49;
    TNode<Smi> tmp50;
    TNode<Number> tmp51;
    TNode<Number> tmp52;
    TNode<Number> tmp53;
    ca_.Bind(&block11, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    ca_.Goto(&block8, tmp44, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52);
  }

  if (block10.is_used()) {
    TNode<Context> tmp54;
    TNode<Object> tmp55;
    TNode<RawPtrT> tmp56;
    TNode<RawPtrT> tmp57;
    TNode<IntPtrT> tmp58;
    TNode<String> tmp59;
    TNode<Smi> tmp60;
    TNode<Number> tmp61;
    TNode<Number> tmp62;
    TNode<Number> tmp63;
    TNode<Smi> tmp64;
    ca_.Bind(&block10, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64);
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = CodeStubAssembler(state_).SmiLessThanOrEqual(TNode<Smi>{tmp64}, TNode<Smi>{tmp60});
    ca_.Branch(tmp65, &block12, &block13, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp64);
  }

  if (block12.is_used()) {
    TNode<Context> tmp66;
    TNode<Object> tmp67;
    TNode<RawPtrT> tmp68;
    TNode<RawPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<String> tmp71;
    TNode<Smi> tmp72;
    TNode<Number> tmp73;
    TNode<Number> tmp74;
    TNode<Smi> tmp75;
    ca_.Bind(&block12, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    ca_.Goto(&block1, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71);
  }

  if (block13.is_used()) {
    TNode<Context> tmp76;
    TNode<Object> tmp77;
    TNode<RawPtrT> tmp78;
    TNode<RawPtrT> tmp79;
    TNode<IntPtrT> tmp80;
    TNode<String> tmp81;
    TNode<Smi> tmp82;
    TNode<Number> tmp83;
    TNode<Number> tmp84;
    TNode<Smi> tmp85;
    ca_.Bind(&block13, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    ca_.Goto(&block8, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84);
  }

  if (block8.is_used()) {
    TNode<Context> tmp86;
    TNode<Object> tmp87;
    TNode<RawPtrT> tmp88;
    TNode<RawPtrT> tmp89;
    TNode<IntPtrT> tmp90;
    TNode<String> tmp91;
    TNode<Smi> tmp92;
    TNode<Number> tmp93;
    TNode<Number> tmp94;
    ca_.Bind(&block8, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94);
    TNode<String> tmp95;
    USE(tmp95);
    tmp95 = FromConstexpr_String_constexpr_string_0(state_, " ");
    TNode<IntPtrT> tmp96;
    USE(tmp96);
    tmp96 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<IntPtrT> tmp97;
    USE(tmp97);
    tmp97 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{tmp90}, TNode<IntPtrT>{tmp97});
    ca_.Branch(tmp98, &block14, &block15, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp95, tmp96);
  }

  if (block14.is_used()) {
    TNode<Context> tmp99;
    TNode<Object> tmp100;
    TNode<RawPtrT> tmp101;
    TNode<RawPtrT> tmp102;
    TNode<IntPtrT> tmp103;
    TNode<String> tmp104;
    TNode<Smi> tmp105;
    TNode<Number> tmp106;
    TNode<String> tmp107;
    TNode<IntPtrT> tmp108;
    ca_.Bind(&block14, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    TNode<IntPtrT> tmp109;
    USE(tmp109);
    tmp109 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp110;
    USE(tmp110);
    tmp110 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp101}, TNode<RawPtrT>{tmp102}, TNode<IntPtrT>{tmp103}}, TNode<IntPtrT>{tmp109});
    TNode<Oddball> tmp111;
    USE(tmp111);
    tmp111 = Undefined_0(state_);
    TNode<BoolT> tmp112;
    USE(tmp112);
    tmp112 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp110}, TNode<HeapObject>{tmp111});
    ca_.Branch(tmp112, &block16, &block17, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp110);
  }

  if (block16.is_used()) {
    TNode<Context> tmp113;
    TNode<Object> tmp114;
    TNode<RawPtrT> tmp115;
    TNode<RawPtrT> tmp116;
    TNode<IntPtrT> tmp117;
    TNode<String> tmp118;
    TNode<Smi> tmp119;
    TNode<Number> tmp120;
    TNode<String> tmp121;
    TNode<IntPtrT> tmp122;
    TNode<Object> tmp123;
    ca_.Bind(&block16, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123);
    TNode<String> tmp124;
    USE(tmp124);
    tmp124 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp113}, TNode<Object>{tmp123});
    TNode<IntPtrT> tmp125;
    USE(tmp125);
    tmp125 = CodeStubAssembler(state_).LoadStringLengthAsWord(TNode<String>{tmp124});
    TNode<IntPtrT> tmp126;
    USE(tmp126);
    tmp126 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp127;
    USE(tmp127);
    tmp127 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp125}, TNode<IntPtrT>{tmp126});
    ca_.Branch(tmp127, &block18, &block19, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp124, tmp125, tmp123);
  }

  if (block18.is_used()) {
    TNode<Context> tmp128;
    TNode<Object> tmp129;
    TNode<RawPtrT> tmp130;
    TNode<RawPtrT> tmp131;
    TNode<IntPtrT> tmp132;
    TNode<String> tmp133;
    TNode<Smi> tmp134;
    TNode<Number> tmp135;
    TNode<String> tmp136;
    TNode<IntPtrT> tmp137;
    TNode<Object> tmp138;
    ca_.Bind(&block18, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    ca_.Goto(&block1, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133);
  }

  if (block19.is_used()) {
    TNode<Context> tmp139;
    TNode<Object> tmp140;
    TNode<RawPtrT> tmp141;
    TNode<RawPtrT> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<String> tmp144;
    TNode<Smi> tmp145;
    TNode<Number> tmp146;
    TNode<String> tmp147;
    TNode<IntPtrT> tmp148;
    TNode<Object> tmp149;
    ca_.Bind(&block19, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149);
    ca_.Goto(&block17, tmp139, tmp140, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149);
  }

  if (block17.is_used()) {
    TNode<Context> tmp150;
    TNode<Object> tmp151;
    TNode<RawPtrT> tmp152;
    TNode<RawPtrT> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<String> tmp155;
    TNode<Smi> tmp156;
    TNode<Number> tmp157;
    TNode<String> tmp158;
    TNode<IntPtrT> tmp159;
    TNode<Object> tmp160;
    ca_.Bind(&block17, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160);
    ca_.Goto(&block15, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159);
  }

  if (block15.is_used()) {
    TNode<Context> tmp161;
    TNode<Object> tmp162;
    TNode<RawPtrT> tmp163;
    TNode<RawPtrT> tmp164;
    TNode<IntPtrT> tmp165;
    TNode<String> tmp166;
    TNode<Smi> tmp167;
    TNode<Number> tmp168;
    TNode<String> tmp169;
    TNode<IntPtrT> tmp170;
    ca_.Bind(&block15, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170);
    TNode<BoolT> tmp171;
    USE(tmp171);
    tmp171 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp168});
    TNode<BoolT> tmp172;
    USE(tmp172);
    tmp172 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp171});
    ca_.Branch(tmp172, &block24, &block25, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170);
  }

  if (block23.is_used()) {
    TNode<Context> tmp173;
    TNode<Object> tmp174;
    TNode<RawPtrT> tmp175;
    TNode<RawPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<String> tmp178;
    TNode<Smi> tmp179;
    TNode<Number> tmp180;
    TNode<String> tmp181;
    TNode<IntPtrT> tmp182;
    ca_.Bind(&block23, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    CodeStubAssembler(state_).FailAssert("Torque assert 'fillLength > 0' failed", "src/builtins/string-pad.tq", 52);
  }

  if (block22.is_used()) {
    TNode<Context> tmp183;
    TNode<Object> tmp184;
    TNode<RawPtrT> tmp185;
    TNode<RawPtrT> tmp186;
    TNode<IntPtrT> tmp187;
    TNode<String> tmp188;
    TNode<Smi> tmp189;
    TNode<Number> tmp190;
    TNode<String> tmp191;
    TNode<IntPtrT> tmp192;
    ca_.Bind(&block22, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192);
  }

  if (block24.is_used()) {
    TNode<Context> tmp193;
    TNode<Object> tmp194;
    TNode<RawPtrT> tmp195;
    TNode<RawPtrT> tmp196;
    TNode<IntPtrT> tmp197;
    TNode<String> tmp198;
    TNode<Smi> tmp199;
    TNode<Number> tmp200;
    TNode<String> tmp201;
    TNode<IntPtrT> tmp202;
    ca_.Bind(&block24, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidStringLength, tmp193);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block25.is_used()) {
    TNode<Context> tmp204;
    TNode<Object> tmp205;
    TNode<RawPtrT> tmp206;
    TNode<RawPtrT> tmp207;
    TNode<IntPtrT> tmp208;
    TNode<String> tmp209;
    TNode<Smi> tmp210;
    TNode<Number> tmp211;
    TNode<String> tmp212;
    TNode<IntPtrT> tmp213;
    ca_.Bind(&block25, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213);
    TNode<Smi> tmp214;
    USE(tmp214);
    tmp214 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp204}, TNode<Object>{tmp211});
    TNode<Smi> tmp215;
    USE(tmp215);
    tmp215 = CodeStubAssembler(state_).SmiConstant(String::kMaxLength);
    TNode<BoolT> tmp216;
    USE(tmp216);
    tmp216 = CodeStubAssembler(state_).SmiGreaterThan(TNode<Smi>{tmp214}, TNode<Smi>{tmp215});
    ca_.Branch(tmp216, &block26, &block27, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214);
  }

  if (block26.is_used()) {
    TNode<Context> tmp217;
    TNode<Object> tmp218;
    TNode<RawPtrT> tmp219;
    TNode<RawPtrT> tmp220;
    TNode<IntPtrT> tmp221;
    TNode<String> tmp222;
    TNode<Smi> tmp223;
    TNode<Number> tmp224;
    TNode<String> tmp225;
    TNode<IntPtrT> tmp226;
    TNode<Smi> tmp227;
    ca_.Bind(&block26, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227);
    CodeStubAssembler(state_).CallRuntime(Runtime::kThrowInvalidStringLength, tmp217);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block27.is_used()) {
    TNode<Context> tmp229;
    TNode<Object> tmp230;
    TNode<RawPtrT> tmp231;
    TNode<RawPtrT> tmp232;
    TNode<IntPtrT> tmp233;
    TNode<String> tmp234;
    TNode<Smi> tmp235;
    TNode<Number> tmp236;
    TNode<String> tmp237;
    TNode<IntPtrT> tmp238;
    TNode<Smi> tmp239;
    ca_.Bind(&block27, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239);
    TNode<Smi> tmp240;
    USE(tmp240);
    tmp240 = CodeStubAssembler(state_).SmiSub(TNode<Smi>{tmp239}, TNode<Smi>{tmp235});
    TNode<IntPtrT> tmp241;
    USE(tmp241);
    tmp241 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp242;
    USE(tmp242);
    tmp242 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp238}, TNode<IntPtrT>{tmp241});
    ca_.Branch(tmp242, &block32, &block33, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, ca_.Uninitialized<String>());
  }

  if (block31.is_used()) {
    TNode<Context> tmp243;
    TNode<Object> tmp244;
    TNode<RawPtrT> tmp245;
    TNode<RawPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<String> tmp248;
    TNode<Smi> tmp249;
    TNode<Number> tmp250;
    TNode<String> tmp251;
    TNode<IntPtrT> tmp252;
    TNode<Smi> tmp253;
    ca_.Bind(&block31, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253);
    CodeStubAssembler(state_).FailAssert("Torque assert 'smiMaxLength > stringLength' failed", "src/builtins/string-pad.tq", 62);
  }

  if (block30.is_used()) {
    TNode<Context> tmp254;
    TNode<Object> tmp255;
    TNode<RawPtrT> tmp256;
    TNode<RawPtrT> tmp257;
    TNode<IntPtrT> tmp258;
    TNode<String> tmp259;
    TNode<Smi> tmp260;
    TNode<Number> tmp261;
    TNode<String> tmp262;
    TNode<IntPtrT> tmp263;
    TNode<Smi> tmp264;
    ca_.Bind(&block30, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264);
  }

  if (block32.is_used()) {
    TNode<Context> tmp265;
    TNode<Object> tmp266;
    TNode<RawPtrT> tmp267;
    TNode<RawPtrT> tmp268;
    TNode<IntPtrT> tmp269;
    TNode<String> tmp270;
    TNode<Smi> tmp271;
    TNode<Number> tmp272;
    TNode<String> tmp273;
    TNode<IntPtrT> tmp274;
    TNode<Smi> tmp275;
    TNode<Smi> tmp276;
    TNode<String> tmp277;
    ca_.Bind(&block32, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274, &tmp275, &tmp276, &tmp277);
    TNode<String> tmp278;
    tmp278 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringRepeat, tmp265, tmp273, tmp276));
    USE(tmp278);
    ca_.Goto(&block34, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp272, tmp273, tmp274, tmp275, tmp276, tmp278);
  }

  if (block33.is_used()) {
    TNode<Context> tmp279;
    TNode<Object> tmp280;
    TNode<RawPtrT> tmp281;
    TNode<RawPtrT> tmp282;
    TNode<IntPtrT> tmp283;
    TNode<String> tmp284;
    TNode<Smi> tmp285;
    TNode<Number> tmp286;
    TNode<String> tmp287;
    TNode<IntPtrT> tmp288;
    TNode<Smi> tmp289;
    TNode<Smi> tmp290;
    TNode<String> tmp291;
    ca_.Bind(&block33, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291);
    TNode<Int32T> tmp292;
    USE(tmp292);
    tmp292 = CodeStubAssembler(state_).TruncateIntPtrToInt32(TNode<IntPtrT>{tmp288});
    TNode<Int32T> tmp293;
    USE(tmp293);
    tmp293 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp290});
    TNode<Int32T> tmp294;
    USE(tmp294);
    tmp294 = CodeStubAssembler(state_).Int32Div(TNode<Int32T>{tmp293}, TNode<Int32T>{tmp292});
    TNode<Int32T> tmp295;
    USE(tmp295);
    tmp295 = CodeStubAssembler(state_).Int32Mod(TNode<Int32T>{tmp293}, TNode<Int32T>{tmp292});
    TNode<Smi> tmp296;
    USE(tmp296);
    tmp296 = Convert_Smi_int32_0(state_, TNode<Int32T>{tmp294});
    TNode<String> tmp297;
    tmp297 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringRepeat, tmp279, tmp287, tmp296));
    USE(tmp297);
    TNode<Int32T> tmp298;
    USE(tmp298);
    tmp298 = FromConstexpr_int32_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp299;
    USE(tmp299);
    tmp299 = CodeStubAssembler(state_).Word32NotEqual(TNode<Int32T>{tmp295}, TNode<Int32T>{tmp298});
    ca_.Branch(tmp299, &block35, &block36, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp287, tmp288, tmp289, tmp290, tmp297, tmp292, tmp293, tmp294, tmp295);
  }

  if (block35.is_used()) {
    TNode<Context> tmp300;
    TNode<Object> tmp301;
    TNode<RawPtrT> tmp302;
    TNode<RawPtrT> tmp303;
    TNode<IntPtrT> tmp304;
    TNode<String> tmp305;
    TNode<Smi> tmp306;
    TNode<Number> tmp307;
    TNode<String> tmp308;
    TNode<IntPtrT> tmp309;
    TNode<Smi> tmp310;
    TNode<Smi> tmp311;
    TNode<String> tmp312;
    TNode<Int32T> tmp313;
    TNode<Int32T> tmp314;
    TNode<Int32T> tmp315;
    TNode<Int32T> tmp316;
    ca_.Bind(&block35, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316);
    TNode<IntPtrT> tmp317;
    USE(tmp317);
    tmp317 = Convert_intptr_int32_0(state_, TNode<Int32T>{tmp316});
    TNode<IntPtrT> tmp318;
    USE(tmp318);
    tmp318 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<String> tmp319;
    tmp319 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringSubstring, tmp300, tmp308, tmp318, tmp317));
    USE(tmp319);
    TNode<String> tmp320;
    USE(tmp320);
    tmp320 = StringAdd_0(state_, TNode<Context>{tmp300}, TNode<String>{tmp312}, TNode<String>{tmp319});
    ca_.Goto(&block36, tmp300, tmp301, tmp302, tmp303, tmp304, tmp305, tmp306, tmp307, tmp308, tmp309, tmp310, tmp311, tmp320, tmp313, tmp314, tmp315, tmp316);
  }

  if (block36.is_used()) {
    TNode<Context> tmp321;
    TNode<Object> tmp322;
    TNode<RawPtrT> tmp323;
    TNode<RawPtrT> tmp324;
    TNode<IntPtrT> tmp325;
    TNode<String> tmp326;
    TNode<Smi> tmp327;
    TNode<Number> tmp328;
    TNode<String> tmp329;
    TNode<IntPtrT> tmp330;
    TNode<Smi> tmp331;
    TNode<Smi> tmp332;
    TNode<String> tmp333;
    TNode<Int32T> tmp334;
    TNode<Int32T> tmp335;
    TNode<Int32T> tmp336;
    TNode<Int32T> tmp337;
    ca_.Bind(&block36, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337);
    ca_.Goto(&block34, tmp321, tmp322, tmp323, tmp324, tmp325, tmp326, tmp327, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333);
  }

  if (block34.is_used()) {
    TNode<Context> tmp338;
    TNode<Object> tmp339;
    TNode<RawPtrT> tmp340;
    TNode<RawPtrT> tmp341;
    TNode<IntPtrT> tmp342;
    TNode<String> tmp343;
    TNode<Smi> tmp344;
    TNode<Number> tmp345;
    TNode<String> tmp346;
    TNode<IntPtrT> tmp347;
    TNode<Smi> tmp348;
    TNode<Smi> tmp349;
    TNode<String> tmp350;
    ca_.Bind(&block34, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350);
    TNode<BoolT> tmp351;
    USE(tmp351);
    tmp351 = FromConstexpr_bool_constexpr_bool_0(state_, (CodeStubAssembler(state_).ConstexprInt31Equal(p_variant, kStringPadStart_0(state_))));
    ca_.Branch(tmp351, &block41, &block42, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp348, tmp349, tmp350);
  }

  if (block40.is_used()) {
    TNode<Context> tmp352;
    TNode<Object> tmp353;
    TNode<RawPtrT> tmp354;
    TNode<RawPtrT> tmp355;
    TNode<IntPtrT> tmp356;
    TNode<String> tmp357;
    TNode<Smi> tmp358;
    TNode<Number> tmp359;
    TNode<String> tmp360;
    TNode<IntPtrT> tmp361;
    TNode<Smi> tmp362;
    TNode<Smi> tmp363;
    TNode<String> tmp364;
    ca_.Bind(&block40, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363, &tmp364);
    CodeStubAssembler(state_).FailAssert("Torque assert 'padLength == padding.length_smi' failed", "src/builtins/string-pad.tq", 88);
  }

  if (block39.is_used()) {
    TNode<Context> tmp365;
    TNode<Object> tmp366;
    TNode<RawPtrT> tmp367;
    TNode<RawPtrT> tmp368;
    TNode<IntPtrT> tmp369;
    TNode<String> tmp370;
    TNode<Smi> tmp371;
    TNode<Number> tmp372;
    TNode<String> tmp373;
    TNode<IntPtrT> tmp374;
    TNode<Smi> tmp375;
    TNode<Smi> tmp376;
    TNode<String> tmp377;
    ca_.Bind(&block39, &tmp365, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377);
  }

  if (block41.is_used()) {
    TNode<Context> tmp378;
    TNode<Object> tmp379;
    TNode<RawPtrT> tmp380;
    TNode<RawPtrT> tmp381;
    TNode<IntPtrT> tmp382;
    TNode<String> tmp383;
    TNode<Smi> tmp384;
    TNode<Number> tmp385;
    TNode<String> tmp386;
    TNode<IntPtrT> tmp387;
    TNode<Smi> tmp388;
    TNode<Smi> tmp389;
    TNode<String> tmp390;
    ca_.Bind(&block41, &tmp378, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390);
    TNode<String> tmp391;
    USE(tmp391);
    tmp391 = StringAdd_0(state_, TNode<Context>{tmp378}, TNode<String>{tmp390}, TNode<String>{tmp383});
    ca_.Goto(&block1, tmp378, tmp379, tmp380, tmp381, tmp382, tmp391);
  }

  if (block42.is_used()) {
    TNode<Context> tmp392;
    TNode<Object> tmp393;
    TNode<RawPtrT> tmp394;
    TNode<RawPtrT> tmp395;
    TNode<IntPtrT> tmp396;
    TNode<String> tmp397;
    TNode<Smi> tmp398;
    TNode<Number> tmp399;
    TNode<String> tmp400;
    TNode<IntPtrT> tmp401;
    TNode<Smi> tmp402;
    TNode<Smi> tmp403;
    TNode<String> tmp404;
    ca_.Bind(&block42, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404);
    TNode<String> tmp405;
    USE(tmp405);
    tmp405 = StringAdd_0(state_, TNode<Context>{tmp392}, TNode<String>{tmp397}, TNode<String>{tmp404});
    ca_.Goto(&block1, tmp392, tmp393, tmp394, tmp395, tmp396, tmp405);
  }

  if (block46.is_used()) {
    TNode<Context> tmp406;
    TNode<Object> tmp407;
    TNode<RawPtrT> tmp408;
    TNode<RawPtrT> tmp409;
    TNode<IntPtrT> tmp410;
    TNode<String> tmp411;
    TNode<Smi> tmp412;
    TNode<Number> tmp413;
    TNode<String> tmp414;
    TNode<IntPtrT> tmp415;
    TNode<Smi> tmp416;
    TNode<Smi> tmp417;
    TNode<String> tmp418;
    ca_.Bind(&block46, &tmp406, &tmp407, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413, &tmp414, &tmp415, &tmp416, &tmp417, &tmp418);
    CodeStubAssembler(state_).FailAssert("Torque assert 'variant == kStringPadEnd' failed", "src/builtins/string-pad.tq", 92);
  }

  if (block45.is_used()) {
    TNode<Context> tmp419;
    TNode<Object> tmp420;
    TNode<RawPtrT> tmp421;
    TNode<RawPtrT> tmp422;
    TNode<IntPtrT> tmp423;
    TNode<String> tmp424;
    TNode<Smi> tmp425;
    TNode<Number> tmp426;
    TNode<String> tmp427;
    TNode<IntPtrT> tmp428;
    TNode<Smi> tmp429;
    TNode<Smi> tmp430;
    TNode<String> tmp431;
    ca_.Bind(&block45, &tmp419, &tmp420, &tmp421, &tmp422, &tmp423, &tmp424, &tmp425, &tmp426, &tmp427, &tmp428, &tmp429, &tmp430, &tmp431);
  }

  if (block1.is_used()) {
    TNode<Context> tmp432;
    TNode<Object> tmp433;
    TNode<RawPtrT> tmp434;
    TNode<RawPtrT> tmp435;
    TNode<IntPtrT> tmp436;
    TNode<String> tmp437;
    ca_.Bind(&block1, &tmp432, &tmp433, &tmp434, &tmp435, &tmp436, &tmp437);
    ca_.Goto(&block47, tmp432, tmp433, tmp434, tmp435, tmp436, tmp437);
  }

    TNode<Context> tmp438;
    TNode<Object> tmp439;
    TNode<RawPtrT> tmp440;
    TNode<RawPtrT> tmp441;
    TNode<IntPtrT> tmp442;
    TNode<String> tmp443;
    ca_.Bind(&block47, &tmp438, &tmp439, &tmp440, &tmp441, &tmp442, &tmp443);
  return TNode<String>{tmp443};
}

TF_BUILTIN(StringPrototypePadStart, CodeStubAssembler) {
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
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = StringPad_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, "String.prototype.padStart", kStringPadStart_0(state_));
    arguments.PopAndReturn(tmp5);
  }
}

TF_BUILTIN(StringPrototypePadEnd, CodeStubAssembler) {
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
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = StringPad_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, "String.prototype.padEnd", kStringPadEnd_0(state_));
    arguments.PopAndReturn(tmp5);
  }
}

}  // namespace internal
}  // namespace v8

