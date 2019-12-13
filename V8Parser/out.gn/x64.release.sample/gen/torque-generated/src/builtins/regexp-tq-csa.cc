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

TNode<BoolT> IsFastRegExpStrict_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    RegExpBuiltinsAssembler(state_).BranchIfFastRegExp_Strict(TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    TNode<Context> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<BoolT> IsFastRegExpPermissive_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    RegExpBuiltinsAssembler(state_).BranchIfFastRegExp_Permissive(TNode<Context>{tmp0}, TNode<HeapObject>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    TNode<Context> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<Object> RegExpExec_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, JSReceiver, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, JSReceiver, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, Object, JSReceiver> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Object, Object, JSReceiver, JSRegExp> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_JSAny_constexpr_string_0(state_, "exec");
    TNode<Object> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp3});
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_Callable_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp4}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp4, tmp4, tmp4, tmp0, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp4, tmp4, tmp4, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp6;
    TNode<JSReceiver> tmp7;
    TNode<String> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Context> tmp12;
    ca_.Bind(&block5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<JSRegExp> tmp13;
    USE(tmp13);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp13 = Cast_JSRegExp_0(state_, TNode<HeapObject>{tmp7}, &label0);
    ca_.Goto(&block10, tmp6, tmp7, tmp8, tmp9, tmp10, ca_.UncheckedCast<Object>(tmp10), tmp7, tmp13);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp6, tmp7, tmp8, tmp9, tmp10, ca_.UncheckedCast<Object>(tmp10), tmp7);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<String> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Context> tmp20;
    TNode<JSReceiver> tmp21;
    ca_.Bind(&block4, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<Object> tmp22;
    USE(tmp22);
    tmp22 = CodeStubAssembler(state_).Call(TNode<Context>{tmp14}, TNode<JSReceiver>{tmp21}, TNode<Object>{tmp15}, TNode<Object>{tmp16});
    TNode<Oddball> tmp23;
    USE(tmp23);
    tmp23 = Null_0(state_);
    TNode<BoolT> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp22}, TNode<HeapObject>{tmp23});
    ca_.Branch(tmp24, &block6, &block7, tmp14, tmp15, tmp16, tmp17, tmp18, tmp21, tmp22);
  }

  if (block6.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<String> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<Object> tmp31;
    ca_.Bind(&block6, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{tmp25}, TNode<Object>{tmp31}, MessageTemplate::kInvalidRegExpExecResult, "");
    ca_.Goto(&block7, tmp25, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31);
  }

  if (block7.is_used()) {
    TNode<Context> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<String> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block7, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    ca_.Goto(&block1, tmp32, tmp33, tmp34, tmp38);
  }

  if (block11.is_used()) {
    TNode<Context> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<String> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<JSReceiver> tmp45;
    ca_.Bind(&block11, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<Object> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_Object_constexpr_string_0(state_, "RegExp.prototype.exec");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp39}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp46}, TNode<Object>{tmp40});
  }

  if (block10.is_used()) {
    TNode<Context> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<String> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<JSReceiver> tmp53;
    TNode<JSRegExp> tmp54;
    ca_.Bind(&block10, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<Object> tmp55;
    tmp55 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRegExpPrototypeExecSlow, tmp47, tmp54, tmp49);
    USE(tmp55);
    ca_.Goto(&block1, tmp47, tmp48, tmp49, tmp55);
  }

  if (block1.is_used()) {
    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<String> tmp58;
    TNode<Object> tmp59;
    ca_.Bind(&block1, &tmp56, &tmp57, &tmp58, &tmp59);
    ca_.Goto(&block12, tmp56, tmp57, tmp58, tmp59);
  }

    TNode<Context> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<String> tmp62;
    TNode<Object> tmp63;
    ca_.Bind(&block12, &tmp60, &tmp61, &tmp62, &tmp63);
  return TNode<Object>{tmp63};
}

TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<Number> p_regexpLastIndex, bool p_isFastPath, compiler::CodeAssemblerLabel* label_IfDidNotMatch) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, BoolT, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject, RegExpMatchInfo> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject, RegExpMatchInfo> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, Number, Smi, IntPtrT, BoolT, RegExpMatchInfo, HeapObject> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, RegExpMatchInfo> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string, p_regexpLastIndex);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<BoolT> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp4, &block3, &block4, tmp0, tmp1, tmp2, tmp3);
  }

  if (block3.is_used()) {
    TNode<Context> tmp5;
    TNode<JSRegExp> tmp6;
    TNode<String> tmp7;
    TNode<Number> tmp8;
    ca_.Bind(&block3, &tmp5, &tmp6, &tmp7, &tmp8);
    ca_.Goto(&block5, tmp5, tmp6, tmp7, tmp8);
  }

  if (block9.is_used()) {
    TNode<Context> tmp9;
    TNode<JSRegExp> tmp10;
    TNode<String> tmp11;
    TNode<Number> tmp12;
    ca_.Bind(&block9, &tmp9, &tmp10, &tmp11, &tmp12);
    CodeStubAssembler(state_).FailAssert("Torque assert 'HasInitialRegExpMap(regexp)' failed", "src/builtins/regexp.tq", 76);
  }

  if (block8.is_used()) {
    TNode<Context> tmp13;
    TNode<JSRegExp> tmp14;
    TNode<String> tmp15;
    TNode<Number> tmp16;
    ca_.Bind(&block8, &tmp13, &tmp14, &tmp15, &tmp16);
  }

  if (block4.is_used()) {
    TNode<Context> tmp17;
    TNode<JSRegExp> tmp18;
    TNode<String> tmp19;
    TNode<Number> tmp20;
    ca_.Bind(&block4, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<Smi> tmp21;
    USE(tmp21);
    tmp21 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kRegExpExecCalledOnSlowRegExp);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp17, tmp21);
    ca_.Goto(&block5, tmp17, tmp18, tmp19, tmp20);
  }

  if (block5.is_used()) {
    TNode<Context> tmp23;
    TNode<JSRegExp> tmp24;
    TNode<String> tmp25;
    TNode<Number> tmp26;
    ca_.Bind(&block5, &tmp23, &tmp24, &tmp25, &tmp26);
    TNode<IntPtrT> tmp27 = ca_.IntPtrConstant(JSRegExp::kFlagsOffset);
    USE(tmp27);
    TNode<Object>tmp28 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp24, tmp27});
    TNode<Smi> tmp29;
    USE(tmp29);
    tmp29 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp23}, TNode<Object>{tmp28});
    TNode<IntPtrT> tmp30;
    USE(tmp30);
    tmp30 = CodeStubAssembler(state_).SmiUntag(TNode<Smi>{tmp29});
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = CodeStubAssembler(state_).IntPtrConstant(JSRegExp::kGlobal | JSRegExp::kSticky);
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).WordAnd(TNode<IntPtrT>{tmp30}, TNode<IntPtrT>{tmp31});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).WordNotEqual(TNode<IntPtrT>{tmp32}, TNode<IntPtrT>{tmp33});
    ca_.Branch(tmp34, &block10, &block11, tmp23, tmp24, tmp25, tmp26, tmp26, tmp29, tmp32, tmp34);
  }

  if (block10.is_used()) {
    TNode<Context> tmp35;
    TNode<JSRegExp> tmp36;
    TNode<String> tmp37;
    TNode<Number> tmp38;
    TNode<Number> tmp39;
    TNode<Smi> tmp40;
    TNode<IntPtrT> tmp41;
    TNode<BoolT> tmp42;
    ca_.Bind(&block10, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42);
    TNode<BoolT> tmp43;
    USE(tmp43);
    tmp43 = CodeStubAssembler(state_).TaggedIsSmi(TNode<Object>{tmp39});
    TNode<BoolT> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp43});
    ca_.Branch(tmp44, &block15, &block16, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp44);
  }

  if (block15.is_used()) {
    TNode<Context> tmp45;
    TNode<JSRegExp> tmp46;
    TNode<String> tmp47;
    TNode<Number> tmp48;
    TNode<Number> tmp49;
    TNode<Smi> tmp50;
    TNode<IntPtrT> tmp51;
    TNode<BoolT> tmp52;
    TNode<BoolT> tmp53;
    ca_.Bind(&block15, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<BoolT> tmp54;
    USE(tmp54);
    tmp54 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block17, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54);
  }

  if (block16.is_used()) {
    TNode<Context> tmp55;
    TNode<JSRegExp> tmp56;
    TNode<String> tmp57;
    TNode<Number> tmp58;
    TNode<Number> tmp59;
    TNode<Smi> tmp60;
    TNode<IntPtrT> tmp61;
    TNode<BoolT> tmp62;
    TNode<BoolT> tmp63;
    ca_.Bind(&block16, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    TNode<Smi> tmp64;
    USE(tmp64);
    tmp64 = CodeStubAssembler(state_).LoadStringLengthAsSmi(TNode<String>{tmp57});
    TNode<BoolT> tmp65;
    USE(tmp65);
    tmp65 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp59}, TNode<Number>{tmp64});
    ca_.Goto(&block17, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp65);
  }

  if (block17.is_used()) {
    TNode<Context> tmp66;
    TNode<JSRegExp> tmp67;
    TNode<String> tmp68;
    TNode<Number> tmp69;
    TNode<Number> tmp70;
    TNode<Smi> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<BoolT> tmp73;
    TNode<BoolT> tmp74;
    TNode<BoolT> tmp75;
    ca_.Bind(&block17, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    ca_.Branch(tmp75, &block13, &block14, tmp66, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73);
  }

  if (block13.is_used()) {
    TNode<Context> tmp76;
    TNode<JSRegExp> tmp77;
    TNode<String> tmp78;
    TNode<Number> tmp79;
    TNode<Number> tmp80;
    TNode<Smi> tmp81;
    TNode<IntPtrT> tmp82;
    TNode<BoolT> tmp83;
    ca_.Bind(&block13, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83);
    TNode<Smi> tmp84;
    USE(tmp84);
    tmp84 = CodeStubAssembler(state_).SmiConstant(0);
    StoreLastIndex_0(state_, TNode<Context>{tmp76}, TNode<Object>{tmp77}, TNode<Number>{tmp84}, p_isFastPath);
    ca_.Goto(&block1);
  }

  if (block14.is_used()) {
    TNode<Context> tmp85;
    TNode<JSRegExp> tmp86;
    TNode<String> tmp87;
    TNode<Number> tmp88;
    TNode<Number> tmp89;
    TNode<Smi> tmp90;
    TNode<IntPtrT> tmp91;
    TNode<BoolT> tmp92;
    ca_.Bind(&block14, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92);
    ca_.Goto(&block12, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92);
  }

  if (block11.is_used()) {
    TNode<Context> tmp93;
    TNode<JSRegExp> tmp94;
    TNode<String> tmp95;
    TNode<Number> tmp96;
    TNode<Number> tmp97;
    TNode<Smi> tmp98;
    TNode<IntPtrT> tmp99;
    TNode<BoolT> tmp100;
    ca_.Bind(&block11, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100);
    TNode<Smi> tmp101;
    USE(tmp101);
    tmp101 = CodeStubAssembler(state_).SmiConstant(0);
    ca_.Goto(&block12, tmp93, tmp94, tmp95, tmp96, tmp101, tmp98, tmp99, tmp100);
  }

  if (block12.is_used()) {
    TNode<Context> tmp102;
    TNode<JSRegExp> tmp103;
    TNode<String> tmp104;
    TNode<Number> tmp105;
    TNode<Number> tmp106;
    TNode<Smi> tmp107;
    TNode<IntPtrT> tmp108;
    TNode<BoolT> tmp109;
    ca_.Bind(&block12, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109);
    TNode<RegExpMatchInfo> tmp110;
    USE(tmp110);
    tmp110 = GetRegExpLastMatchInfo_0(state_, TNode<Context>{tmp102});
    TNode<HeapObject> tmp111;
    USE(tmp111);
    tmp111 = RegExpBuiltinsAssembler(state_).RegExpExecInternal(TNode<Context>{tmp102}, TNode<JSRegExp>{tmp103}, TNode<String>{tmp104}, TNode<Number>{tmp106}, TNode<RegExpMatchInfo>{tmp110});
    TNode<Oddball> tmp112;
    USE(tmp112);
    tmp112 = Null_0(state_);
    TNode<BoolT> tmp113;
    USE(tmp113);
    tmp113 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp111}, TNode<HeapObject>{tmp112});
    ca_.Branch(tmp113, &block18, &block19, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111);
  }

  if (block18.is_used()) {
    TNode<Context> tmp114;
    TNode<JSRegExp> tmp115;
    TNode<String> tmp116;
    TNode<Number> tmp117;
    TNode<Number> tmp118;
    TNode<Smi> tmp119;
    TNode<IntPtrT> tmp120;
    TNode<BoolT> tmp121;
    TNode<RegExpMatchInfo> tmp122;
    TNode<HeapObject> tmp123;
    ca_.Bind(&block18, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123);
    TNode<RegExpMatchInfo> tmp124;
    USE(tmp124);
    tmp124 = UnsafeCast_RegExpMatchInfo_0(state_, TNode<Context>{tmp114}, TNode<Object>{tmp123});
    ca_.Branch(tmp121, &block20, &block21, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122, tmp123, tmp124);
  }

  if (block20.is_used()) {
    TNode<Context> tmp125;
    TNode<JSRegExp> tmp126;
    TNode<String> tmp127;
    TNode<Number> tmp128;
    TNode<Number> tmp129;
    TNode<Smi> tmp130;
    TNode<IntPtrT> tmp131;
    TNode<BoolT> tmp132;
    TNode<RegExpMatchInfo> tmp133;
    TNode<HeapObject> tmp134;
    TNode<RegExpMatchInfo> tmp135;
    ca_.Bind(&block20, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    TNode<Smi> tmp136;
    USE(tmp136);
    tmp136 = Method_RegExpMatchInfo_GetEndOfCapture_0(state_, TNode<Context>{tmp125}, TNode<RegExpMatchInfo>{tmp135}, 0);
    StoreLastIndex_0(state_, TNode<Context>{tmp125}, TNode<Object>{tmp126}, TNode<Number>{tmp136}, p_isFastPath);
    ca_.Goto(&block21, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135);
  }

  if (block21.is_used()) {
    TNode<Context> tmp137;
    TNode<JSRegExp> tmp138;
    TNode<String> tmp139;
    TNode<Number> tmp140;
    TNode<Number> tmp141;
    TNode<Smi> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<BoolT> tmp144;
    TNode<RegExpMatchInfo> tmp145;
    TNode<HeapObject> tmp146;
    TNode<RegExpMatchInfo> tmp147;
    ca_.Bind(&block21, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147);
    ca_.Goto(&block24, tmp137, tmp138, tmp139, tmp140, tmp147);
  }

  if (block19.is_used()) {
    TNode<Context> tmp148;
    TNode<JSRegExp> tmp149;
    TNode<String> tmp150;
    TNode<Number> tmp151;
    TNode<Number> tmp152;
    TNode<Smi> tmp153;
    TNode<IntPtrT> tmp154;
    TNode<BoolT> tmp155;
    TNode<RegExpMatchInfo> tmp156;
    TNode<HeapObject> tmp157;
    ca_.Bind(&block19, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157);
    ca_.Branch(tmp155, &block22, &block23, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157);
  }

  if (block22.is_used()) {
    TNode<Context> tmp158;
    TNode<JSRegExp> tmp159;
    TNode<String> tmp160;
    TNode<Number> tmp161;
    TNode<Number> tmp162;
    TNode<Smi> tmp163;
    TNode<IntPtrT> tmp164;
    TNode<BoolT> tmp165;
    TNode<RegExpMatchInfo> tmp166;
    TNode<HeapObject> tmp167;
    ca_.Bind(&block22, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167);
    TNode<Smi> tmp168;
    USE(tmp168);
    tmp168 = CodeStubAssembler(state_).SmiConstant(0);
    StoreLastIndex_0(state_, TNode<Context>{tmp158}, TNode<Object>{tmp159}, TNode<Number>{tmp168}, p_isFastPath);
    ca_.Goto(&block23, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167);
  }

  if (block23.is_used()) {
    TNode<Context> tmp169;
    TNode<JSRegExp> tmp170;
    TNode<String> tmp171;
    TNode<Number> tmp172;
    TNode<Number> tmp173;
    TNode<Smi> tmp174;
    TNode<IntPtrT> tmp175;
    TNode<BoolT> tmp176;
    TNode<RegExpMatchInfo> tmp177;
    TNode<HeapObject> tmp178;
    ca_.Bind(&block23, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178);
    ca_.Goto(&block1);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_IfDidNotMatch);
  }

    TNode<Context> tmp179;
    TNode<JSRegExp> tmp180;
    TNode<String> tmp181;
    TNode<Number> tmp182;
    TNode<RegExpMatchInfo> tmp183;
    ca_.Bind(&block24, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183);
  return TNode<RegExpMatchInfo>{tmp183};
}

TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResultFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, compiler::CodeAssemblerLabel* label_IfDidNotMatch) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, JSRegExp, String, Number, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, JSRegExp, String, Number, Context, RegExpMatchInfo> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, RegExpMatchInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = LoadLastIndexAsLength_0(state_, TNode<Context>{tmp0}, TNode<JSRegExp>{tmp1}, true);
    TNode<RegExpMatchInfo> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = RegExpPrototypeExecBodyWithoutResult_0(state_, TNode<Context>{tmp0}, TNode<JSRegExp>{tmp1}, TNode<String>{tmp2}, TNode<Number>{tmp3}, true, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<JSRegExp> tmp6;
    TNode<String> tmp7;
    TNode<Number> tmp8;
    TNode<JSRegExp> tmp9;
    TNode<String> tmp10;
    TNode<Number> tmp11;
    TNode<Context> tmp12;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_IfDidNotMatch);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSRegExp> tmp14;
    TNode<String> tmp15;
    TNode<Number> tmp16;
    TNode<JSRegExp> tmp17;
    TNode<String> tmp18;
    TNode<Number> tmp19;
    TNode<Context> tmp20;
    TNode<RegExpMatchInfo> tmp21;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block5, tmp13, tmp14, tmp15, tmp21);
  }

    TNode<Context> tmp22;
    TNode<JSRegExp> tmp23;
    TNode<String> tmp24;
    TNode<RegExpMatchInfo> tmp25;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25);
  return TNode<RegExpMatchInfo>{tmp25};
}

