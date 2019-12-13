#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_INTL_OBJECTS_TQ_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_INTL_OBJECTS_TQ_H_

#include "src/compiler/code-assembler.h"
#include "src/codegen/code-stub-assembler.h"
#include "src/utils/utils.h"
#include "torque-generated/field-offsets-tq.h"
#include "torque-generated/csa-types-tq.h"

namespace v8 {
namespace internal {

TNode<String> LoadJSDateTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSDateTimeFormatIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadJSDateTimeFormatIcuSimpleDateFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatIcuSimpleDateFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadJSDateTimeFormatIcuDateIntervalFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatIcuDateIntervalFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);
TNode<HeapObject> LoadJSDateTimeFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSDateTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);
void StoreJSDateTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadJSDisplayNamesInternal_0(compiler::CodeAssemblerState* state_, TNode<JSDisplayNames> p_o);
void StoreJSDisplayNamesInternal_0(compiler::CodeAssemblerState* state_, TNode<JSDisplayNames> p_o, TNode<Foreign> p_v);
TNode<Smi> LoadJSDisplayNamesFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDisplayNames> p_o);
void StoreJSDisplayNamesFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDisplayNames> p_o, TNode<Smi> p_v);
TNode<String> LoadJSListFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o);
void StoreJSListFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSListFormatIcuFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o);
void StoreJSListFormatIcuFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o, TNode<Foreign> p_v);
TNode<Smi> LoadJSListFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o);
void StoreJSListFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSListFormat> p_o, TNode<Smi> p_v);
TNode<String> LoadJSNumberFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o);
void StoreJSNumberFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o, TNode<String> p_v);
TNode<String> LoadJSNumberFormatNumberingSystem_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o);
void StoreJSNumberFormatNumberingSystem_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSNumberFormatIcuNumberFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o);
void StoreJSNumberFormatIcuNumberFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o, TNode<Foreign> p_v);
TNode<HeapObject> LoadJSNumberFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o);
void StoreJSNumberFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSNumberFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o);
void StoreJSNumberFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSNumberFormat> p_o, TNode<Smi> p_v);
TNode<String> LoadJSPluralRulesLocale_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o);
void StoreJSPluralRulesLocale_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o, TNode<String> p_v);
TNode<Smi> LoadJSPluralRulesFlags_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o);
void StoreJSPluralRulesFlags_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadJSPluralRulesIcuPluralRules_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o);
void StoreJSPluralRulesIcuPluralRules_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadJSPluralRulesIcuNumberFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o);
void StoreJSPluralRulesIcuNumberFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSPluralRules> p_o, TNode<Foreign> p_v);
TNode<String> LoadJSRelativeTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o);
void StoreJSRelativeTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o, TNode<String> p_v);
TNode<String> LoadJSRelativeTimeFormatNumberingSystem_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o);
void StoreJSRelativeTimeFormatNumberingSystem_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSRelativeTimeFormatIcuFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o);
void StoreJSRelativeTimeFormatIcuFormatter_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o, TNode<Foreign> p_v);
TNode<Smi> LoadJSRelativeTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o);
void StoreJSRelativeTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSRelativeTimeFormat> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadJSLocaleIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSLocale> p_o);
void StoreJSLocaleIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSLocale> p_o, TNode<Foreign> p_v);
TNode<String> LoadJSSegmenterLocale_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o);
void StoreJSSegmenterLocale_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSSegmenterIcuBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o);
void StoreJSSegmenterIcuBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o, TNode<Foreign> p_v);
TNode<Smi> LoadJSSegmenterFlags_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o);
void StoreJSSegmenterFlags_0(compiler::CodeAssemblerState* state_, TNode<JSSegmenter> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadJSSegmentIteratorIcuBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o);
void StoreJSSegmentIteratorIcuBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadJSSegmentIteratorUnicodeString_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o);
void StoreJSSegmentIteratorUnicodeString_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o, TNode<Foreign> p_v);
TNode<Smi> LoadJSSegmentIteratorFlags_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o);
void StoreJSSegmentIteratorFlags_0(compiler::CodeAssemblerState* state_, TNode<JSSegmentIterator> p_o, TNode<Smi> p_v);
TNode<String> LoadJSV8BreakIteratorLocale_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorLocale_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<String> p_v);
TNode<Foreign> LoadJSV8BreakIteratorBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBreakIterator_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<Foreign> p_v);
TNode<Foreign> LoadJSV8BreakIteratorUnicodeString_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorUnicodeString_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<Foreign> p_v);
TNode<HeapObject> LoadJSV8BreakIteratorBoundAdoptText_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBoundAdoptText_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSV8BreakIteratorBoundFirst_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBoundFirst_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSV8BreakIteratorBoundNext_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBoundNext_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSV8BreakIteratorBoundCurrent_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBoundCurrent_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<HeapObject> p_v);
TNode<HeapObject> LoadJSV8BreakIteratorBoundBreakType_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBoundBreakType_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<HeapObject> p_v);
TNode<Smi> LoadJSV8BreakIteratorBreakIteratorType_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o);
void StoreJSV8BreakIteratorBreakIteratorType_0(compiler::CodeAssemblerState* state_, TNode<JSV8BreakIterator> p_o, TNode<Smi> p_v);
TNode<Foreign> LoadJSCollatorIcuCollator_0(compiler::CodeAssemblerState* state_, TNode<JSCollator> p_o);
void StoreJSCollatorIcuCollator_0(compiler::CodeAssemblerState* state_, TNode<JSCollator> p_o, TNode<Foreign> p_v);
TNode<HeapObject> LoadJSCollatorBoundCompare_0(compiler::CodeAssemblerState* state_, TNode<JSCollator> p_o);
void StoreJSCollatorBoundCompare_0(compiler::CodeAssemblerState* state_, TNode<JSCollator> p_o, TNode<HeapObject> p_v);
}  // namespace internal
}  // namespace v8

#endif  // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_INTL_OBJECTS_TQ_H_
