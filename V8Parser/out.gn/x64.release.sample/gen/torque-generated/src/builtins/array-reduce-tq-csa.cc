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

TF_BUILTIN(ArrayReducePreLoopEagerDeoptContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(parameter3);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSReceiver, Object, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSReceiver, Object, NativeContext, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSReceiver, JSReceiver, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, JSReceiver, JSReceiver, Object, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp4 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0, tmp4);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp5;
    TNode<Object> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<NativeContext> tmp10;
    ca_.Bind(&block4, &tmp5, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<NativeContext> tmp16;
    TNode<JSReceiver> tmp17;
    ca_.Bind(&block3, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<JSReceiver> tmp18;
    USE(tmp18);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp18 = Cast_Callable_1(state_, TNode<Context>{tmp11}, TNode<Object>{tmp13}, &label0);
    ca_.Goto(&block7, tmp11, tmp12, tmp13, tmp14, tmp17, tmp13, tmp11, tmp18);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp11, tmp12, tmp13, tmp14, tmp17, tmp13, tmp11);
    }
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<Object> tmp22;
    TNode<JSReceiver> tmp23;
    TNode<Object> tmp24;
    TNode<NativeContext> tmp25;
    ca_.Bind(&block8, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<Object> tmp31;
    TNode<NativeContext> tmp32;
    TNode<JSReceiver> tmp33;
    ca_.Bind(&block7, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    TNode<Number> tmp34;
    USE(tmp34);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp34 = Cast_Number_0(state_, TNode<Object>{tmp29}, &label0);
    ca_.Goto(&block11, tmp26, tmp27, tmp28, tmp29, tmp30, tmp33, tmp29, tmp34);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp26, tmp27, tmp28, tmp29, tmp30, tmp33, tmp29);
    }
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<JSReceiver> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<Object> tmp41;
    ca_.Bind(&block12, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp42;
    TNode<Object> tmp43;
    TNode<Object> tmp44;
    TNode<Object> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<Object> tmp48;
    TNode<Number> tmp49;
    ca_.Bind(&block11, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49);
    TNode<Oddball> tmp50;
    USE(tmp50);
    tmp50 = TheHole_0(state_);
    TNode<Number> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    TNode<Object> tmp52;
    tmp52 = CodeStubAssembler(state_).CallBuiltin(Builtins::kArrayReduceLoopContinuation, tmp42, tmp46, tmp47, tmp50, tmp46, tmp51, tmp49);
    USE(tmp52);
    CodeStubAssembler(state_).Return(tmp52);
  }
}

TF_BUILTIN(ArrayReduceLoopEagerDeoptContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::kAccumulator));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, Object, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, Object, NativeContext, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Object, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Number, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Number, Object, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<NativeContext> tmp14;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<NativeContext> tmp22;
    TNode<JSReceiver> tmp23;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<JSReceiver> tmp24;
    USE(tmp24);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp24 = Cast_Callable_1(state_, TNode<Context>{tmp15}, TNode<Object>{tmp17}, &label0);
    ca_.Goto(&block7, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp23, tmp17, tmp15, tmp24);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp23, tmp17, tmp15);
    }
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Object> tmp32;
    TNode<NativeContext> tmp33;
    ca_.Bind(&block8, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<Object> tmp41;
    TNode<NativeContext> tmp42;
    TNode<JSReceiver> tmp43;
    ca_.Bind(&block7, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<Number> tmp44;
    USE(tmp44);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp44 = Cast_Number_0(state_, TNode<Object>{tmp37}, &label0);
    ca_.Goto(&block11, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp43, tmp37, tmp44);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp43, tmp37);
    }
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<JSReceiver> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    ca_.Bind(&block12, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp62;
    TNode<Number> tmp63;
    ca_.Bind(&block11, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    TNode<Number> tmp64;
    USE(tmp64);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp64 = Cast_Number_0(state_, TNode<Object>{tmp58}, &label0);
    ca_.Goto(&block15, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp63, tmp58, tmp64);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp63, tmp58);
    }
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<JSReceiver> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<Number> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block16, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<JSReceiver> tmp82;
    TNode<Number> tmp83;
    TNode<Object> tmp84;
    TNode<Number> tmp85;
    ca_.Bind(&block15, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<Object> tmp86;
    tmp86 = CodeStubAssembler(state_).CallBuiltin(Builtins::kArrayReduceLoopContinuation, tmp75, tmp81, tmp82, tmp80, tmp81, tmp83, tmp85);
    USE(tmp86);
    CodeStubAssembler(state_).Return(tmp86);
  }
}

TF_BUILTIN(ArrayReduceLoopLazyDeoptContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kCallback));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::kInitialK));
  USE(parameter3);
  TNode<Object> parameter4 = UncheckedCast<Object>(Parameter(Descriptor::kLength));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::kResult));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, Object, NativeContext, JSReceiver> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, Object, NativeContext> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, Object, NativeContext, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Object, Number> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Number, Object> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, Object, Object, Object, JSReceiver, JSReceiver, Number, Object, Number> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_JSReceiver_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp7;
    TNode<Object> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Object> tmp12;
    TNode<Object> tmp13;
    TNode<NativeContext> tmp14;
    ca_.Bind(&block4, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp15;
    TNode<Object> tmp16;
    TNode<Object> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Object> tmp20;
    TNode<Object> tmp21;
    TNode<NativeContext> tmp22;
    TNode<JSReceiver> tmp23;
    ca_.Bind(&block3, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<JSReceiver> tmp24;
    USE(tmp24);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp24 = Cast_Callable_1(state_, TNode<Context>{tmp15}, TNode<Object>{tmp17}, &label0);
    ca_.Goto(&block7, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp23, tmp17, tmp15, tmp24);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block8, tmp15, tmp16, tmp17, tmp18, tmp19, tmp20, tmp23, tmp17, tmp15);
    }
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<Object> tmp29;
    TNode<Object> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Object> tmp32;
    TNode<NativeContext> tmp33;
    ca_.Bind(&block8, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp34;
    TNode<Object> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<Object> tmp38;
    TNode<Object> tmp39;
    TNode<JSReceiver> tmp40;
    TNode<Object> tmp41;
    TNode<NativeContext> tmp42;
    TNode<JSReceiver> tmp43;
    ca_.Bind(&block7, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<Number> tmp44;
    USE(tmp44);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp44 = Cast_Number_0(state_, TNode<Object>{tmp37}, &label0);
    ca_.Goto(&block11, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp43, tmp37, tmp44);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block12, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp40, tmp43, tmp37);
    }
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp45;
    TNode<Object> tmp46;
    TNode<Object> tmp47;
    TNode<Object> tmp48;
    TNode<Object> tmp49;
    TNode<Object> tmp50;
    TNode<JSReceiver> tmp51;
    TNode<JSReceiver> tmp52;
    TNode<Object> tmp53;
    ca_.Bind(&block12, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp54;
    TNode<Object> tmp55;
    TNode<Object> tmp56;
    TNode<Object> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<JSReceiver> tmp61;
    TNode<Object> tmp62;
    TNode<Number> tmp63;
    ca_.Bind(&block11, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63);
    TNode<Number> tmp64;
    USE(tmp64);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp64 = Cast_Number_0(state_, TNode<Object>{tmp58}, &label0);
    ca_.Goto(&block15, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp63, tmp58, tmp64);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block16, tmp54, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp63, tmp58);
    }
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<JSReceiver> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<Number> tmp73;
    TNode<Object> tmp74;
    ca_.Bind(&block16, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp75;
    TNode<Object> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    TNode<Object> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<JSReceiver> tmp82;
    TNode<Number> tmp83;
    TNode<Object> tmp84;
    TNode<Number> tmp85;
    ca_.Bind(&block15, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    TNode<Object> tmp86;
    tmp86 = CodeStubAssembler(state_).CallBuiltin(Builtins::kArrayReduceLoopContinuation, tmp75, tmp81, tmp82, tmp80, tmp81, tmp83, tmp85);
    USE(tmp86);
    CodeStubAssembler(state_).Return(tmp86);
  }
}