TNode<RegExpMatchInfo> RegExpPrototypeExecBodyWithoutResultFast_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string, TNode<Number> p_lastIndex, compiler::CodeAssemblerLabel* label_IfDidNotMatch) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, JSRegExp, String, Number, Context> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, JSRegExp, String, Number, Context, RegExpMatchInfo> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Number, RegExpMatchInfo> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string, p_lastIndex);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    TNode<Number> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<RegExpMatchInfo> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = RegExpPrototypeExecBodyWithoutResult_0(state_, TNode<Context>{tmp0}, TNode<JSRegExp>{tmp1}, TNode<String>{tmp2}, TNode<Number>{tmp3}, true, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp2, tmp3, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<JSRegExp> tmp6;
    TNode<String> tmp7;
    TNode<Number> tmp8;
    TNode<JSRegExp> tmp9;
    TNode<String> tmp10;
    TNode<Number> tmp11;
    TNode<Context> tmp12;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    ca_.Goto(label_IfDidNotMatch);
  }

  if (block3.is_used()) {
    TNode<Context> tmp13;
    TNode<JSRegExp> tmp14;
    TNode<String> tmp15;
    TNode<Number> tmp16;
    TNode<JSRegExp> tmp17;
    TNode<String> tmp18;
    TNode<Number> tmp19;
    TNode<Context> tmp20;
    TNode<RegExpMatchInfo> tmp21;
    ca_.Bind(&block3, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    ca_.Goto(&block5, tmp13, tmp14, tmp15, tmp16, tmp21);
  }

    TNode<Context> tmp22;
    TNode<JSRegExp> tmp23;
    TNode<String> tmp24;
    TNode<Number> tmp25;
    TNode<RegExpMatchInfo> tmp26;
    ca_.Bind(&block5, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26);
  return TNode<RegExpMatchInfo>{tmp26};
}

TNode<Object> RegExpPrototypeExecBody_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp, JSReceiver> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp, JSReceiver, JSRegExp> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp, Number, JSRegExp, String, Number, Context> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, JSRegExp, Number, JSRegExp, String, Number, Context, RegExpMatchInfo> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    if ((p_isFastPath)) {
      ca_.Goto(&block2, tmp0, tmp1, tmp2, ca_.Uninitialized<JSRegExp>());
    } else {
      ca_.Goto(&block3, tmp0, tmp1, tmp2, ca_.Uninitialized<JSRegExp>());
    }
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<JSReceiver> tmp4;
    TNode<String> tmp5;
    TNode<JSRegExp> tmp6;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<JSRegExp> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    ca_.Goto(&block4, tmp3, tmp4, tmp5, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<String> tmp10;
    TNode<JSRegExp> tmp11;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10, &tmp11);
    TNode<JSRegExp> tmp12;
    USE(tmp12);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp12 = Cast_JSRegExp_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block7, tmp8, tmp9, tmp10, tmp11, tmp9, tmp12);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp8, tmp9, tmp10, tmp11, tmp9);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp13;
    TNode<JSReceiver> tmp14;
    TNode<String> tmp15;
    TNode<JSRegExp> tmp16;
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block8, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Object> tmp18;
    USE(tmp18);
    tmp18 = FromConstexpr_Object_constexpr_string_0(state_, "RegExp.prototype.exec");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp13}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp18}, TNode<Object>{tmp14});
  }

  if (block7.is_used()) {
    TNode<Context> tmp19;
    TNode<JSReceiver> tmp20;
    TNode<String> tmp21;
    TNode<JSRegExp> tmp22;
    TNode<JSReceiver> tmp23;
    TNode<JSRegExp> tmp24;
    ca_.Bind(&block7, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    ca_.Goto(&block4, tmp19, tmp20, tmp21, tmp24);
  }

  if (block4.is_used()) {
    TNode<Context> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<String> tmp27;
    TNode<JSRegExp> tmp28;
    ca_.Bind(&block4, &tmp25, &tmp26, &tmp27, &tmp28);
    TNode<Number> tmp29;
    USE(tmp29);
    tmp29 = LoadLastIndexAsLength_0(state_, TNode<Context>{tmp25}, TNode<JSRegExp>{tmp28}, p_isFastPath);
    TNode<RegExpMatchInfo> tmp30;
    USE(tmp30);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp30 = RegExpPrototypeExecBodyWithoutResult_0(state_, TNode<Context>{tmp25}, TNode<JSRegExp>{tmp28}, TNode<String>{tmp27}, TNode<Number>{tmp29}, p_isFastPath, &label0);
    ca_.Goto(&block11, tmp25, tmp26, tmp27, tmp28, tmp29, tmp28, tmp27, tmp29, tmp25, tmp30);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp25, tmp26, tmp27, tmp28, tmp29, tmp28, tmp27, tmp29, tmp25);
    }
  }

  if (block12.is_used()) {
    TNode<Context> tmp31;
    TNode<JSReceiver> tmp32;
    TNode<String> tmp33;
    TNode<JSRegExp> tmp34;
    TNode<Number> tmp35;
    TNode<JSRegExp> tmp36;
    TNode<String> tmp37;
    TNode<Number> tmp38;
    TNode<Context> tmp39;
    ca_.Bind(&block12, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39);
    TNode<Oddball> tmp40;
    USE(tmp40);
    tmp40 = Null_0(state_);
    ca_.Goto(&block1, tmp31, tmp32, tmp33, tmp40);
  }

  if (block11.is_used()) {
    TNode<Context> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<String> tmp43;
    TNode<JSRegExp> tmp44;
    TNode<Number> tmp45;
    TNode<JSRegExp> tmp46;
    TNode<String> tmp47;
    TNode<Number> tmp48;
    TNode<Context> tmp49;
    TNode<RegExpMatchInfo> tmp50;
    ca_.Bind(&block11, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<JSArray> tmp51;
    USE(tmp51);
    tmp51 = RegExpBuiltinsAssembler(state_).ConstructNewResultFromMatchInfo(TNode<Context>{tmp41}, TNode<JSRegExp>{tmp44}, TNode<RegExpMatchInfo>{tmp50}, TNode<String>{tmp43}, TNode<Number>{tmp45});
    ca_.Goto(&block1, tmp41, tmp42, tmp43, tmp51);
  }

  if (block1.is_used()) {
    TNode<Context> tmp52;
    TNode<JSReceiver> tmp53;
    TNode<String> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block1, &tmp52, &tmp53, &tmp54, &tmp55);
    ca_.Goto(&block13, tmp52, tmp53, tmp54, tmp55);
  }

    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<String> tmp58;
    TNode<Object> tmp59;
    ca_.Bind(&block13, &tmp56, &tmp57, &tmp58, &tmp59);
  return TNode<Object>{tmp59};
}

