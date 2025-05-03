#ifndef FEGN_STREAM_HPP
#define FEGN_STREAM_HPP

#include <string>
#include <memory>
#include <functional>
#include <vector>

namespace Fegn {
    // Stream öğesi
    class StreamItem {
    public:
        std::string data;
        std::chrono::steady_clock::time_point timestamp;
        
        StreamItem(const std::string& data)
            : data(data), timestamp(std::chrono::steady_clock::now()) {}
    };
    
    // Stream yöneticisi
    class StreamManager {
    private:
        std::vector<std::shared_ptr<StreamItem>> items;
        std::function<void(const std::string&)> onItem;
        std::function<void(const std::string&)> onError;
        
    public:
        // Öğe ekle
        void push(const std::string& data) {
            auto item = std::make_shared<StreamItem>(data);
            items.push_back(item);
            if (onItem) {
                onItem(data);
            }
        }
        
        // Olay yöneticileri
        void onItem(const std::function<void(const std::string&)>& callback) {
            onItem = callback;
        }
        
        void onError(const std::function<void(const std::string&)>& callback) {
            onError = callback;
        }
        
        // Stream akışı
        void pipe(const std::function<void(const std::string&)>& callback) {
            for (auto& item : items) {
                callback(item->data);
            }
        }
    };
    
    // Stream istemcisi
    class StreamClient {
    private:
        std::shared_ptr<StreamManager> manager;
        
    public:
        StreamClient(std::shared_ptr<StreamManager> manager)
            : manager(manager) {}
        
        void push(const std::string& data) {
            manager->push(data);
        }
        
        void onItem(const std::function<void(const std::string&)>& callback) {
            manager->onItem(callback);
        }
        
        void onError(const std::function<void(const std::string&)>& callback) {
            manager->onError(callback);
        }
        
        void pipe(const std::function<void(const std::string&)>& callback) {
            manager->pipe(callback);
        }
    };
}

#endif // FEGN_STREAM_HPP