TF_BUILTIN(ArrayReduceLoopContinuation, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSReceiver> parameter1 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<JSReceiver> parameter2 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<Object> parameter3 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<JSReceiver> parameter4 = UncheckedCast<JSReceiver>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  TNode<Number> parameter5 = UncheckedCast<Number>(Parameter(Descriptor::ParameterIndex<4>()));
  USE(parameter5);
  TNode<Number> parameter6 = UncheckedCast<Number>(Parameter(Descriptor::ParameterIndex<5>()));
  USE(parameter6);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number, Oddball> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number, Oddball, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number, Oddball, Object, Object, Object, Oddball> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number, Oddball, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number, Oddball> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Number> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Object, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, JSReceiver, Object, JSReceiver, Number, Number, Object, Object, Object, Oddball> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5, parameter6);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<JSReceiver> tmp2;
    TNode<Object> tmp3;
    TNode<JSReceiver> tmp4;
    TNode<Number> tmp5;
    TNode<Number> tmp6;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5, &tmp6);
    ca_.Goto(&block3, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp3, tmp5);
  }

  if (block3.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<Object> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<Number> tmp12;
    TNode<Number> tmp13;
    TNode<Object> tmp14;
    TNode<Number> tmp15;
    ca_.Bind(&block3, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15);
    TNode<BoolT> tmp16;
    USE(tmp16);
    tmp16 = NumberIsLessThan_0(state_, TNode<Number>{tmp15}, TNode<Number>{tmp13});
    ca_.Branch(tmp16, &block1, &block2, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp13, tmp14, tmp15);
  }

  if (block1.is_used()) {
    TNode<Context> tmp17;
    TNode<JSReceiver> tmp18;
    TNode<JSReceiver> tmp19;
    TNode<Object> tmp20;
    TNode<JSReceiver> tmp21;
    TNode<Number> tmp22;
    TNode<Number> tmp23;
    TNode<Object> tmp24;
    TNode<Number> tmp25;
    ca_.Bind(&block1, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25);
    TNode<Oddball> tmp26;
    USE(tmp26);
    tmp26 = CodeStubAssembler(state_).HasProperty_Inline(TNode<Context>{tmp17}, TNode<JSReceiver>{tmp21}, TNode<Object>{tmp25});
    TNode<Oddball> tmp27;
    USE(tmp27);
    tmp27 = True_0(state_);
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = CodeStubAssembler(state_).TaggedEqual(TNode<HeapObject>{tmp26}, TNode<HeapObject>{tmp27});
    ca_.Branch(tmp28, &block5, &block6, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26);
  }

  if (block5.is_used()) {
    TNode<Context> tmp29;
    TNode<JSReceiver> tmp30;
    TNode<JSReceiver> tmp31;
    TNode<Object> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Number> tmp34;
    TNode<Number> tmp35;
    TNode<Object> tmp36;
    TNode<Number> tmp37;
    TNode<Oddball> tmp38;
    ca_.Bind(&block5, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38);
    TNode<Object> tmp39;
    USE(tmp39);
    tmp39 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp29}, TNode<Object>{tmp33}, TNode<Object>{tmp37});
    TNode<Oddball> tmp40;
    USE(tmp40);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp40 = Cast_TheHole_0(state_, TNode<Object>{tmp36}, &label0);
    ca_.Goto(&block9, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp36, tmp36, tmp40);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp36, tmp36);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp41;
    TNode<JSReceiver> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<Object> tmp44;
    TNode<JSReceiver> tmp45;
    TNode<Number> tmp46;
    TNode<Number> tmp47;
    TNode<Object> tmp48;
    TNode<Number> tmp49;
    TNode<Oddball> tmp50;
    TNode<Object> tmp51;
    TNode<Object> tmp52;
    TNode<Object> tmp53;
    ca_.Bind(&block10, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53);
    TNode<Oddball> tmp54;
    USE(tmp54);
    tmp54 = Undefined_0(state_);
    TNode<Object> tmp55;
    USE(tmp55);
    tmp55 = CodeStubAssembler(state_).Call(TNode<Context>{tmp41}, TNode<JSReceiver>{tmp43}, TNode<Object>{tmp54}, TNode<Object>{ca_.UncheckedCast<Object>(tmp52)}, TNode<Object>{tmp51}, TNode<Object>{tmp49}, TNode<Object>{tmp45});
    ca_.Goto(&block7, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp55, tmp49, tmp50, tmp51, tmp52);
  }

  if (block9.is_used()) {
    TNode<Context> tmp56;
    TNode<JSReceiver> tmp57;
    TNode<JSReceiver> tmp58;
    TNode<Object> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Number> tmp61;
    TNode<Number> tmp62;
    TNode<Object> tmp63;
    TNode<Number> tmp64;
    TNode<Oddball> tmp65;
    TNode<Object> tmp66;
    TNode<Object> tmp67;
    TNode<Object> tmp68;
    TNode<Oddball> tmp69;
    ca_.Bind(&block9, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    ca_.Goto(&block7, tmp56, tmp57, tmp58, tmp59, tmp60, tmp61, tmp62, tmp66, tmp64, tmp65, tmp66, tmp67);
  }

  if (block7.is_used()) {
    TNode<Context> tmp70;
    TNode<JSReceiver> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<Object> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Number> tmp75;
    TNode<Number> tmp76;
    TNode<Object> tmp77;
    TNode<Number> tmp78;
    TNode<Oddball> tmp79;
    TNode<Object> tmp80;
    TNode<Object> tmp81;
    ca_.Bind(&block7, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81);
    ca_.Goto(&block6, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79);
  }

  if (block6.is_used()) {
    TNode<Context> tmp82;
    TNode<JSReceiver> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Object> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<Number> tmp87;
    TNode<Number> tmp88;
    TNode<Object> tmp89;
    TNode<Number> tmp90;
    TNode<Oddball> tmp91;
    ca_.Bind(&block6, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91);
    TNode<Number> tmp92;
    USE(tmp92);
    tmp92 = FromConstexpr_Number_constexpr_int31_0(state_, 1);
    TNode<Number> tmp93;
    USE(tmp93);
    tmp93 = CodeStubAssembler(state_).NumberAdd(TNode<Number>{tmp90}, TNode<Number>{tmp92});
    ca_.Goto(&block3, tmp82, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp93);
  }

  if (block2.is_used()) {
    TNode<Context> tmp94;
    TNode<JSReceiver> tmp95;
    TNode<JSReceiver> tmp96;
    TNode<Object> tmp97;
    TNode<JSReceiver> tmp98;
    TNode<Number> tmp99;
    TNode<Number> tmp100;
    TNode<Object> tmp101;
    TNode<Number> tmp102;
    ca_.Bind(&block2, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102);
    TNode<Oddball> tmp103;
    USE(tmp103);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp103 = Cast_TheHole_0(state_, TNode<Object>{tmp101}, &label0);
    ca_.Goto(&block13, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp101, tmp101, tmp103);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp94, tmp95, tmp96, tmp97, tmp98, tmp99, tmp100, tmp101, tmp101, tmp101);
    }
  }

  if (block14.is_used()) {
    TNode<Context> tmp104;
    TNode<JSReceiver> tmp105;
    TNode<JSReceiver> tmp106;
    TNode<Object> tmp107;
    TNode<JSReceiver> tmp108;
    TNode<Number> tmp109;
    TNode<Number> tmp110;
    TNode<Object> tmp111;
    TNode<Object> tmp112;
    TNode<Object> tmp113;
    ca_.Bind(&block14, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    CodeStubAssembler(state_).Return(ca_.UncheckedCast<Object>(tmp112));
  }

  if (block13.is_used()) {
    TNode<Context> tmp114;
    TNode<JSReceiver> tmp115;
    TNode<JSReceiver> tmp116;
    TNode<Object> tmp117;
    TNode<JSReceiver> tmp118;
    TNode<Number> tmp119;
    TNode<Number> tmp120;
    TNode<Object> tmp121;
    TNode<Object> tmp122;
    TNode<Object> tmp123;
    TNode<Oddball> tmp124;
    ca_.Bind(&block13, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp114}, MessageTemplate::kReduceNoInitial, "Array.prototype.reduce");
  }
}