TNode<JSFunction> LoadRegExpFunction_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, JSFunction> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<IntPtrT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_NativeContextSlot_constexpr_NativeContextSlot_0(state_, Context::REGEXP_FUNCTION_INDEX);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).LoadContextElement(TNode<NativeContext>{tmp1}, TNode<IntPtrT>{tmp2});
    TNode<JSFunction> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSFunction_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp4);
  }

    TNode<Context> tmp5;
    TNode<NativeContext> tmp6;
    TNode<JSFunction> tmp7;
    ca_.Bind(&block2, &tmp5, &tmp6, &tmp7);
  return TNode<JSFunction>{tmp7};
}

TNode<BoolT> HasInitialRegExpMap_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<NativeContext> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<JSFunction> tmp3;
    USE(tmp3);
    tmp3 = LoadRegExpFunction_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSFunction::kPrototypeOrInitialMapOffset);
    USE(tmp4);
    TNode<HeapObject>tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp4});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp7);
    TNode<Map>tmp8 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp1, tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp6}, TNode<HeapObject>{tmp8});
    ca_.Goto(&block2, tmp0, tmp1, tmp9);
  }

    TNode<Context> tmp10;
    TNode<HeapObject> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12);
  return TNode<BoolT>{tmp12};
}

TNode<BoolT> IsReceiverInitialRegExpPrototype_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<NativeContext> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).LoadNativeContext(TNode<Context>{tmp0});
    TNode<JSFunction> tmp3;
    USE(tmp3);
    tmp3 = LoadRegExpFunction_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSFunction::kPrototypeOrInitialMapOffset);
    USE(tmp4);
    TNode<HeapObject>tmp5 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp3, tmp4});
    TNode<Map> tmp6;
    USE(tmp6);
    tmp6 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7 = ca_.IntPtrConstant(Map::kPrototypeOffset);
    USE(tmp7);
    TNode<HeapObject>tmp8 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp6, tmp7});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).TaggedEqual(TNode<MaybeObject>{tmp1}, TNode<MaybeObject>{tmp8});
    ca_.Goto(&block2, tmp0, tmp1, tmp9);
  }

    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<BoolT> tmp12;
    ca_.Bind(&block2, &tmp10, &tmp11, &tmp12);
  return TNode<BoolT>{tmp12};
}

TNode<Object> FlagGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, JSRegExp::Flag p_flag, int31_t p_counter, const char* p_methodName) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Object, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSRegExp_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1, tmp1, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<Object> tmp6;
    TNode<Context> tmp7;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5, &tmp6, &tmp7);
    TNode<BoolT> tmp8;
    USE(tmp8);
    tmp8 = IsReceiverInitialRegExpPrototype_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp8});
    ca_.Branch(tmp9, &block6, &block7, tmp3, tmp4);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Context> tmp14;
    TNode<JSRegExp> tmp15;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = RegExpBuiltinsAssembler(state_).FastFlagGetter(TNode<JSRegExp>{tmp15}, p_flag);
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).SelectBooleanConstant(TNode<BoolT>{tmp16});
    ca_.Goto(&block1, tmp10, tmp11, tmp17);
  }

  if (block6.is_used()) {
    TNode<Context> tmp18;
    TNode<Object> tmp19;
    ca_.Bind(&block6, &tmp18, &tmp19);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp18}, MessageTemplate::kRegExpNonRegExp, p_methodName);
  }

  if (block7.is_used()) {
    TNode<Context> tmp20;
    TNode<Object> tmp21;
    ca_.Bind(&block7, &tmp20, &tmp21);
    if (((CodeStubAssembler(state_).ConstexprInt31NotEqual(p_counter, -1)))) {
      ca_.Goto(&block8, tmp20, tmp21);
    } else {
      ca_.Goto(&block9, tmp20, tmp21);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    ca_.Bind(&block8, &tmp22, &tmp23);
    TNode<Smi> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).SmiConstant(p_counter);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp22, tmp24);
    ca_.Goto(&block10, tmp22, tmp23);
  }

  if (block9.is_used()) {
    TNode<Context> tmp26;
    TNode<Object> tmp27;
    ca_.Bind(&block9, &tmp26, &tmp27);
    ca_.Goto(&block10, tmp26, tmp27);
  }

  if (block10.is_used()) {
    TNode<Context> tmp28;
    TNode<Object> tmp29;
    ca_.Bind(&block10, &tmp28, &tmp29);
    TNode<Oddball> tmp30;
    USE(tmp30);
    tmp30 = Undefined_0(state_);
    ca_.Goto(&block1, tmp28, tmp29, tmp30);
  }

  if (block1.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<Object> tmp33;
    ca_.Bind(&block1, &tmp31, &tmp32, &tmp33);
    ca_.Goto(&block11, tmp31, tmp32, tmp33);
  }

    TNode<Context> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    ca_.Bind(&block11, &tmp34, &tmp35, &tmp36);
  return TNode<Object>{tmp36};
}

