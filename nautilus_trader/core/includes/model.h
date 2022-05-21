/* Generated with cbindgen:0.20.0 */

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdint.h>
#include <Python.h>

#define FIXED_PRECISION 9

#define FIXED_SCALAR 1000000000.0

typedef enum BookLevel {
    L1_TBBO = 1,
    L2_MBP = 2,
    L3_MBO = 3,
} BookLevel;

typedef enum CurrencyType {
    Crypto,
    Fiat,
} CurrencyType;

typedef enum OrderSide {
    Buy = 1,
    Sell = 2,
} OrderSide;

typedef struct BTreeMap_BookPrice__Level BTreeMap_BookPrice__Level;

typedef struct HashMap_u64__BookPrice HashMap_u64__BookPrice;

typedef struct String String;

typedef struct Symbol_t {
    struct String *value;
} Symbol_t;

typedef struct Venue_t {
    struct String *value;
} Venue_t;

typedef struct InstrumentId_t {
    struct Symbol_t symbol;
    struct Venue_t venue;
} InstrumentId_t;

typedef struct Price_t {
    int64_t raw;
    uint8_t precision;
} Price_t;

typedef struct Quantity_t {
    uint64_t raw;
    uint8_t precision;
} Quantity_t;

/**
 * Represents a single quote tick in a financial market.
 */
typedef struct QuoteTick_t {
    struct InstrumentId_t instrument_id;
    struct Price_t bid;
    struct Price_t ask;
    struct Quantity_t bid_size;
    struct Quantity_t ask_size;
    Timestamp ts_event;
    Timestamp ts_init;
} QuoteTick_t;

typedef struct TradeId_t {
    struct String *value;
} TradeId_t;

/**
 * Represents a single trade tick in a financial market.
 */
typedef struct TradeTick_t {
    struct InstrumentId_t instrument_id;
    struct Price_t price;
    struct Quantity_t size;
    enum OrderSide aggressor_side;
    struct TradeId_t trade_id;
    Timestamp ts_event;
    Timestamp ts_init;
} TradeTick_t;

typedef struct AccountId_t {
    struct String *value;
} AccountId_t;

typedef struct ClientId_t {
    struct String *value;
} ClientId_t;

typedef struct ClientOrderId_t {
    struct String *value;
} ClientOrderId_t;

typedef struct ComponentId_t {
    struct String *value;
} ComponentId_t;

typedef struct OrderListId_t {
    struct String *value;
} OrderListId_t;

typedef struct PositionId_t {
    struct String *value;
} PositionId_t;

typedef struct StrategyId_t {
    struct String *value;
} StrategyId_t;

typedef struct TraderId_t {
    struct String *value;
} TraderId_t;

typedef struct VenueOrderId_t {
    struct String *value;
} VenueOrderId_t;

typedef struct Ladder {
    enum OrderSide side;
    struct BTreeMap_BookPrice__Level *levels;
    struct HashMap_u64__BookPrice *cache;
} Ladder;

typedef struct OrderBook {
    struct Ladder bids;
    struct Ladder asks;
    struct InstrumentId_t instrument_id;
    enum BookLevel book_level;
    enum OrderSide last_side;
    int64_t ts_last;
} OrderBook;

typedef struct Currency_t {
    struct String *code;
    uint8_t precision;
    uint16_t iso4217;
    struct String *name;
    enum CurrencyType currency_type;
} Currency_t;

typedef struct Money_t {
    int64_t raw;
    struct Currency_t currency;
} Money_t;

void quote_tick_free(struct QuoteTick_t tick);

struct QuoteTick_t quote_tick_new(struct InstrumentId_t instrument_id,
                                  struct Price_t bid,
                                  struct Price_t ask,
                                  struct Quantity_t bid_size,
                                  struct Quantity_t ask_size,
                                  int64_t ts_event,
                                  int64_t ts_init);

