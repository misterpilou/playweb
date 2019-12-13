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

TNode<Number> ConvertToRelativeIndex_0(compiler::CodeAssemblerState* state_, TNode<Number> p_index, TNode<Number> p_length) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Number, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_index, p_length);

  if (block0.is_used()) {
    TNode<Number> tmp0;
    TNode<Number> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Number> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp3;
    USE(tmp3);
    tmp3 = NumberIsLessThan_0(state_, TNode<Number>{tmp0}, TNode<Number>{tmp2});
    ca_.Branch(tmp3, &block2, &block3, tmp0, tmp1);
  }

  if (block2.is_used()) {
    TNode<Number> tmp4;
    TNode<Number> tmp5;
    ca_.Bind(&block2, &tmp4, &tmp5);
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp4}, TNode<Number>{tmp5});
    TNode<Number> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<Number> tmp8;
    USE(tmp8);
    tmp8 = Max_0(state_, TNode<Number>{tmp6}, TNode<Number>{tmp7});
    ca_.Goto(&block4, tmp4, tmp5, tmp8);
  }

  if (block3.is_used()) {
    TNode<Number> tmp9;
    TNode<Number> tmp10;
    ca_.Bind(&block3, &tmp9, &tmp10);
    TNode<Number> tmp11;
    USE(tmp11);
    tmp11 = Min_0(state_, TNode<Number>{tmp9}, TNode<Number>{tmp10});
    ca_.Goto(&block4, tmp9, tmp10, tmp11);
  }

  if (block4.is_used()) {
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Number> tmp14;
    ca_.Bind(&block4, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block6, tmp12, tmp13, tmp14);
  }

    TNode<Number> tmp15;
    TNode<Number> tmp16;
    TNode<Number> tmp17;
    ca_.Bind(&block6, &tmp15, &tmp16, &tmp17);
  return TNode<Number>{tmp17};
}