TF_BUILTIN(RegExpPrototypeGlobalGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kGlobal, v8::Isolate::kRegExpPrototypeOldFlagGetter, "RegExp.prototype.global");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(RegExpPrototypeIgnoreCaseGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kIgnoreCase, v8::Isolate::kRegExpPrototypeOldFlagGetter, "RegExp.prototype.ignoreCase");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(RegExpPrototypeMultilineGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kMultiline, v8::Isolate::kRegExpPrototypeOldFlagGetter, "RegExp.prototype.multiline");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(RegExpPrototypeDotAllGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kDotAll, -1, "RegExp.prototype.dotAll");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(RegExpPrototypeStickyGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kSticky, v8::Isolate::kRegExpPrototypeStickyGetter, "RegExp.prototype.sticky");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TF_BUILTIN(RegExpPrototypeUnicodeGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = FlagGetter_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, JSRegExp::kUnicode, v8::Isolate::kRegExpPrototypeUnicodeGetter, "RegExp.prototype.unicode");
    CodeStubAssembler(state_).Return(tmp2);
  }
}

TNode<String> FastFlagsGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = RegExpBuiltinsAssembler(state_).FlagsGetter(TNode<Context>{tmp0}, TNode<Object>{tmp1}, true);
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Context> tmp3;
    TNode<JSRegExp> tmp4;
    TNode<String> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<String>{tmp5};
}

TNode<String> SlowFlagsGetter_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = RegExpBuiltinsAssembler(state_).FlagsGetter(TNode<Context>{tmp0}, TNode<Object>{tmp1}, false);
    ca_.Goto(&block2, tmp0, tmp1, tmp2);
  }

    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<String> tmp5;
    ca_.Bind(&block2, &tmp3, &tmp4, &tmp5);
  return TNode<String>{tmp5};
}

TF_BUILTIN(RegExpPrototypeFlagsGetter, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, JSRegExp> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{tmp0}, TNode<Object>{tmp1}, MessageTemplate::kRegExpNonObject, "RegExp.prototype.flags");
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_FastJSRegExp_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<NativeContext> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = SlowFlagsGetter_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    CodeStubAssembler(state_).Return(tmp7);
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<NativeContext> tmp11;
    TNode<JSRegExp> tmp12;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<String> tmp13;
    USE(tmp13);
    tmp13 = FastFlagsGetter_0(state_, TNode<Context>{tmp8}, TNode<JSRegExp>{tmp12});
    CodeStubAssembler(state_).Return(tmp13);
  }
}

TNode<Object> LoadLastIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_regexp, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<BoolT> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp2, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block2, &tmp3, &tmp4);
    TNode<JSRegExp> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Smi> tmp6;
    USE(tmp6);
    tmp6 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp5});
    ca_.Goto(&block4, tmp3, tmp4, tmp6);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<Object> tmp8;
    ca_.Bind(&block3, &tmp7, &tmp8);
    TNode<Object> tmp9;
    USE(tmp9);
    tmp9 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp7}, TNode<Object>{tmp8});
    ca_.Goto(&block4, tmp7, tmp8, tmp9);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12);
    ca_.Goto(&block6, tmp10, tmp11, tmp12);
  }

    TNode<Context> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    ca_.Bind(&block6, &tmp13, &tmp14, &tmp15);
  return TNode<Object>{tmp15};
}

TNode<Number> LoadLastIndexAsLength_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Object> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Object, Object, Object> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Object, Object, Object, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = LoadLastIndex_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, p_isFastPath);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<JSRegExp> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<Smi> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_PositiveSmi_0(state_, TNode<Context>{tmp4}, TNode<Object>{tmp6});
    ca_.Goto(&block1, tmp4, tmp5, tmp7);
  }

  if (block3.is_used()) {
    TNode<Context> tmp8;
    TNode<JSRegExp> tmp9;
    TNode<Object> tmp10;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10);
    TNode<Smi> tmp11;
    USE(tmp11);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp11 = Cast_PositiveSmi_0(state_, TNode<Object>{tmp10}, &label0);
    ca_.Goto(&block7, tmp8, tmp9, tmp10, tmp10, tmp10, tmp11);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp8, tmp9, tmp10, tmp10, tmp10);
    }
  }

  if (block8.is_used()) {
    TNode<Context> tmp12;
    TNode<JSRegExp> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<Object> tmp16;
    ca_.Bind(&block8, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Number> tmp17;
    USE(tmp17);
    tmp17 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp12}, TNode<Object>{ca_.UncheckedCast<Object>(tmp15)});
    ca_.Goto(&block1, tmp12, tmp13, tmp17);
  }

  if (block7.is_used()) {
    TNode<Context> tmp18;
    TNode<JSRegExp> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    ca_.Goto(&block1, tmp18, tmp19, tmp23);
  }

  if (block1.is_used()) {
    TNode<Context> tmp24;
    TNode<JSRegExp> tmp25;
    TNode<Number> tmp26;
    ca_.Bind(&block1, &tmp24, &tmp25, &tmp26);
    ca_.Goto(&block9, tmp24, tmp25, tmp26);
  }

    TNode<Context> tmp27;
    TNode<JSRegExp> tmp28;
    TNode<Number> tmp29;
    ca_.Bind(&block9, &tmp27, &tmp28, &tmp29);
  return TNode<Number>{tmp29};
}

