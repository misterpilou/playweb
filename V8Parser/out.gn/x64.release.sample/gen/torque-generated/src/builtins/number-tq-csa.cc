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

int32_t kAsciiZero_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 48;
}

int32_t kAsciiLowerCaseA_0(compiler::CodeAssemblerState* state_) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0);

    ca_.Bind(&block0);
return 97;
}

TNode<Number> ThisNumberValue_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_receiver, const char* p_method) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_receiver);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Object> tmp2;
    USE(tmp2);
    tmp2 = CodeStubAssembler(state_).ToThisValue(TNode<Context>{tmp0}, TNode<Object>{tmp1}, PrimitiveType::kNumber, p_method);
    TNode<Number> tmp3;
    USE(tmp3);
    tmp3 = UnsafeCast_Number_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2});
    ca_.Goto(&block2, tmp0, tmp1, tmp3);
  }

    TNode<Context> tmp4;
    TNode<Object> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block2, &tmp4, &tmp5, &tmp6);
  return TNode<Number>{tmp6};
}

TF_BUILTIN(NumberPrototypeToString, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT, BoolT> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, BoolT, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, Int32T> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, Int32T> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number, Int32T> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, Number, Object, Number> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Number> tmp5;
    USE(tmp5);
    tmp5 = ThisNumberValue_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, "Number.prototype.toString");
    TNode<IntPtrT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp6});
    TNode<Oddball> tmp8;
    USE(tmp8);
    tmp8 = Undefined_0(state_);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp7}, TNode<HeapObject>{tmp8});
    ca_.Branch(tmp9, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp7);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<Number> tmp15;
    TNode<Object> tmp16;
    ca_.Bind(&block1, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Number> tmp17;
    USE(tmp17);
    tmp17 = FromConstexpr_Number_constexpr_int31_0(state_, 10);
    ca_.Goto(&block3, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp18;
    TNode<RawPtrT> tmp19;
    TNode<IntPtrT> tmp20;
    TNode<NativeContext> tmp21;
    TNode<Object> tmp22;
    TNode<Number> tmp23;
    TNode<Object> tmp24;
    ca_.Bind(&block2, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24);
    TNode<Number> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp21}, TNode<Object>{tmp24}, CodeStubAssembler::ToIntegerTruncationMode::kTruncateMinusZero);
    ca_.Goto(&block3, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp26;
    TNode<RawPtrT> tmp27;
    TNode<IntPtrT> tmp28;
    TNode<NativeContext> tmp29;
    TNode<Object> tmp30;
    TNode<Number> tmp31;
    TNode<Object> tmp32;
    TNode<Number> tmp33;
    ca_.Bind(&block3, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Number> tmp34;
    USE(tmp34);
    tmp34 = FromConstexpr_Number_constexpr_int31_0(state_, 2);
    TNode<BoolT> tmp35;
    USE(tmp35);
    tmp35 = NumberIsLessThan_0(state_, TNode<Number>{tmp33}, TNode<Number>{tmp34});
    ca_.Branch(tmp35, &block7, &block8, tmp26, tmp27, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp35);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<Number> tmp41;
    TNode<Object> tmp42;
    TNode<Number> tmp43;
    TNode<BoolT> tmp44;
    ca_.Bind(&block7, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44);
    TNode<BoolT> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block9, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp46;
    TNode<RawPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<NativeContext> tmp49;
    TNode<Object> tmp50;
    TNode<Number> tmp51;
    TNode<Object> tmp52;
    TNode<Number> tmp53;
    TNode<BoolT> tmp54;
    ca_.Bind(&block8, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    TNode<Number> tmp55;
    USE(tmp55);
    tmp55 = FromConstexpr_Number_constexpr_int31_0(state_, 36);
    TNode<BoolT> tmp56;
    USE(tmp56);
    tmp56 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp53}, TNode<Number>{tmp55});
    ca_.Goto(&block9, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp56);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp57;
    TNode<RawPtrT> tmp58;
    TNode<IntPtrT> tmp59;
    TNode<NativeContext> tmp60;
    TNode<Object> tmp61;
    TNode<Number> tmp62;
    TNode<Object> tmp63;
    TNode<Number> tmp64;
    TNode<BoolT> tmp65;
    TNode<BoolT> tmp66;
    ca_.Bind(&block9, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66);
    ca_.Branch(tmp66, &block5, &block6, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp67;
    TNode<RawPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<NativeContext> tmp70;
    TNode<Object> tmp71;
    TNode<Number> tmp72;
    TNode<Object> tmp73;
    TNode<Number> tmp74;
    ca_.Bind(&block5, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    CodeStubAssembler(state_).ThrowRangeError(TNode<Context>{tmp70}, MessageTemplate::kToRadixFormatRange);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp75;
    TNode<RawPtrT> tmp76;
    TNode<IntPtrT> tmp77;
    TNode<NativeContext> tmp78;
    TNode<Object> tmp79;
    TNode<Number> tmp80;
    TNode<Object> tmp81;
    TNode<Number> tmp82;
    ca_.Bind(&block6, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82);
    TNode<Number> tmp83;
    USE(tmp83);
    tmp83 = FromConstexpr_Number_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp84;
    USE(tmp84);
    tmp84 = IsNumberEqual_0(state_, TNode<Number>{tmp82}, TNode<Number>{tmp83});
    ca_.Branch(tmp84, &block10, &block11, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp85;
    TNode<RawPtrT> tmp86;
    TNode<IntPtrT> tmp87;
    TNode<NativeContext> tmp88;
    TNode<Object> tmp89;
    TNode<Number> tmp90;
    TNode<Object> tmp91;
    TNode<Number> tmp92;
    ca_.Bind(&block10, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92);
    TNode<String> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).NumberToString(TNode<Number>{tmp90});
    arguments.PopAndReturn(tmp93);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp94;
    TNode<RawPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<NativeContext> tmp97;
    TNode<Object> tmp98;
    TNode<Number> tmp99;
    TNode<Object> tmp100;
    TNode<Number> tmp101;
    ca_.Bind(&block11, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101);
    TNode<BoolT> tmp102;
    USE(tmp102);
    tmp102 = CodeStubAssembler(state_).TaggedIsPositiveSmi(TNode<Object>{tmp99});
    ca_.Branch(tmp102, &block14, &block15, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp102);
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp103;
    TNode<RawPtrT> tmp104;
    TNode<IntPtrT> tmp105;
    TNode<NativeContext> tmp106;
    TNode<Object> tmp107;
    TNode<Number> tmp108;
    TNode<Object> tmp109;
    TNode<Number> tmp110;
    TNode<BoolT> tmp111;
    ca_.Bind(&block14, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111);
    TNode<BoolT> tmp112;
    USE(tmp112);
    tmp112 = NumberIsLessThan_0(state_, TNode<Number>{tmp108}, TNode<Number>{tmp110});
    ca_.Goto(&block16, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp112);
  }

  if (block15.is_used()) {
    TNode<RawPtrT> tmp113;
    TNode<RawPtrT> tmp114;
    TNode<IntPtrT> tmp115;
    TNode<NativeContext> tmp116;
    TNode<Object> tmp117;
    TNode<Number> tmp118;
    TNode<Object> tmp119;
    TNode<Number> tmp120;
    TNode<BoolT> tmp121;
    ca_.Bind(&block15, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121);
    TNode<BoolT> tmp122;
    USE(tmp122);
    tmp122 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block16, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp119, tmp120, tmp121, tmp122);
  }

  if (block16.is_used()) {
    TNode<RawPtrT> tmp123;
    TNode<RawPtrT> tmp124;
    TNode<IntPtrT> tmp125;
    TNode<NativeContext> tmp126;
    TNode<Object> tmp127;
    TNode<Number> tmp128;
    TNode<Object> tmp129;
    TNode<Number> tmp130;
    TNode<BoolT> tmp131;
    TNode<BoolT> tmp132;
    ca_.Bind(&block16, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132);
    ca_.Branch(tmp132, &block12, &block13, tmp123, tmp124, tmp125, tmp126, tmp127, tmp128, tmp129, tmp130);
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp133;
    TNode<RawPtrT> tmp134;
    TNode<IntPtrT> tmp135;
    TNode<NativeContext> tmp136;
    TNode<Object> tmp137;
    TNode<Number> tmp138;
    TNode<Object> tmp139;
    TNode<Number> tmp140;
    ca_.Bind(&block12, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    TNode<Smi> tmp141;
    USE(tmp141);
    tmp141 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp136}, TNode<Object>{tmp138});
    TNode<Int32T> tmp142;
    USE(tmp142);
    tmp142 = Convert_int32_Smi_0(state_, TNode<Smi>{tmp141});
    TNode<Int32T> tmp143;
    USE(tmp143);
    tmp143 = FromConstexpr_int32_constexpr_int31_0(state_, 10);
    TNode<BoolT> tmp144;
    USE(tmp144);
    tmp144 = CodeStubAssembler(state_).Int32LessThan(TNode<Int32T>{tmp142}, TNode<Int32T>{tmp143});
    ca_.Branch(tmp144, &block17, &block18, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140, tmp142);
  }

  if (block17.is_used()) {
    TNode<RawPtrT> tmp145;
    TNode<RawPtrT> tmp146;
    TNode<IntPtrT> tmp147;
    TNode<NativeContext> tmp148;
    TNode<Object> tmp149;
    TNode<Number> tmp150;
    TNode<Object> tmp151;
    TNode<Number> tmp152;
    TNode<Int32T> tmp153;
    ca_.Bind(&block17, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153);
    TNode<Int32T> tmp154;
    USE(tmp154);
    tmp154 = FromConstexpr_int32_constexpr_int32_0(state_, kAsciiZero_0(state_));
    TNode<Int32T> tmp155;
    USE(tmp155);
    tmp155 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp153}, TNode<Int32T>{tmp154});
    ca_.Goto(&block19, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp155);
  }

  if (block18.is_used()) {
    TNode<RawPtrT> tmp156;
    TNode<RawPtrT> tmp157;
    TNode<IntPtrT> tmp158;
    TNode<NativeContext> tmp159;
    TNode<Object> tmp160;
    TNode<Number> tmp161;
    TNode<Object> tmp162;
    TNode<Number> tmp163;
    TNode<Int32T> tmp164;
    ca_.Bind(&block18, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164);
    TNode<Int32T> tmp165;
    USE(tmp165);
    tmp165 = FromConstexpr_int32_constexpr_int31_0(state_, 10);
    TNode<Int32T> tmp166;
    USE(tmp166);
    tmp166 = CodeStubAssembler(state_).Int32Sub(TNode<Int32T>{tmp164}, TNode<Int32T>{tmp165});
    TNode<Int32T> tmp167;
    USE(tmp167);
    tmp167 = FromConstexpr_int32_constexpr_int32_0(state_, kAsciiLowerCaseA_0(state_));
    TNode<Int32T> tmp168;
    USE(tmp168);
    tmp168 = CodeStubAssembler(state_).Int32Add(TNode<Int32T>{tmp166}, TNode<Int32T>{tmp167});
    ca_.Goto(&block19, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp168);
  }

  if (block19.is_used()) {
    TNode<RawPtrT> tmp169;
    TNode<RawPtrT> tmp170;
    TNode<IntPtrT> tmp171;
    TNode<NativeContext> tmp172;
    TNode<Object> tmp173;
    TNode<Number> tmp174;
    TNode<Object> tmp175;
    TNode<Number> tmp176;
    TNode<Int32T> tmp177;
    ca_.Bind(&block19, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177);
    TNode<String> tmp178;
    USE(tmp178);
    tmp178 = CodeStubAssembler(state_).StringFromSingleCharCode(TNode<Int32T>{tmp177});
    arguments.PopAndReturn(tmp178);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp179;
    TNode<RawPtrT> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<NativeContext> tmp182;
    TNode<Object> tmp183;
    TNode<Number> tmp184;
    TNode<Object> tmp185;
    TNode<Number> tmp186;
    ca_.Bind(&block13, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186);
    TNode<Number> tmp187;
    USE(tmp187);
    tmp187 = FromConstexpr_Number_constexpr_int31_0(state_, -0);
    TNode<BoolT> tmp188;
    USE(tmp188);
    tmp188 = IsNumberEqual_0(state_, TNode<Number>{tmp184}, TNode<Number>{tmp187});
    ca_.Branch(tmp188, &block20, &block21, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186);
  }

  if (block20.is_used()) {
    TNode<RawPtrT> tmp189;
    TNode<RawPtrT> tmp190;
    TNode<IntPtrT> tmp191;
    TNode<NativeContext> tmp192;
    TNode<Object> tmp193;
    TNode<Number> tmp194;
    TNode<Object> tmp195;
    TNode<Number> tmp196;
    ca_.Bind(&block20, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196);
    TNode<String> tmp197;
    USE(tmp197);
    tmp197 = CodeStubAssembler(state_).ZeroStringConstant();
    arguments.PopAndReturn(tmp197);
  }

  if (block21.is_used()) {
    TNode<RawPtrT> tmp198;
    TNode<RawPtrT> tmp199;
    TNode<IntPtrT> tmp200;
    TNode<NativeContext> tmp201;
    TNode<Object> tmp202;
    TNode<Number> tmp203;
    TNode<Object> tmp204;
    TNode<Number> tmp205;
    ca_.Bind(&block21, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205);
    TNode<BoolT> tmp206;
    USE(tmp206);
    tmp206 = NumberIsNaN_0(state_, TNode<Number>{tmp203});
    ca_.Branch(tmp206, &block23, &block24, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205);
  }

  if (block23.is_used()) {
    TNode<RawPtrT> tmp207;
    TNode<RawPtrT> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<NativeContext> tmp210;
    TNode<Object> tmp211;
    TNode<Number> tmp212;
    TNode<Object> tmp213;
    TNode<Number> tmp214;
    ca_.Bind(&block23, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214);
    TNode<String> tmp215;
    USE(tmp215);
    tmp215 = CodeStubAssembler(state_).NaNStringConstant();
    arguments.PopAndReturn(tmp215);
  }

  if (block24.is_used()) {
    TNode<RawPtrT> tmp216;
    TNode<RawPtrT> tmp217;
    TNode<IntPtrT> tmp218;
    TNode<NativeContext> tmp219;
    TNode<Object> tmp220;
    TNode<Number> tmp221;
    TNode<Object> tmp222;
    TNode<Number> tmp223;
    ca_.Bind(&block24, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223);
    TNode<Number> tmp224;
    USE(tmp224);
    tmp224 = FromConstexpr_Number_constexpr_float64_0(state_, V8_INFINITY);
    TNode<BoolT> tmp225;
    USE(tmp225);
    tmp225 = IsNumberEqual_0(state_, TNode<Number>{tmp221}, TNode<Number>{tmp224});
    ca_.Branch(tmp225, &block26, &block27, tmp216, tmp217, tmp218, tmp219, tmp220, tmp221, tmp222, tmp223);
  }

  if (block26.is_used()) {
    TNode<RawPtrT> tmp226;
    TNode<RawPtrT> tmp227;
    TNode<IntPtrT> tmp228;
    TNode<NativeContext> tmp229;
    TNode<Object> tmp230;
    TNode<Number> tmp231;
    TNode<Object> tmp232;
    TNode<Number> tmp233;
    ca_.Bind(&block26, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233);
    TNode<String> tmp234;
    USE(tmp234);
    tmp234 = CodeStubAssembler(state_).InfinityStringConstant();
    arguments.PopAndReturn(tmp234);
  }

  if (block27.is_used()) {
    TNode<RawPtrT> tmp235;
    TNode<RawPtrT> tmp236;
    TNode<IntPtrT> tmp237;
    TNode<NativeContext> tmp238;
    TNode<Object> tmp239;
    TNode<Number> tmp240;
    TNode<Object> tmp241;
    TNode<Number> tmp242;
    ca_.Bind(&block27, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242);
    TNode<Number> tmp243;
    USE(tmp243);
    tmp243 = FromConstexpr_Number_constexpr_float64_0(state_, -V8_INFINITY);
    TNode<BoolT> tmp244;
    USE(tmp244);
    tmp244 = IsNumberEqual_0(state_, TNode<Number>{tmp240}, TNode<Number>{tmp243});
    ca_.Branch(tmp244, &block29, &block30, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242);
  }

  if (block29.is_used()) {
    TNode<RawPtrT> tmp245;
    TNode<RawPtrT> tmp246;
    TNode<IntPtrT> tmp247;
    TNode<NativeContext> tmp248;
    TNode<Object> tmp249;
    TNode<Number> tmp250;
    TNode<Object> tmp251;
    TNode<Number> tmp252;
    ca_.Bind(&block29, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252);
    TNode<String> tmp253;
    USE(tmp253);
    tmp253 = CodeStubAssembler(state_).MinusInfinityStringConstant();
    arguments.PopAndReturn(tmp253);
  }

  if (block30.is_used()) {
    TNode<RawPtrT> tmp254;
    TNode<RawPtrT> tmp255;
    TNode<IntPtrT> tmp256;
    TNode<NativeContext> tmp257;
    TNode<Object> tmp258;
    TNode<Number> tmp259;
    TNode<Object> tmp260;
    TNode<Number> tmp261;
    ca_.Bind(&block30, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261);
    TNode<String> tmp262;
    tmp262 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kDoubleToStringWithRadix, tmp257, tmp259, tmp261)); 
    USE(tmp262);
    arguments.PopAndReturn(tmp262);
  }
}

TNode<Number> UnsafeCast_Number_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
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
    TNode<Number> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<Number>{tmp9};
}

}  // namespace internal
}  // namespace v8