TNode<Object> FastArrayReduce_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o, TNode<Number> p_len, TNode<JSReceiver> p_callbackfn, TNode<Object> p_initialAccumulator, compiler::CodeAssemblerLabel* label_Bailout, compiler::TypedCodeAssemblerVariable<Number>* label_Bailout_parameter_0, compiler::TypedCodeAssemblerVariable<Object>* label_Bailout_parameter_1) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, Number> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, Number, Smi> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSReceiver, Context> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSReceiver, Context, JSArray> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block20(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block21(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block23(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi> block28(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi, JSArray, Smi, Context> block32(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi, JSArray, Smi, Context, Object> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi> block29(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi, JSArray, Smi, Context> block34(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi, JSArray, Smi, Context, Object> block33(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Smi, Context, Context, Smi, Object> block27(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block26(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Object, Object, Object> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Object, Object, Object, Oddball> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi, Object, Object> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Smi> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Object, Object> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object, JSArray, JSArray, JSArray, Map, BoolT, Object, Object, Oddball> block42(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Number, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, Number, JSReceiver, Object, Object> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o, p_len, p_callbackfn, p_initialAccumulator);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<Number> tmp2;
    TNode<JSReceiver> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Smi> tmp5;
    USE(tmp5);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp5 = Cast_Smi_0(state_, TNode<Object>{tmp2}, &label0);
    ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp2, tmp5);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp2, tmp3, tmp4, tmp4, tmp2);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp6;
    TNode<JSReceiver> tmp7;
    TNode<Number> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<Object> tmp10;
    TNode<Object> tmp11;
    TNode<Number> tmp12;
    ca_.Bind(&block6, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<Number> tmp13;
    USE(tmp13);
    tmp13 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    ca_.Goto(&block1, tmp13, tmp11);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Number> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<Object> tmp18;
    TNode<Object> tmp19;
    TNode<Number> tmp20;
    TNode<Smi> tmp21;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21);
    TNode<JSArray> tmp22;
    USE(tmp22);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp22 = Cast_FastJSArrayForRead_0(state_, TNode<Context>{tmp14}, TNode<HeapObject>{tmp15}, &label0);
    ca_.Goto(&block9, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp15, tmp14, tmp22);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block10, tmp14, tmp15, tmp16, tmp17, tmp18, tmp19, tmp15, tmp14);
    }
  }

  if (block10.is_used()) {
    TNode<Context> tmp23;
    TNode<JSReceiver> tmp24;
    TNode<Number> tmp25;
    TNode<JSReceiver> tmp26;
    TNode<Object> tmp27;
    TNode<Object> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<Context> tmp30;
    ca_.Bind(&block10, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28, &tmp29, &tmp30);
    TNode<Number> tmp31;
    USE(tmp31);
    tmp31 = FromConstexpr_Number_constexpr_int31_0(state_, 0);
    ca_.Goto(&block1, tmp31, tmp28);
  }

  if (block9.is_used()) {
    TNode<Context> tmp32;
    TNode<JSReceiver> tmp33;
    TNode<Number> tmp34;
    TNode<JSReceiver> tmp35;
    TNode<Object> tmp36;
    TNode<Object> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<Context> tmp39;
    TNode<JSArray> tmp40;
    ca_.Bind(&block9, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40);
    TNode<JSArray> tmp41;
    USE(tmp41);
    TNode<JSArray> tmp42;
    USE(tmp42);
    TNode<Map> tmp43;
    USE(tmp43);
    TNode<BoolT> tmp44;
    USE(tmp44);
    std::tie(tmp41, tmp42, tmp43, tmp44) = NewFastJSArrayForReadWitness_0(state_, TNode<JSArray>{tmp40}).Flatten();
    TNode<Smi> tmp45;
    USE(tmp45);
    tmp45 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    ca_.Goto(&block13, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp40, tmp41, tmp42, tmp43, tmp44, tmp45);
  }

  if (block13.is_used()) {
    TNode<Context> tmp46;
    TNode<JSReceiver> tmp47;
    TNode<Number> tmp48;
    TNode<JSReceiver> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    TNode<JSArray> tmp52;
    TNode<JSArray> tmp53;
    TNode<JSArray> tmp54;
    TNode<Map> tmp55;
    TNode<BoolT> tmp56;
    TNode<Smi> tmp57;
    ca_.Bind(&block13, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57);
    TNode<BoolT> tmp58;
    USE(tmp58);
    tmp58 = NumberIsLessThan_0(state_, TNode<Number>{tmp57}, TNode<Number>{tmp48});
    ca_.Branch(tmp58, &block11, &block12, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp56, tmp57);
  }

  if (block11.is_used()) {
    TNode<Context> tmp59;
    TNode<JSReceiver> tmp60;
    TNode<Number> tmp61;
    TNode<JSReceiver> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<JSArray> tmp65;
    TNode<JSArray> tmp66;
    TNode<JSArray> tmp67;
    TNode<Map> tmp68;
    TNode<BoolT> tmp69;
    TNode<Smi> tmp70;
    ca_.Bind(&block11, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70);
    TNode<IntPtrT> tmp71 = ca_.IntPtrConstant(HeapObject::kMapOffset);
    USE(tmp71);
    TNode<Map>tmp72 = CodeStubAssembler(state_).LoadReference<Map>(CodeStubAssembler::Reference{tmp66, tmp71});
    TNode<BoolT> tmp73;
    USE(tmp73);
    tmp73 = CodeStubAssembler(state_).TaggedNotEqual(TNode<HeapObject>{tmp72}, TNode<HeapObject>{tmp68});
    ca_.Branch(tmp73, &block18, &block19, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66, tmp67, tmp68, tmp69, tmp70);
  }

  if (block18.is_used()) {
    TNode<Context> tmp74;
    TNode<JSReceiver> tmp75;
    TNode<Number> tmp76;
    TNode<JSReceiver> tmp77;
    TNode<Object> tmp78;
    TNode<Object> tmp79;
    TNode<JSArray> tmp80;
    TNode<JSArray> tmp81;
    TNode<JSArray> tmp82;
    TNode<Map> tmp83;
    TNode<BoolT> tmp84;
    TNode<Smi> tmp85;
    ca_.Bind(&block18, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85);
    ca_.Goto(&block16, tmp74, tmp75, tmp76, tmp77, tmp78, tmp79, tmp80, tmp81, tmp82, tmp83, tmp84, tmp85);
  }

  if (block19.is_used()) {
    TNode<Context> tmp86;
    TNode<JSReceiver> tmp87;
    TNode<Number> tmp88;
    TNode<JSReceiver> tmp89;
    TNode<Object> tmp90;
    TNode<Object> tmp91;
    TNode<JSArray> tmp92;
    TNode<JSArray> tmp93;
    TNode<JSArray> tmp94;
    TNode<Map> tmp95;
    TNode<BoolT> tmp96;
    TNode<Smi> tmp97;
    ca_.Bind(&block19, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97);
    TNode<BoolT> tmp98;
    USE(tmp98);
    tmp98 = CodeStubAssembler(state_).IsNoElementsProtectorCellInvalid();
    ca_.Branch(tmp98, &block20, &block21, tmp86, tmp87, tmp88, tmp89, tmp90, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97);
  }

  if (block20.is_used()) {
    TNode<Context> tmp99;
    TNode<JSReceiver> tmp100;
    TNode<Number> tmp101;
    TNode<JSReceiver> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    TNode<JSArray> tmp105;
    TNode<JSArray> tmp106;
    TNode<JSArray> tmp107;
    TNode<Map> tmp108;
    TNode<BoolT> tmp109;
    TNode<Smi> tmp110;
    ca_.Bind(&block20, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108, &tmp109, &tmp110);
    ca_.Goto(&block16, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106, tmp107, tmp108, tmp109, tmp110);
  }

  if (block21.is_used()) {
    TNode<Context> tmp111;
    TNode<JSReceiver> tmp112;
    TNode<Number> tmp113;
    TNode<JSReceiver> tmp114;
    TNode<Object> tmp115;
    TNode<Object> tmp116;
    TNode<JSArray> tmp117;
    TNode<JSArray> tmp118;
    TNode<JSArray> tmp119;
    TNode<Map> tmp120;
    TNode<BoolT> tmp121;
    TNode<Smi> tmp122;
    ca_.Bind(&block21, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116, &tmp117, &tmp118, &tmp119, &tmp120, &tmp121, &tmp122);
    TNode<JSArray> tmp123;
    USE(tmp123);
    tmp123 = (TNode<JSArray>{tmp118});
    TNode<IntPtrT> tmp124 = ca_.IntPtrConstant(JSArray::kLengthOffset);
    USE(tmp124);
    TNode<Number>tmp125 = CodeStubAssembler(state_).LoadReference<Number>(CodeStubAssembler::Reference{tmp123, tmp124});
    TNode<BoolT> tmp126;
    USE(tmp126);
    tmp126 = NumberIsGreaterThanOrEqual_0(state_, TNode<Number>{tmp122}, TNode<Number>{tmp125});
    ca_.Branch(tmp126, &block22, &block23, tmp111, tmp112, tmp113, tmp114, tmp115, tmp116, tmp117, tmp118, tmp123, tmp120, tmp121, tmp122);
  }

  if (block16.is_used()) {
    TNode<Context> tmp127;
    TNode<JSReceiver> tmp128;
    TNode<Number> tmp129;
    TNode<JSReceiver> tmp130;
    TNode<Object> tmp131;
    TNode<Object> tmp132;
    TNode<JSArray> tmp133;
    TNode<JSArray> tmp134;
    TNode<JSArray> tmp135;
    TNode<Map> tmp136;
    TNode<BoolT> tmp137;
    TNode<Smi> tmp138;
    ca_.Bind(&block16, &tmp127, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135, &tmp136, &tmp137, &tmp138);
    ca_.Goto(&block1, tmp138, tmp132);
  }

  if (block22.is_used()) {
    TNode<Context> tmp139;
    TNode<JSReceiver> tmp140;
    TNode<Number> tmp141;
    TNode<JSReceiver> tmp142;
    TNode<Object> tmp143;
    TNode<Object> tmp144;
    TNode<JSArray> tmp145;
    TNode<JSArray> tmp146;
    TNode<JSArray> tmp147;
    TNode<Map> tmp148;
    TNode<BoolT> tmp149;
    TNode<Smi> tmp150;
    ca_.Bind(&block22, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150);
    ca_.Goto(&block1, tmp150, tmp144);
  }

  if (block23.is_used()) {
    TNode<Context> tmp151;
    TNode<JSReceiver> tmp152;
    TNode<Number> tmp153;
    TNode<JSReceiver> tmp154;
    TNode<Object> tmp155;
    TNode<Object> tmp156;
    TNode<JSArray> tmp157;
    TNode<JSArray> tmp158;
    TNode<JSArray> tmp159;
    TNode<Map> tmp160;
    TNode<BoolT> tmp161;
    TNode<Smi> tmp162;
    ca_.Bind(&block23, &tmp151, &tmp152, &tmp153, &tmp154, &tmp155, &tmp156, &tmp157, &tmp158, &tmp159, &tmp160, &tmp161, &tmp162);
    ca_.Branch(tmp161, &block28, &block29, tmp151, tmp152, tmp153, tmp154, tmp155, tmp156, tmp157, tmp158, tmp159, tmp160, tmp161, tmp162, tmp162, tmp151, tmp151, tmp162);
  }

  if (block28.is_used()) {
    TNode<Context> tmp163;
    TNode<JSReceiver> tmp164;
    TNode<Number> tmp165;
    TNode<JSReceiver> tmp166;
    TNode<Object> tmp167;
    TNode<Object> tmp168;
    TNode<JSArray> tmp169;
    TNode<JSArray> tmp170;
    TNode<JSArray> tmp171;
    TNode<Map> tmp172;
    TNode<BoolT> tmp173;
    TNode<Smi> tmp174;
    TNode<Smi> tmp175;
    TNode<Context> tmp176;
    TNode<Context> tmp177;
    TNode<Smi> tmp178;
    ca_.Bind(&block28, &tmp163, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178);
    TNode<Object> tmp179;
    USE(tmp179);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp179 = LoadElementNoHole_FixedDoubleArray_0(state_, TNode<Context>{tmp177}, TNode<JSArray>{tmp171}, TNode<Smi>{tmp178}, &label0);
    ca_.Goto(&block31, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp171, tmp178, tmp177, tmp179);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block32, tmp163, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp174, tmp175, tmp176, tmp177, tmp178, tmp171, tmp178, tmp177);
    }
  }

  if (block32.is_used()) {
    TNode<Context> tmp180;
    TNode<JSReceiver> tmp181;
    TNode<Number> tmp182;
    TNode<JSReceiver> tmp183;
    TNode<Object> tmp184;
    TNode<Object> tmp185;
    TNode<JSArray> tmp186;
    TNode<JSArray> tmp187;
    TNode<JSArray> tmp188;
    TNode<Map> tmp189;
    TNode<BoolT> tmp190;
    TNode<Smi> tmp191;
    TNode<Smi> tmp192;
    TNode<Context> tmp193;
    TNode<Context> tmp194;
    TNode<Smi> tmp195;
    TNode<JSArray> tmp196;
    TNode<Smi> tmp197;
    TNode<Context> tmp198;
    ca_.Bind(&block32, &tmp180, &tmp181, &tmp182, &tmp183, &tmp184, &tmp185, &tmp186, &tmp187, &tmp188, &tmp189, &tmp190, &tmp191, &tmp192, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198);
    ca_.Goto(&block26, tmp180, tmp181, tmp182, tmp183, tmp184, tmp185, tmp186, tmp187, tmp188, tmp189, tmp190, tmp191);
  }

  if (block31.is_used()) {
    TNode<Context> tmp199;
    TNode<JSReceiver> tmp200;
    TNode<Number> tmp201;
    TNode<JSReceiver> tmp202;
    TNode<Object> tmp203;
    TNode<Object> tmp204;
    TNode<JSArray> tmp205;
    TNode<JSArray> tmp206;
    TNode<JSArray> tmp207;
    TNode<Map> tmp208;
    TNode<BoolT> tmp209;
    TNode<Smi> tmp210;
    TNode<Smi> tmp211;
    TNode<Context> tmp212;
    TNode<Context> tmp213;
    TNode<Smi> tmp214;
    TNode<JSArray> tmp215;
    TNode<Smi> tmp216;
    TNode<Context> tmp217;
    TNode<Object> tmp218;
    ca_.Bind(&block31, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218);
    ca_.Goto(&block27, tmp199, tmp200, tmp201, tmp202, tmp203, tmp204, tmp205, tmp206, tmp207, tmp208, tmp209, tmp210, tmp211, tmp212, tmp213, tmp214, tmp218);
  }

  if (block29.is_used()) {
    TNode<Context> tmp219;
    TNode<JSReceiver> tmp220;
    TNode<Number> tmp221;
    TNode<JSReceiver> tmp222;
    TNode<Object> tmp223;
    TNode<Object> tmp224;
    TNode<JSArray> tmp225;
    TNode<JSArray> tmp226;
    TNode<JSArray> tmp227;
    TNode<Map> tmp228;
    TNode<BoolT> tmp229;
    TNode<Smi> tmp230;
    TNode<Smi> tmp231;
    TNode<Context> tmp232;
    TNode<Context> tmp233;
    TNode<Smi> tmp234;
    ca_.Bind(&block29, &tmp219, &tmp220, &tmp221, &tmp222, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233, &tmp234);
    TNode<Object> tmp235;
    USE(tmp235);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp235 = LoadElementNoHole_FixedArray_0(state_, TNode<Context>{tmp233}, TNode<JSArray>{tmp227}, TNode<Smi>{tmp234}, &label0);
    ca_.Goto(&block33, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp227, tmp234, tmp233, tmp235);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block34, tmp219, tmp220, tmp221, tmp222, tmp223, tmp224, tmp225, tmp226, tmp227, tmp228, tmp229, tmp230, tmp231, tmp232, tmp233, tmp234, tmp227, tmp234, tmp233);
    }
  }

  if (block34.is_used()) {
    TNode<Context> tmp236;
    TNode<JSReceiver> tmp237;
    TNode<Number> tmp238;
    TNode<JSReceiver> tmp239;
    TNode<Object> tmp240;
    TNode<Object> tmp241;
    TNode<JSArray> tmp242;
    TNode<JSArray> tmp243;
    TNode<JSArray> tmp244;
    TNode<Map> tmp245;
    TNode<BoolT> tmp246;
    TNode<Smi> tmp247;
    TNode<Smi> tmp248;
    TNode<Context> tmp249;
    TNode<Context> tmp250;
    TNode<Smi> tmp251;
    TNode<JSArray> tmp252;
    TNode<Smi> tmp253;
    TNode<Context> tmp254;
    ca_.Bind(&block34, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245, &tmp246, &tmp247, &tmp248, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254);
    ca_.Goto(&block26, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245, tmp246, tmp247);
  }

  if (block33.is_used()) {
    TNode<Context> tmp255;
    TNode<JSReceiver> tmp256;
    TNode<Number> tmp257;
    TNode<JSReceiver> tmp258;
    TNode<Object> tmp259;
    TNode<Object> tmp260;
    TNode<JSArray> tmp261;
    TNode<JSArray> tmp262;
    TNode<JSArray> tmp263;
    TNode<Map> tmp264;
    TNode<BoolT> tmp265;
    TNode<Smi> tmp266;
    TNode<Smi> tmp267;
    TNode<Context> tmp268;
    TNode<Context> tmp269;
    TNode<Smi> tmp270;
    TNode<JSArray> tmp271;
    TNode<Smi> tmp272;
    TNode<Context> tmp273;
    TNode<Object> tmp274;
    ca_.Bind(&block33, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260, &tmp261, &tmp262, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270, &tmp271, &tmp272, &tmp273, &tmp274);
    ca_.Goto(&block27, tmp255, tmp256, tmp257, tmp258, tmp259, tmp260, tmp261, tmp262, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp274);
  }

  if (block27.is_used()) {
    TNode<Context> tmp275;
    TNode<JSReceiver> tmp276;
    TNode<Number> tmp277;
    TNode<JSReceiver> tmp278;
    TNode<Object> tmp279;
    TNode<Object> tmp280;
    TNode<JSArray> tmp281;
    TNode<JSArray> tmp282;
    TNode<JSArray> tmp283;
    TNode<Map> tmp284;
    TNode<BoolT> tmp285;
    TNode<Smi> tmp286;
    TNode<Smi> tmp287;
    TNode<Context> tmp288;
    TNode<Context> tmp289;
    TNode<Smi> tmp290;
    TNode<Object> tmp291;
    ca_.Bind(&block27, &tmp275, &tmp276, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291);
    TNode<Oddball> tmp292;
    USE(tmp292);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp292 = Cast_TheHole_0(state_, TNode<Object>{tmp280}, &label0);
    ca_.Goto(&block37, tmp275, tmp276, tmp277, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp291, tmp280, tmp280, tmp292);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block38, tmp275, tmp276, tmp277, tmp278, tmp279, tmp280, tmp281, tmp282, tmp283, tmp284, tmp285, tmp286, tmp291, tmp280, tmp280);
    }
  }

  if (block26.is_used()) {
    TNode<Context> tmp293;
    TNode<JSReceiver> tmp294;
    TNode<Number> tmp295;
    TNode<JSReceiver> tmp296;
    TNode<Object> tmp297;
    TNode<Object> tmp298;
    TNode<JSArray> tmp299;
    TNode<JSArray> tmp300;
    TNode<JSArray> tmp301;
    TNode<Map> tmp302;
    TNode<BoolT> tmp303;
    TNode<Smi> tmp304;
    ca_.Bind(&block26, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302, &tmp303, &tmp304);
    ca_.Goto(&block14, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302, tmp303, tmp304);
  }

  if (block38.is_used()) {
    TNode<Context> tmp305;
    TNode<JSReceiver> tmp306;
    TNode<Number> tmp307;
    TNode<JSReceiver> tmp308;
    TNode<Object> tmp309;
    TNode<Object> tmp310;
    TNode<JSArray> tmp311;
    TNode<JSArray> tmp312;
    TNode<JSArray> tmp313;
    TNode<Map> tmp314;
    TNode<BoolT> tmp315;
    TNode<Smi> tmp316;
    TNode<Object> tmp317;
    TNode<Object> tmp318;
    TNode<Object> tmp319;
    ca_.Bind(&block38, &tmp305, &tmp306, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316, &tmp317, &tmp318, &tmp319);
    TNode<Oddball> tmp320;
    USE(tmp320);
    tmp320 = Undefined_0(state_);
    TNode<Object> tmp321;
    USE(tmp321);
    tmp321 = CodeStubAssembler(state_).Call(TNode<Context>{tmp305}, TNode<JSReceiver>{tmp308}, TNode<Object>{tmp320}, TNode<Object>{ca_.UncheckedCast<Object>(tmp318)}, TNode<Object>{tmp317}, TNode<Object>{tmp316}, TNode<Object>{tmp313});
    ca_.Goto(&block35, tmp305, tmp306, tmp307, tmp308, tmp309, tmp321, tmp311, tmp312, tmp313, tmp314, tmp315, tmp316, tmp317, tmp318);
  }

  if (block37.is_used()) {
    TNode<Context> tmp322;
    TNode<JSReceiver> tmp323;
    TNode<Number> tmp324;
    TNode<JSReceiver> tmp325;
    TNode<Object> tmp326;
    TNode<Object> tmp327;
    TNode<JSArray> tmp328;
    TNode<JSArray> tmp329;
    TNode<JSArray> tmp330;
    TNode<Map> tmp331;
    TNode<BoolT> tmp332;
    TNode<Smi> tmp333;
    TNode<Object> tmp334;
    TNode<Object> tmp335;
    TNode<Object> tmp336;
    TNode<Oddball> tmp337;
    ca_.Bind(&block37, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326, &tmp327, &tmp328, &tmp329, &tmp330, &tmp331, &tmp332, &tmp333, &tmp334, &tmp335, &tmp336, &tmp337);
    ca_.Goto(&block35, tmp322, tmp323, tmp324, tmp325, tmp326, tmp334, tmp328, tmp329, tmp330, tmp331, tmp332, tmp333, tmp334, tmp335);
  }

  if (block35.is_used()) {
    TNode<Context> tmp338;
    TNode<JSReceiver> tmp339;
    TNode<Number> tmp340;
    TNode<JSReceiver> tmp341;
    TNode<Object> tmp342;
    TNode<Object> tmp343;
    TNode<JSArray> tmp344;
    TNode<JSArray> tmp345;
    TNode<JSArray> tmp346;
    TNode<Map> tmp347;
    TNode<BoolT> tmp348;
    TNode<Smi> tmp349;
    TNode<Object> tmp350;
    TNode<Object> tmp351;
    ca_.Bind(&block35, &tmp338, &tmp339, &tmp340, &tmp341, &tmp342, &tmp343, &tmp344, &tmp345, &tmp346, &tmp347, &tmp348, &tmp349, &tmp350, &tmp351);
    ca_.Goto(&block14, tmp338, tmp339, tmp340, tmp341, tmp342, tmp343, tmp344, tmp345, tmp346, tmp347, tmp348, tmp349);
  }

  if (block14.is_used()) {
    TNode<Context> tmp352;
    TNode<JSReceiver> tmp353;
    TNode<Number> tmp354;
    TNode<JSReceiver> tmp355;
    TNode<Object> tmp356;
    TNode<Object> tmp357;
    TNode<JSArray> tmp358;
    TNode<JSArray> tmp359;
    TNode<JSArray> tmp360;
    TNode<Map> tmp361;
    TNode<BoolT> tmp362;
    TNode<Smi> tmp363;
    ca_.Bind(&block14, &tmp352, &tmp353, &tmp354, &tmp355, &tmp356, &tmp357, &tmp358, &tmp359, &tmp360, &tmp361, &tmp362, &tmp363);
    TNode<Smi> tmp364;
    USE(tmp364);
    tmp364 = FromConstexpr_Smi_constexpr_int31_0(state_, 1);
    TNode<Smi> tmp365;
    USE(tmp365);
    tmp365 = CodeStubAssembler(state_).SmiAdd(TNode<Smi>{tmp363}, TNode<Smi>{tmp364});
    ca_.Goto(&block13, tmp352, tmp353, tmp354, tmp355, tmp356, tmp357, tmp358, tmp359, tmp360, tmp361, tmp362, tmp365);
  }

  if (block12.is_used()) {
    TNode<Context> tmp366;
    TNode<JSReceiver> tmp367;
    TNode<Number> tmp368;
    TNode<JSReceiver> tmp369;
    TNode<Object> tmp370;
    TNode<Object> tmp371;
    TNode<JSArray> tmp372;
    TNode<JSArray> tmp373;
    TNode<JSArray> tmp374;
    TNode<Map> tmp375;
    TNode<BoolT> tmp376;
    TNode<Smi> tmp377;
    ca_.Bind(&block12, &tmp366, &tmp367, &tmp368, &tmp369, &tmp370, &tmp371, &tmp372, &tmp373, &tmp374, &tmp375, &tmp376, &tmp377);
    TNode<Oddball> tmp378;
    USE(tmp378);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp378 = Cast_TheHole_0(state_, TNode<Object>{tmp371}, &label0);
    ca_.Goto(&block42, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp371, tmp371, tmp378);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block43, tmp366, tmp367, tmp368, tmp369, tmp370, tmp371, tmp372, tmp373, tmp374, tmp375, tmp376, tmp371, tmp371);
    }
  }

  if (block43.is_used()) {
    TNode<Context> tmp379;
    TNode<JSReceiver> tmp380;
    TNode<Number> tmp381;
    TNode<JSReceiver> tmp382;
    TNode<Object> tmp383;
    TNode<Object> tmp384;
    TNode<JSArray> tmp385;
    TNode<JSArray> tmp386;
    TNode<JSArray> tmp387;
    TNode<Map> tmp388;
    TNode<BoolT> tmp389;
    TNode<Object> tmp390;
    TNode<Object> tmp391;
    ca_.Bind(&block43, &tmp379, &tmp380, &tmp381, &tmp382, &tmp383, &tmp384, &tmp385, &tmp386, &tmp387, &tmp388, &tmp389, &tmp390, &tmp391);
    ca_.Goto(&block44, tmp379, tmp380, tmp381, tmp382, tmp383, ca_.UncheckedCast<Object>(tmp390));
  }

  if (block42.is_used()) {
    TNode<Context> tmp392;
    TNode<JSReceiver> tmp393;
    TNode<Number> tmp394;
    TNode<JSReceiver> tmp395;
    TNode<Object> tmp396;
    TNode<Object> tmp397;
    TNode<JSArray> tmp398;
    TNode<JSArray> tmp399;
    TNode<JSArray> tmp400;
    TNode<Map> tmp401;
    TNode<BoolT> tmp402;
    TNode<Object> tmp403;
    TNode<Object> tmp404;
    TNode<Oddball> tmp405;
    ca_.Bind(&block42, &tmp392, &tmp393, &tmp394, &tmp395, &tmp396, &tmp397, &tmp398, &tmp399, &tmp400, &tmp401, &tmp402, &tmp403, &tmp404, &tmp405);
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp392}, MessageTemplate::kReduceNoInitial, "Array.prototype.reduce");
  }

  if (block1.is_used()) {
    TNode<Number> tmp406;
    TNode<Object> tmp407;
    ca_.Bind(&block1, &tmp406, &tmp407);
    *label_Bailout_parameter_1 = tmp407;
    *label_Bailout_parameter_0 = tmp406;
    ca_.Goto(label_Bailout);
  }

    TNode<Context> tmp408;
    TNode<JSReceiver> tmp409;
    TNode<Number> tmp410;
    TNode<JSReceiver> tmp411;
    TNode<Object> tmp412;
    TNode<Object> tmp413;
    ca_.Bind(&block44, &tmp408, &tmp409, &tmp410, &tmp411, &tmp412, &tmp413);
  return TNode<Object>{tmp413};
}