void StoreLastIndex_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_regexp, TNode<Number> p_value, bool p_isFastPath) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_value);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<Number> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = FromConstexpr_bool_constexpr_bool_0(state_, p_isFastPath);
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1, tmp2);
  }

  if (block2.is_used()) {
    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
    TNode<JSRegExp> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp4}, TNode<Object>{tmp5});
    TNode<Smi> tmp8;
    USE(tmp8);
    tmp8 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp4}, TNode<Object>{tmp6});
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp7}, TNode<Smi>{tmp8});
    ca_.Goto(&block4, tmp4, tmp5, tmp6);
  }

  if (block3.is_used()) {
    TNode<Context> tmp9;
    TNode<Object> tmp10;
    TNode<Number> tmp11;
    ca_.Bind(&block3, &tmp9, &tmp10, &tmp11);
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp9}, TNode<Object>{tmp10}, TNode<Object>{tmp11});
    ca_.Goto(&block4, tmp9, tmp10, tmp11);
  }

  if (block4.is_used()) {
    TNode<Context> tmp12;
    TNode<Object> tmp13;
    TNode<Number> tmp14;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block5, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<Number> tmp17;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17);
}

TNode<BoolT> IsRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_obj) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, Context, JSReceiver> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block11(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block19(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSReceiver, Object> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_obj);

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
    TNode<Symbol> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).MatchSymbolConstant();
    TNode<Object> tmp14;
    USE(tmp14);
    tmp14 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp8}, TNode<Object>{tmp12}, TNode<Object>{tmp13});
    TNode<Oddball> tmp15;
    USE(tmp15);
    tmp15 = Undefined_0(state_);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp14}, TNode<HeapObject>{tmp15});
    ca_.Branch(tmp16, &block6, &block7, tmp8, tmp9, tmp12, tmp14);
  }

  if (block6.is_used()) {
    TNode<Context> tmp17;
    TNode<Object> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Object> tmp20;
    ca_.Bind(&block6, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<BoolT> tmp21;
    USE(tmp21);
    tmp21 = Is_JSRegExp_JSReceiver_0(state_, TNode<Context>{tmp17}, TNode<JSReceiver>{tmp19});
    ca_.Goto(&block1, tmp17, tmp18, tmp21);
  }

  if (block7.is_used()) {
    TNode<Context> tmp22;
    TNode<Object> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<Object> tmp25;
    ca_.Bind(&block7, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<BoolT> tmp26;
    USE(tmp26);
    tmp26 = ToBoolean_0(state_, TNode<Object>{tmp25});
    ca_.Branch(tmp26, &block12, &block13, tmp22, tmp23, tmp24, tmp25);
  }

  if (block11.is_used()) {
    TNode<Context> tmp27;
    TNode<Object> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Object> tmp30;
    ca_.Bind(&block11, &tmp27, &tmp28, &tmp29, &tmp30);
    CodeStubAssembler(state_).FailAssert("Torque assert 'value != Undefined' failed", "src/builtins/regexp.tq", 388);
  }

  if (block10.is_used()) {
    TNode<Context> tmp31;
    TNode<Object> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block10, &tmp31, &tmp32, &tmp33, &tmp34);
  }

  if (block12.is_used()) {
    TNode<Context> tmp35;
    TNode<Object> tmp36;
    TNode<JSReceiver> tmp37;
    TNode<Object> tmp38;
    ca_.Bind(&block12, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<BoolT> tmp39;
    USE(tmp39);
    tmp39 = Is_JSRegExp_JSReceiver_0(state_, TNode<Context>{tmp35}, TNode<JSReceiver>{tmp37});
    TNode<BoolT> tmp40;
    USE(tmp40);
    tmp40 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp39});
    ca_.Branch(tmp40, &block14, &block15, tmp35, tmp36, tmp37, tmp38);
  }

  if (block14.is_used()) {
    TNode<Context> tmp41;
    TNode<Object> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<Object> tmp44;
    ca_.Bind(&block14, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kRegExpMatchIsTrueishOnNonJSRegExp);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp41, tmp45);
    ca_.Goto(&block15, tmp41, tmp42, tmp43, tmp44);
  }

  if (block15.is_used()) {
    TNode<Context> tmp47;
    TNode<Object> tmp48;
    TNode<JSReceiver> tmp49;
    TNode<Object> tmp50;
    ca_.Bind(&block15, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp47, tmp48, tmp51);
  }

  if (block13.is_used()) {
    TNode<Context> tmp52;
    TNode<Object> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<Object> tmp55;
    ca_.Bind(&block13, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = Is_JSRegExp_JSReceiver_0(state_, TNode<Context>{tmp52}, TNode<JSReceiver>{tmp54});
    ca_.Branch(tmp56, &block20, &block21, tmp52, tmp53, tmp54, tmp55);
  }

  if (block19.is_used()) {
    TNode<Context> tmp57;
    TNode<Object> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<Object> tmp60;
    ca_.Bind(&block19, &tmp57, &tmp58, &tmp59, &tmp60);
    CodeStubAssembler(state_).FailAssert("Torque assert '!ToBoolean(value)' failed", "src/builtins/regexp.tq", 399);
  }

  if (block18.is_used()) {
    TNode<Context> tmp61;
    TNode<Object> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<Object> tmp64;
    ca_.Bind(&block18, &tmp61, &tmp62, &tmp63, &tmp64);
  }

  if (block20.is_used()) {
    TNode<Context> tmp65;
    TNode<Object> tmp66;
    TNode<JSReceiver> tmp67;
    TNode<Object> tmp68;
    ca_.Bind(&block20, &tmp65, &tmp66, &tmp67, &tmp68);
    TNode<Smi> tmp69;
    USE(tmp69);
    tmp69 = CodeStubAssembler(state_).SmiConstant(v8::Isolate::kRegExpMatchIsFalseishOnJSRegExp);
    CodeStubAssembler(state_).CallRuntime(Runtime::kIncrementUseCounter, tmp65, tmp69);
    ca_.Goto(&block21, tmp65, tmp66, tmp67, tmp68);
  }

  if (block21.is_used()) {
    TNode<Context> tmp71;
    TNode<Object> tmp72;
    TNode<JSReceiver> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block21, &tmp71, &tmp72, &tmp73, &tmp74);
    TNode<BoolT> tmp75;
    USE(tmp75);
    tmp75 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp71, tmp72, tmp75);
  }

  if (block1.is_used()) {
    TNode<Context> tmp76;
    TNode<Object> tmp77;
    TNode<BoolT> tmp78;
    ca_.Bind(&block1, &tmp76, &tmp77, &tmp78);
    ca_.Goto(&block22, tmp76, tmp77, tmp78);
  }

    TNode<Context> tmp79;
    TNode<Object> tmp80;
    TNode<BoolT> tmp81;
    ca_.Bind(&block22, &tmp79, &tmp80, &tmp81);
  return TNode<BoolT>{tmp81};
}