struct QuoteTick_t quote_tick_from_raw(struct InstrumentId_t instrument_id,
                                       int64_t bid,
                                       int64_t ask,
                                       uint8_t price_prec,
                                       uint64_t bid_size,
                                       uint64_t ask_size,
                                       uint8_t size_prec,
                                       int64_t ts_event,
                                       int64_t ts_init);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *quote_tick_to_pystr(const struct QuoteTick_t *tick);

void trade_tick_free(struct TradeTick_t tick);

struct TradeTick_t trade_tick_from_raw(struct InstrumentId_t instrument_id,
                                       int64_t price,
                                       uint8_t price_prec,
                                       uint64_t size,
                                       uint8_t size_prec,
                                       enum OrderSide aggressor_side,
                                       struct TradeId_t trade_id,
                                       int64_t ts_event,
                                       int64_t ts_init);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *trade_tick_to_pystr(const struct TradeTick_t *tick);

void account_id_free(struct AccountId_t account_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct AccountId_t account_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *account_id_to_pystr(const struct AccountId_t *account_id);

uint8_t account_id_eq(const struct AccountId_t *lhs, const struct AccountId_t *rhs);

uint64_t account_id_hash(const struct AccountId_t *account_id);

void client_id_free(struct ClientId_t client_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct ClientId_t client_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *client_id_to_pystr(const struct ClientId_t *client_id);

uint8_t client_id_eq(const struct ClientId_t *lhs, const struct ClientId_t *rhs);

uint64_t client_id_hash(const struct ClientId_t *client_id);

void client_order_id_free(struct ClientOrderId_t client_order_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct ClientOrderId_t client_order_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *client_order_id_to_pystr(const struct ClientOrderId_t *client_order_id);

uint8_t client_order_id_eq(const struct ClientOrderId_t *lhs, const struct ClientOrderId_t *rhs);

uint64_t client_order_id_hash(const struct ClientOrderId_t *client_order_id);

void component_id_free(struct ComponentId_t component_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct ComponentId_t component_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *component_to_pystr(const struct ComponentId_t *component_id);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *component_id_to_pystr(const struct ComponentId_t *component_id);

uint8_t component_id_eq(const struct ComponentId_t *lhs, const struct ComponentId_t *rhs);

uint64_t component_id_hash(const struct ComponentId_t *component_id);

void instrument_id_free(struct InstrumentId_t instrument_id);

/**
 * Returns a Nautilus identifier from valid Python object pointers.
 *
 * # Safety
 *
 * - `symbol_ptr` and `venue_ptr` must be borrowed from a valid Python UTF-8 `str`(s).
 */
struct InstrumentId_t instrument_id_from_pystrs(PyObject *symbol_ptr, PyObject *venue_ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *instrument_id_to_pystr(const struct InstrumentId_t *instrument_id);

uint8_t instrument_id_eq(const struct InstrumentId_t *lhs, const struct InstrumentId_t *rhs);

uint64_t instrument_id_hash(const struct InstrumentId_t *instrument_id);

void order_list_id_free(struct OrderListId_t order_list_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct OrderListId_t order_list_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *order_list_id_to_pystr(const struct OrderListId_t *order_list_id);

uint8_t order_list_id_eq(const struct OrderListId_t *lhs, const struct OrderListId_t *rhs);

uint64_t order_list_id_hash(const struct OrderListId_t *order_list_id);

void position_id_free(struct PositionId_t position_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct PositionId_t position_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *position_id_to_pystr(const struct PositionId_t *position_id);

uint8_t position_id_eq(const struct PositionId_t *lhs, const struct PositionId_t *rhs);

uint64_t position_id_hash(const struct PositionId_t *position_id);

void strategy_id_free(struct StrategyId_t strategy_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct StrategyId_t strategy_id_from_pystr(PyObject *ptr);

void symbol_free(struct Symbol_t symbol);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct Symbol_t symbol_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *symbol_to_pystr(const struct Symbol_t *symbol);

uint8_t symbol_eq(const struct Symbol_t *lhs, const struct Symbol_t *rhs);

uint64_t symbol_hash(const struct Symbol_t *symbol);

void trade_id_free(struct TradeId_t trade_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct TradeId_t trade_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *trade_id_to_pystr(const struct TradeId_t *trade_id);

uint8_t trade_id_eq(const struct TradeId_t *lhs, const struct TradeId_t *rhs);

uint64_t trade_id_hash(const struct TradeId_t *trade_id);

void trader_id_free(struct TraderId_t trader_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct TraderId_t trader_id_from_pystr(PyObject *ptr);

void venue_free(struct Venue_t venue);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct Venue_t venue_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *venue_to_pystr(const struct Venue_t *venue);

uint8_t venue_eq(const struct Venue_t *lhs, const struct Venue_t *rhs);

uint64_t venue_hash(const struct Venue_t *venue);

void venue_order_id_free(struct VenueOrderId_t venue_order_id);

/**
 * Returns a Nautilus identifier from a valid Python object pointer.
 *
 * # Safety
 *
 * - `ptr` must be borrowed from a valid Python UTF-8 `str`.
 */
struct VenueOrderId_t venue_order_id_from_pystr(PyObject *ptr);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *venue_order_id_to_pystr(const struct VenueOrderId_t *venue_order_id);

uint8_t venue_order_id_eq(const struct VenueOrderId_t *lhs, const struct VenueOrderId_t *rhs);

uint64_t venue_order_id_hash(const struct VenueOrderId_t *venue_order_id);

struct OrderBook order_book_new(struct InstrumentId_t instrument_id, enum BookLevel book_level);

/**
 * Returns a `Currency` from valid Python object pointers and primitives.
 *
 * # Safety
 *
 * - `code_ptr` and `name_ptr` must be borrowed from a valid Python UTF-8 `str`(s).
 */
struct Currency_t currency_from_py(PyObject *code_ptr,
                                   uint8_t precision,
                                   uint16_t iso4217,
                                   PyObject *name_ptr,
                                   enum CurrencyType currency_type);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *currency_code_to_pystr(const struct Currency_t *currency);

/**
 * Returns a pointer to a valid Python UTF-8 string.
 *
 * # Safety
 *
 * - Assumes that since the data is originating from Rust, the GIL does not need
 * to be acquired.
 * - Assumes you are immediately returning this pointer to Python.
 */
PyObject *currency_name_to_pystr(const struct Currency_t *currency);

void currency_free(struct Currency_t currency);

struct Money_t money_new(double amount, struct Currency_t currency);

struct Money_t money_from_raw(int64_t raw, struct Currency_t currency);

void money_free(struct Money_t money);

double money_as_f64(const struct Money_t *money);

void money_add_assign(struct Money_t a, struct Money_t b);

void money_sub_assign(struct Money_t a, struct Money_t b);

struct Price_t price_new(double value, uint8_t precision);

struct Price_t price_from_raw(int64_t raw, uint8_t precision);

void price_free(struct Price_t price);

double price_as_f64(const struct Price_t *price);

void price_add_assign(struct Price_t a, struct Price_t b);

void price_sub_assign(struct Price_t a, struct Price_t b);

struct Quantity_t quantity_new(double value, uint8_t precision);

struct Quantity_t quantity_from_raw(uint64_t raw, uint8_t precision);

void quantity_free(struct Quantity_t qty);

double quantity_as_f64(const struct Quantity_t *qty);

void quantity_add_assign(struct Quantity_t a, struct Quantity_t b);

void quantity_add_assign_u64(struct Quantity_t a, uint64_t b);

void quantity_sub_assign(struct Quantity_t a, struct Quantity_t b);

void quantity_sub_assign_u64(struct Quantity_t a, uint64_t b);