TF_BUILTIN(ArrayReduce, CodeStubAssembler) {
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
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, NativeContext> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, Object, NativeContext, JSReceiver> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, JSReceiver> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, JSReceiver> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, JSReceiver, Object> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, JSReceiver, Object, JSReceiver, Number, JSReceiver, Object, NativeContext, Number, Object> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object, JSReceiver, Number, JSReceiver, Object, JSReceiver, Number, JSReceiver, Object, NativeContext, Object> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block2(&ca_, compiler::CodeAssemblerLabel::kDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<Object> tmp5;
    USE(tmp5);
    tmp5 = RequireObjectCoercible_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp4}, "Array.prototype.reduce");
    TNode<JSReceiver> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).ToObject_Inline(TNode<Context>{tmp3}, TNode<Object>{tmp4});
    TNode<Number> tmp7;
    USE(tmp7);
    tmp7 = GetLengthProperty_0(state_, TNode<Context>{tmp3}, TNode<Object>{tmp6});
    TNode<IntPtrT> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp9;
    USE(tmp9);
    tmp9 = CodeStubAssembler(state_).WordEqual(TNode<IntPtrT>{tmp2}, TNode<IntPtrT>{tmp8});
    ca_.Branch(tmp9, &block3, &block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp6, tmp7);
  }

  if (block3.is_used()) {
    TNode<RawPtrT> tmp10;
    TNode<RawPtrT> tmp11;
    TNode<IntPtrT> tmp12;
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<JSReceiver> tmp15;
    TNode<Number> tmp16;
    ca_.Bind(&block3, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    ca_.Goto(&block2, tmp10, tmp11, tmp12, tmp13, tmp14);
  }

  if (block4.is_used()) {
    TNode<RawPtrT> tmp17;
    TNode<RawPtrT> tmp18;
    TNode<IntPtrT> tmp19;
    TNode<NativeContext> tmp20;
    TNode<Object> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<Number> tmp23;
    ca_.Bind(&block4, &tmp17, &tmp18, &tmp19, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp17}, TNode<RawPtrT>{tmp18}, TNode<IntPtrT>{tmp19}}, TNode<IntPtrT>{tmp24});
    TNode<JSReceiver> tmp26;
    USE(tmp26);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp26 = Cast_Callable_1(state_, TNode<Context>{tmp20}, TNode<Object>{tmp25}, &label0);
    ca_.Goto(&block5, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp25, tmp20, tmp26);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp17, tmp18, tmp19, tmp20, tmp21, tmp22, tmp23, tmp25, tmp20);
    }
  }

  if (block6.is_used()) {
    TNode<RawPtrT> tmp27;
    TNode<RawPtrT> tmp28;
    TNode<IntPtrT> tmp29;
    TNode<NativeContext> tmp30;
    TNode<Object> tmp31;
    TNode<JSReceiver> tmp32;
    TNode<Number> tmp33;
    TNode<Object> tmp34;
    TNode<NativeContext> tmp35;
    ca_.Bind(&block6, &tmp27, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35);
    ca_.Goto(&block2, tmp27, tmp28, tmp29, tmp30, tmp31);
  }

  if (block5.is_used()) {
    TNode<RawPtrT> tmp36;
    TNode<RawPtrT> tmp37;
    TNode<IntPtrT> tmp38;
    TNode<NativeContext> tmp39;
    TNode<Object> tmp40;
    TNode<JSReceiver> tmp41;
    TNode<Number> tmp42;
    TNode<Object> tmp43;
    TNode<NativeContext> tmp44;
    TNode<JSReceiver> tmp45;
    ca_.Bind(&block5, &tmp36, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45);
    TNode<IntPtrT> tmp46;
    USE(tmp46);
    tmp46 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<BoolT> tmp47;
    USE(tmp47);
    tmp47 = CodeStubAssembler(state_).IntPtrGreaterThan(TNode<IntPtrT>{tmp38}, TNode<IntPtrT>{tmp46});
    ca_.Branch(tmp47, &block7, &block8, tmp36, tmp37, tmp38, tmp39, tmp40, tmp41, tmp42, tmp45);
  }

  if (block7.is_used()) {
    TNode<RawPtrT> tmp48;
    TNode<RawPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    TNode<NativeContext> tmp51;
    TNode<Object> tmp52;
    TNode<JSReceiver> tmp53;
    TNode<Number> tmp54;
    TNode<JSReceiver> tmp55;
    ca_.Bind(&block7, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54, &tmp55);
    TNode<IntPtrT> tmp56;
    USE(tmp56);
    tmp56 = FromConstexpr_intptr_constexpr_int31_0(state_, 1);
    TNode<Object> tmp57;
    USE(tmp57);
    tmp57 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp48}, TNode<RawPtrT>{tmp49}, TNode<IntPtrT>{tmp50}}, TNode<IntPtrT>{tmp56});
    ca_.Goto(&block9, tmp48, tmp49, tmp50, tmp51, tmp52, tmp53, tmp54, tmp55, tmp57);
  }

  if (block8.is_used()) {
    TNode<RawPtrT> tmp58;
    TNode<RawPtrT> tmp59;
    TNode<IntPtrT> tmp60;
    TNode<NativeContext> tmp61;
    TNode<Object> tmp62;
    TNode<JSReceiver> tmp63;
    TNode<Number> tmp64;
    TNode<JSReceiver> tmp65;
    ca_.Bind(&block8, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65);
    TNode<Oddball> tmp66;
    USE(tmp66);
    tmp66 = TheHole_0(state_);
    ca_.Goto(&block9, tmp58, tmp59, tmp60, tmp61, tmp62, tmp63, tmp64, tmp65, tmp66);
  }

  if (block9.is_used()) {
    TNode<RawPtrT> tmp67;
    TNode<RawPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<NativeContext> tmp70;
    TNode<Object> tmp71;
    TNode<JSReceiver> tmp72;
    TNode<Number> tmp73;
    TNode<JSReceiver> tmp74;
    TNode<Object> tmp75;
    ca_.Bind(&block9, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74, &tmp75);
    TNode<Object> tmp76;
    USE(tmp76);
    compiler::TypedCodeAssemblerVariable<Number> result_0_0(&ca_);
    compiler::TypedCodeAssemblerVariable<Object> result_0_1(&ca_);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp76 = FastArrayReduce_0(state_, TNode<Context>{tmp70}, TNode<JSReceiver>{tmp72}, TNode<Number>{tmp73}, TNode<JSReceiver>{tmp74}, TNode<Object>{tmp75}, &label0, &result_0_0, &result_0_1);
    ca_.Goto(&block13, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp72, tmp73, tmp74, tmp75, tmp70, tmp76);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block14, tmp67, tmp68, tmp69, tmp70, tmp71, tmp72, tmp73, tmp74, tmp75, tmp72, tmp73, tmp74, tmp75, tmp70, result_0_0.value(), result_0_1.value());
    }
  }

  if (block14.is_used()) {
    TNode<RawPtrT> tmp77;
    TNode<RawPtrT> tmp78;
    TNode<IntPtrT> tmp79;
    TNode<NativeContext> tmp80;
    TNode<Object> tmp81;
    TNode<JSReceiver> tmp82;
    TNode<Number> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<Object> tmp85;
    TNode<JSReceiver> tmp86;
    TNode<Number> tmp87;
    TNode<JSReceiver> tmp88;
    TNode<Object> tmp89;
    TNode<NativeContext> tmp90;
    TNode<Number> tmp91;
    TNode<Object> tmp92;
    ca_.Bind(&block14, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90, &tmp91, &tmp92);
    TNode<Object> tmp93;
    tmp93 = CodeStubAssembler(state_).CallBuiltin(Builtins::kArrayReduceLoopContinuation, tmp80, tmp82, tmp84, tmp92, tmp82, tmp91, tmp83);
    USE(tmp93);
    arguments.PopAndReturn(tmp93);
  }

  if (block13.is_used()) {
    TNode<RawPtrT> tmp94;
    TNode<RawPtrT> tmp95;
    TNode<IntPtrT> tmp96;
    TNode<NativeContext> tmp97;
    TNode<Object> tmp98;
    TNode<JSReceiver> tmp99;
    TNode<Number> tmp100;
    TNode<JSReceiver> tmp101;
    TNode<Object> tmp102;
    TNode<JSReceiver> tmp103;
    TNode<Number> tmp104;
    TNode<JSReceiver> tmp105;
    TNode<Object> tmp106;
    TNode<NativeContext> tmp107;
    TNode<Object> tmp108;
    ca_.Bind(&block13, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106, &tmp107, &tmp108);
    arguments.PopAndReturn(tmp108);
  }

  if (block2.is_used()) {
    TNode<RawPtrT> tmp109;
    TNode<RawPtrT> tmp110;
    TNode<IntPtrT> tmp111;
    TNode<NativeContext> tmp112;
    TNode<Object> tmp113;
    ca_.Bind(&block2, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113);
    TNode<IntPtrT> tmp114;
    USE(tmp114);
    tmp114 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp115;
    USE(tmp115);
    tmp115 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp109}, TNode<RawPtrT>{tmp110}, TNode<IntPtrT>{tmp111}}, TNode<IntPtrT>{tmp114});
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp112}, MessageTemplate::kCalledNonCallable, TNode<Object>{tmp115});
  }
}

}  // namespace internal
}  // namespace v8