TNode<Object> RegExpCreate_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_maybeString, TNode<String> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, String, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_maybeString, p_flags);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<String> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSFunction> tmp4;
    USE(tmp4);
    tmp4 = LoadRegExpFunction_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp1});
    TNode<IntPtrT> tmp5 = ca_.IntPtrConstant(JSFunction::kPrototypeOrInitialMapOffset);
    USE(tmp5);
    TNode<HeapObject>tmp6 = CodeStubAssembler(state_).LoadReference<HeapObject>(CodeStubAssembler::Reference{tmp4, tmp5});
    TNode<Map> tmp7;
    USE(tmp7);
    tmp7 = UnsafeCast_Map_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp6});
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = RegExpCreate_1(state_, TNode<Context>{tmp0}, TNode<Map>{tmp7}, TNode<Object>{tmp2}, TNode<String>{tmp3});
    ca_.Goto(&block2, tmp0, tmp1, tmp2, tmp3, tmp8);
  }

    TNode<Context> tmp9;
    TNode<NativeContext> tmp10;
    TNode<Object> tmp11;
    TNode<String> tmp12;
    TNode<Object> tmp13;
    ca_.Bind(&block2, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13);
  return TNode<Object>{tmp13};
}

TNode<Object> RegExpCreate_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Map> p_initialMap, TNode<Object> p_maybeString, TNode<String> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, String> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, String, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Map, Object, String, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_initialMap, p_maybeString, p_flags);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Map> tmp1;
    TNode<Object> tmp2;
    TNode<String> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<Oddball> tmp4;
    USE(tmp4);
    tmp4 = Undefined_0(state_);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp2}, TNode<HeapObject>{tmp4});
    ca_.Branch(tmp5, &block2, &block3, tmp0, tmp1, tmp2, tmp3);
  }

  if (block2.is_used()) {
    TNode<Context> tmp6;
    TNode<Map> tmp7;
    TNode<Object> tmp8;
    TNode<String> tmp9;
    ca_.Bind(&block2, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<String> tmp10;
    USE(tmp10);
    tmp10 = kEmptyString_0(state_);
    ca_.Goto(&block4, tmp6, tmp7, tmp8, tmp9, tmp10);
  }

  if (block3.is_used()) {
    TNode<Context> tmp11;
    TNode<Map> tmp12;
    TNode<Object> tmp13;
    TNode<String> tmp14;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14);
    TNode<String> tmp15;
    USE(tmp15);
    tmp15 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp11}, TNode<Object>{tmp13});
    ca_.Goto(&block4, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block4.is_used()) {
    TNode<Context> tmp16;
    TNode<Map> tmp17;
    TNode<Object> tmp18;
    TNode<String> tmp19;
    TNode<String> tmp20;
    ca_.Bind(&block4, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20);
    TNode<JSObject> tmp21;
    USE(tmp21);
    tmp21 = AllocateFastOrSlowJSObjectFromMap_0(state_, TNode<Context>{tmp16}, TNode<Map>{tmp17});
    TNode<JSRegExp> tmp22;
    USE(tmp22);
    tmp22 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp16}, TNode<Object>{tmp21});
    TNode<Object> tmp23;
    tmp23 = CodeStubAssembler(state_).CallRuntime(Runtime::kRegExpInitializeAndCompile, tmp16, tmp22, tmp20, tmp19); 
    USE(tmp23);
    ca_.Goto(&block6, tmp16, tmp17, tmp18, tmp19, tmp23);
  }

    TNode<Context> tmp24;
    TNode<Map> tmp25;
    TNode<Object> tmp26;
    TNode<String> tmp27;
    TNode<Object> tmp28;
    ca_.Bind(&block6, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
  return TNode<Object>{tmp28};
}

TNode<JSRegExp> Cast_FastJSRegExp_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSRegExp> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSRegExp> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSRegExp> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
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
    TNode<JSRegExp> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSRegExp> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSRegExp>{tmp22};
}

TNode<Smi> UnsafeCast_PositiveSmi_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Smi> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
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
    TNode<Smi> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Smi>{tmp9};
}

TNode<BoolT> Is_JSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSRegExp_0(state_, TNode<HeapObject>{tmp1}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp1);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<JSReceiver> tmp4;
    TNode<JSReceiver> tmp5;
    ca_.Bind(&block5, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp3, tmp4, tmp6);
  }

  if (block4.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<JSRegExp> tmp10;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

}  // namespace internal
}  // namespace v8