TF_BUILTIN(ArrayPrototypeCopyWithin, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, BoolT> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, BoolT> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, BoolT, BoolT> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, Oddball> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, Oddball> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number, Oddball> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Number, Number, Number, Number, Number, Number, Number, Number> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<JSReceiver> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Number> tmp6;
    USE(tmp6);
    tmp6 = GetLengthProperty_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp5});
    TNode<IntPtrT> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp8;
    USE(tmp8);
    tmp8 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp7});
    TNode<Number> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp8});
    TNode<Number> tmp10;
    USE(tmp10);
    tmp10 = ConvertToRelativeIndex_0(state_, TNode<Number>{tmp9}, TNode<Number>{tmp6});
    TNode<IntPtrT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp12;
    USE(tmp12);
    tmp12 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp11});
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp12});
    TNode<Number> tmp14;
    USE(tmp14);
    tmp14 = ConvertToRelativeIndex_0(state_, TNode<Number>{tmp13}, TNode<Number>{tmp6});
    TNode<IntPtrT> tmp15;
    USE(tmp15);
    tmp15 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp16;
    USE(tmp16);
    tmp16 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp15});
    TNode<Oddball> tmp17;
    USE(tmp17);
    tmp17 = Undefined_0(state_);
    TNode<BoolT> tmp18;
    USE(tmp18);
    tmp18 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp16}, TNode<HeapObject>{tmp17});
    ca_.Branch(tmp18, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp9, tmp10, tmp13, tmp14, tmp6);
  }

  if (block1.is_used()) {
    TNode<RawPtrT> tmp19;
    TNode<RawPtrT> tmp20;
    TNode<IntPtrT> tmp21;
    TNode<NativeContext> tmp22;
    TNode<Object> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<Number> tmp25;
    TNode<Number> tmp26;
    TNode<Number> tmp27;
    TNode<Number> tmp28;
    TNode<Number> tmp29;
    TNode<Number> tmp30;
    ca_.Bind(&block1, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<IntPtrT> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_intptr_constexpr_int31_0(state_, 2);
    TNode<Object> tmp32;
    USE(tmp32);
    tmp32 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp19}, TNode<RawPtrT>{tmp20}, TNode<IntPtrT>{tmp21}}, TNode<IntPtrT>{tmp31});
    TNode<Number> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).ToInteger_Inline(TNode<Context>{tmp22}, TNode<Object>{tmp32});
    ca_.Goto(&block2, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27, tmp28, tmp29, tmp33);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp34;
    TNode<RawPtrT> tmp35;
    TNode<IntPtrT> tmp36;
    TNode<NativeContext> tmp37;
    TNode<Object> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<Number> tmp40;
    TNode<Number> tmp41;
    TNode<Number> tmp42;
    TNode<Number> tmp43;
    TNode<Number> tmp44;
    TNode<Number> tmp45;
    ca_.Bind(&block2, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<Number> tmp46;
    USE(tmp46);
    tmp46 = ConvertToRelativeIndex_0(state_, TNode<Number>{tmp45}, TNode<Number>{tmp40});
    TNode<Number> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp46}, TNode<Number>{tmp44});
    TNode<Number> tmp48;
    USE(tmp48);
    tmp48 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp40}, TNode<Number>{tmp42});
    TNode<Number> tmp49;
    USE(tmp49);
    tmp49 = Min_0(state_, TNode<Number>{tmp47}, TNode<Number>{tmp48});
    TNode<Number> tmp50;
    USE(tmp50);
    tmp50 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp51;
    USE(tmp51);
    tmp51 = NumberIsLessThan_0(state_, TNode<Number>{tmp44}, TNode<Number>{tmp42});
    ca_.Branch(tmp51, &block5, &block6, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp49, tmp50, tmp51);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp52;
    TNode<RawPtrT> tmp53;
    TNode<IntPtrT> tmp54;
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<Number> tmp58;
    TNode<Number> tmp59;
    TNode<Number> tmp60;
    TNode<Number> tmp61;
    TNode<Number> tmp62;
    TNode<Number> tmp63;
    TNode<Number> tmp64;
    TNode<Number> tmp65;
    TNode<Number> tmp66;
    TNode<BoolT> tmp67;
    ca_.Bind(&block5, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67);
    TNode<Number> tmp68;
    USE(tmp68);
    tmp68 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp62}, TNode<Number>{tmp65});
    TNode<BoolT> tmp69;
    USE(tmp69);
    tmp69 = NumberIsLessThan_0(state_, TNode<Number>{tmp60}, TNode<Number>{tmp68});
    ca_.Goto(&block7, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp69);
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp70;
    TNode<RawPtrT> tmp71;
    TNode<IntPtrT> tmp72;
    TNode<NativeContext> tmp73;
    TNode<Object> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Number> tmp76;
    TNode<Number> tmp77;
    TNode<Number> tmp78;
    TNode<Number> tmp79;
    TNode<Number> tmp80;
    TNode<Number> tmp81;
    TNode<Number> tmp82;
    TNode<Number> tmp83;
    TNode<Number> tmp84;
    TNode<BoolT> tmp85;
    ca_.Bind(&block6, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<BoolT> tmp86;
    USE(tmp86);
    tmp86 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block7, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85, tmp86);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp87;
    TNode<RawPtrT> tmp88;
    TNode<IntPtrT> tmp89;
    TNode<NativeContext> tmp90;
    TNode<Object> tmp91;
    TNode<JSReceiver> tmp92;
    TNode<Number> tmp93;
    TNode<Number> tmp94;
    TNode<Number> tmp95;
    TNode<Number> tmp96;
    TNode<Number> tmp97;
    TNode<Number> tmp98;
    TNode<Number> tmp99;
    TNode<Number> tmp100;
    TNode<Number> tmp101;
    TNode<BoolT> tmp102;
    TNode<BoolT> tmp103;
    ca_.Bind(&block7, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103);
    ca_.Branch(tmp103, &block3, &block4, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp104;
    TNode<RawPtrT> tmp105;
    TNode<IntPtrT> tmp106;
    TNode<NativeContext> tmp107;
    TNode<Object> tmp108;
    TNode<JSReceiver> tmp109;
    TNode<Number> tmp110;
    TNode<Number> tmp111;
    TNode<Number> tmp112;
    TNode<Number> tmp113;
    TNode<Number> tmp114;
    TNode<Number> tmp115;
    TNode<Number> tmp116;
    TNode<Number> tmp117;
    TNode<Number> tmp118;
    ca_.Bind(&block3, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118);
    TNode<Number> tmp119;
    USE(tmp119);
    tmp119 = FromConstexpr_Number_constexpr_int31_0(state_, -1);
    TNode<Number> tmp120;
    USE(tmp120);
    tmp120 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp114}, TNode<Number>{tmp117});
    TNode<Number> tmp121;
    USE(tmp121);
    tmp121 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp122;
    USE(tmp122);
    tmp122 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp120}, TNode<Number>{tmp121});
    TNode<Number> tmp123;
    USE(tmp123);
    tmp123 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp112}, TNode<Number>{tmp117});
    TNode<Number> tmp124;
    USE(tmp124);
    tmp124 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp125;
    USE(tmp125);
    tmp125 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp123}, TNode<Number>{tmp124});
    ca_.Goto(&block4, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110, tmp111, tmp125, tmp113, tmp122, tmp115, tmp116, tmp117, tmp119);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp126;
    TNode<RawPtrT> tmp127;
    TNode<IntPtrT> tmp128;
    TNode<NativeContext> tmp129;
    TNode<Object> tmp130;
    TNode<JSReceiver> tmp131;
    TNode<Number> tmp132;
    TNode<Number> tmp133;
    TNode<Number> tmp134;
    TNode<Number> tmp135;
    TNode<Number> tmp136;
    TNode<Number> tmp137;
    TNode<Number> tmp138;
    TNode<Number> tmp139;
    TNode<Number> tmp140;
    ca_.Bind(&block4, &tmp126, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140);
    ca_.Goto(&block10, tmp126, tmp127, tmp128, tmp129, tmp130, tmp131, tmp132, tmp133, tmp134, tmp135, tmp136, tmp137, tmp138, tmp139, tmp140);
  }

  if (block10.is_used()) {
    TNode<RawPtrT> tmp141;
    TNode<RawPtrT> tmp142;
    TNode<IntPtrT> tmp143;
    TNode<NativeContext> tmp144;
    TNode<Object> tmp145;
    TNode<JSReceiver> tmp146;
    TNode<Number> tmp147;
    TNode<Number> tmp148;
    TNode<Number> tmp149;
    TNode<Number> tmp150;
    TNode<Number> tmp151;
    TNode<Number> tmp152;
    TNode<Number> tmp153;
    TNode<Number> tmp154;
    TNode<Number> tmp155;
    ca_.Bind(&block10, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155);
    TNode<Number> tmp156;
    USE(tmp156);
    tmp156 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp157;
    USE(tmp157);
    tmp157 = NumberIsGreaterThan_0(state_, TNode<Number>{tmp154}, TNode<Number>{tmp156});
    ca_.Branch(tmp157, &block8, &block9, tmp141, tmp142, tmp143, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp153, tmp154, tmp155);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp158;
    TNode<RawPtrT> tmp159;
    TNode<IntPtrT> tmp160;
    TNode<NativeContext> tmp161;
    TNode<Object> tmp162;
    TNode<JSReceiver> tmp163;
    TNode<Number> tmp164;
    TNode<Number> tmp165;
    TNode<Number> tmp166;
    TNode<Number> tmp167;
    TNode<Number> tmp168;
    TNode<Number> tmp169;
    TNode<Number> tmp170;
    TNode<Number> tmp171;
    TNode<Number> tmp172;
    ca_.Bind(&block8, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172);
    TNode<Oddball> tmp173;
    tmp173 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kHasProperty, tmp161, tmp163, tmp168));
    USE(tmp173);
    TNode<Oddball> tmp174;
    USE(tmp174);
    tmp174 = True_0(state_);
    TNode<BoolT> tmp175;
    USE(tmp175);
    tmp175 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp173}, TNode<HeapObject>{tmp174});
    ca_.Branch(tmp175, &block11, &block12, tmp158, tmp159, tmp160, tmp161, tmp162, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173);
  }

  if (block11.is_used()) {
    TNode<RawPtrT> tmp176;
    TNode<RawPtrT> tmp177;
    TNode<IntPtrT> tmp178;
    TNode<NativeContext> tmp179;
    TNode<Object> tmp180;
    TNode<JSReceiver> tmp181;
    TNode<Number> tmp182;
    TNode<Number> tmp183;
    TNode<Number> tmp184;
    TNode<Number> tmp185;
    TNode<Number> tmp186;
    TNode<Number> tmp187;
    TNode<Number> tmp188;
    TNode<Number> tmp189;
    TNode<Number> tmp190;
    TNode<Oddball> tmp191;
    ca_.Bind(&block11, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191);
    TNode<Object> tmp192;
    USE(tmp192);
    tmp192 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp179}, TNode<Object>{tmp181}, TNode<Object>{tmp186});
    CodeStubAssembler(state_).CallBuiltin(Builtins::kSetProperty, tmp179, tmp181, tmp184, tmp192);
    ca_.Goto(&block13, tmp176, tmp177, tmp178, tmp179, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191);
  }

  if (block12.is_used()) {
    TNode<RawPtrT> tmp194;
    TNode<RawPtrT> tmp195;
    TNode<IntPtrT> tmp196;
    TNode<NativeContext> tmp197;
    TNode<Object> tmp198;
    TNode<JSReceiver> tmp199;
    TNode<Number> tmp200;
    TNode<Number> tmp201;
    TNode<Number> tmp202;
    TNode<Number> tmp203;
    TNode<Number> tmp204;
    TNode<Number> tmp205;
    TNode<Number> tmp206;
    TNode<Number> tmp207;
    TNode<Number> tmp208;
    TNode<Oddball> tmp209;
    ca_.Bind(&block12, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209);
    TNode<Smi> tmp210;
    USE(tmp210);
    tmp210 = FromConstexpr_LanguageMode_constexpr_LanguageMode_0(state_, LanguageMode::kStrict);
    TNode<Oddball> tmp211;
    tmp211 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kDeleteProperty, tmp197, tmp199, tmp202, tmp210));
    USE(tmp211);
    ca_.Goto(&block13, tmp194, tmp195, tmp196, tmp197, tmp198, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp212;
    TNode<RawPtrT> tmp213;
    TNode<IntPtrT> tmp214;
    TNode<NativeContext> tmp215;
    TNode<Object> tmp216;
    TNode<JSReceiver> tmp217;
    TNode<Number> tmp218;
    TNode<Number> tmp219;
    TNode<Number> tmp220;
    TNode<Number> tmp221;
    TNode<Number> tmp222;
    TNode<Number> tmp223;
    TNode<Number> tmp224;
    TNode<Number> tmp225;
    TNode<Number> tmp226;
    TNode<Oddball> tmp227;
    ca_.Bind(&block13, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227);
    TNode<Number> tmp228;
    USE(tmp228);
    tmp228 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp222}, TNode<Number>{tmp226});
    TNode<Number> tmp229;
    USE(tmp229);
    tmp229 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp220}, TNode<Number>{tmp226});
    TNode<Number> tmp230;
    USE(tmp230);
    tmp230 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp231;
    USE(tmp231);
    tmp231 = CodeStubAssembler(state_).NumberSub(TNode<Number>{tmp225}, TNode<Number>{tmp230});
    ca_.Goto(&block10, tmp212, tmp213, tmp214, tmp215, tmp216, tmp217, tmp218, tmp219, tmp229, tmp221, tmp228, tmp223, tmp224, tmp231, tmp226);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp232;
    TNode<RawPtrT> tmp233;
    TNode<IntPtrT> tmp234;
    TNode<NativeContext> tmp235;
    TNode<Object> tmp236;
    TNode<JSReceiver> tmp237;
    TNode<Number> tmp238;
    TNode<Number> tmp239;
    TNode<Number> tmp240;
    TNode<Number> tmp241;
    TNode<Number> tmp242;
    TNode<Number> tmp243;
    TNode<Number> tmp244;
    TNode<Number> tmp245;
    TNode<Number> tmp246;
    ca_.Bind(&block9, &tmp232, &tmp233, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246);
    arguments.PopAndReturn(tmp237);
  }
}

}  // namespace internal
}  // namespace v8

