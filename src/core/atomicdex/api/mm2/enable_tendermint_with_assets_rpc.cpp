#include <nlohmann/json.hpp>

#include "enable_tendermint_with_assets_rpc.hpp"

namespace atomic_dex::mm2
{
    void to_json(nlohmann::json& j, const enable_tendermint_with_assets_request_rpc& in)
    {
        j["ticker"] = in.ticker;
        j["rpc_urls"] = in.rpc_urls;
        j["tx_history"] = in.tx_history;
        j["tokens_params"] = in.tokens_params;
        if (in.required_confirmations.has_value())
            j["required_confirmations"] = in.required_confirmations.value();
        if (in.requires_notarization.has_value())
            j["requires_notarization"] = in.requires_notarization.value();
    }

    void to_json(nlohmann::json& j, const enable_tendermint_with_assets_request_rpc::tendermint_token_request_t& in)
    {
        j["ticker"] = in.ticker;
        if (in.required_confirmations)
            j["required_confirmations"] = in.required_confirmations.value();
    }

    void from_json(const nlohmann::json& json, enable_tendermint_with_assets_result_rpc& out)
    {
        out.address = json["address"];
        out.current_block = json["current_block"];
        out.tendermint_addresses_infos = json["tendermint_addresses_infos"].get<typeof(out.tendermint_addresses_infos)>();
        out.tendermint_token_addresses_infos = json["tendermint_token_addresses_infos"].get<typeof(out.tendermint_token_addresses_infos)>();
    }
    
    void from_json(const nlohmann::json& json, enable_tendermint_with_assets_result_rpc::tendermint_address_infos_t& out)
    {
        out.balances = json["balances"];
    }
    
    void from_json(const nlohmann::json& json, enable_tendermint_with_assets_result_rpc::tendermint_token_address_infos_t& out)
    {
        out.balances = json["balances"].get<typeof(out.balances)>();
    }
}